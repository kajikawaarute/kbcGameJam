#include "stdafx.h"
#include "Player.h"
#include "GabageBotol.h"
#include "GarbagePaper.h"

Player::Player()
{
}

Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

bool Player::Start()
{
	//アニメーションクリップのロード
	m_animationClip[enAnimationClip_Player_Idle].Load(L"animData/KBCjamPlayer/Player_Idle.tka");
	m_animationClip[enAnimationClip_Player_Run].Load(L"animData/KBCjamPlayer/Player_Run.tka");
	m_animationClip[enAnimationClip_Player_Gomihiroi].Load(L"animData/KBCjamPlayer/Player_Gomihiroi.tka");
	//ループフラグの設定
	m_animationClip[enAnimationClip_Player_Idle].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Player_Run].SetLoopFlag(true);
	m_animationClip[enAnimationClip_Player_Gomihiroi].SetLoopFlag(false);
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_scale = { 1.5f, 1.5f, 1.5f };
	m_skinModelRender->Init(L"modelData/KBCjam Player.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_charaCon.Init(50.0f, 90.0f, m_position);

	return true;
}

void Player::AnimationController()
{
	
	
	if (ChangeHIroiMo == 0) {
		if (Pad(0).GetLStickXF() || Pad(0).GetLStickYF()) {
			m_skinModelRender->PlayAnimation(enAnimationClip_Player_Run, 0.0f);
		}
		else {
			//m_skinModelRender->PlayAnimation(enAnimationClip_Player_Idle, 0.0f);
		}
		if (Pad(0).IsTrigger(enButtonA))
		{
			m_skinModelRender->PlayAnimation(enAnimationClip_Player_Gomihiroi, 0.0f);
			//ChangeHIroiMo = 1;
		}
		
	}
	/*if (ChangeHIroiMo == 1)
	{
		m_skinModelRender->PlayAnimation(enAnimationClip_Player_Gomihiroi, 0.0f);
		
	}
	ChangeHIroiMo = 0;*/
}

void Player::Move()
{
	float LStick_x = Pad(0).GetLStickXF() * 800.0f;
	float LStick_y = Pad(0).GetLStickYF() * 800.0f;

	//カメラの前方向と右方向を取得
	CVector3 cameraFoward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();

	//XZ方向での前方向と右方向をに変換する。
	cameraFoward.y = 0;
	cameraFoward.Normalize();
	cameraRight.y = 0;
	cameraRight.Normalize();

	m_moveSpeed.x = 0;
	m_moveSpeed.y -= 90.0f;
	m_moveSpeed.z = 0;

	m_moveSpeed += cameraFoward * LStick_y;
	m_moveSpeed += cameraRight * LStick_x;

	if (Pad(0).IsTrigger(enButtonX))
	{
		m_moveSpeed.y += 600.0f;
	}

	m_position = m_charaCon.Execute(m_moveSpeed, GameTime().GetFrameDeltaTime());
}

void Player::Turn()
{
	if (fabsf(m_moveSpeed.x) < 0.001f && fabsf(m_moveSpeed.z) < 0.001f) {
		return;
	}
	float angle = atan2(m_moveSpeed.x, m_moveSpeed.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}


void Player::Update()
{
	Move();
	Turn();
	AnimationController();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}


