#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

bool Player::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_charaCon.Init(50.0f, 90.0f, m_position);

	return true;
}

void Player::Move()
{
	float LStick_x = Pad(0).GetLStickXF() * 300.0f;
	float LStick_y = Pad(0).GetLStickYF() * 300.0f;

	//カメラの前方向と右方向を取得
	CVector3 cameraFoward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();

	//XZ方向での前方向と右方向をに変換する。
	cameraFoward.y = 0;
	cameraFoward.Normalize();
	cameraRight.y = 0;
	cameraRight.Normalize();

	m_moveSpeed.x = 0;
	m_moveSpeed.y = 0;
	m_moveSpeed.z = 0;

	m_moveSpeed += cameraFoward * LStick_y;
	m_moveSpeed += cameraRight * LStick_x;

	m_position = m_charaCon.Execute(m_moveSpeed);
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
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}


