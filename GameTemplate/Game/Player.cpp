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
	//�A�j���[�V�����N���b�v�̃��[�h
	m_animationClip[enAnimationClip_Player_Idle].Load(L"animData/KBCjamPlayer/Player_Idle.tka");
	m_animationClip[enAnimationClip_Player_Run].Load(L"animData/KBCjamPlayer/Player_Run.tka");
	//���[�v�t���O�̐ݒ�
	m_animationClip[enAnimationClip_Player_Idle].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Player_Run].SetLoopFlag(true);
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/KBCjam Player.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_charaCon.Init(50.0f, 90.0f, m_position);

	return true;
}

void Player::AnimationController()
{
	//m_skinModelRender->PlayAnimation(enAnimationClip_Player_Idle, 0.0f);
	if (Pad(0).GetLStickXF() || Pad(0).GetLStickYF()) {
		m_skinModelRender->PlayAnimation(enAnimationClip_Player_Run, 0.0f);
	}
}

void Player::Move()
{
	float LStick_x = Pad(0).GetLStickXF() * 300.0f;
	float LStick_y = Pad(0).GetLStickYF() * 300.0f;

	//�J�����̑O�����ƉE�������擾
	CVector3 cameraFoward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();

	//XZ�����ł̑O�����ƉE�������ɕϊ�����B
	cameraFoward.y = 0;
	cameraFoward.Normalize();
	cameraRight.y = 0;
	cameraRight.Normalize();

	m_moveSpeed.x = 0;
	m_moveSpeed.y = 0;
	m_moveSpeed.z = 0;

	m_moveSpeed += cameraFoward * LStick_y;
	m_moveSpeed += cameraRight * LStick_x;

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
}

