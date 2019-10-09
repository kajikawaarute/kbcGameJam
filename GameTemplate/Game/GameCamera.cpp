#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
}

GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	//カメラを設定。
	/*MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, -200.0f });
	MainCamera().Update();*/

	m_toCameraPos.Set(0.0f, 250.0f, -400.0f);
	m_pl = FindGO<Player>("pl");
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);


	return true;
}

void GameCamera::Update()
{
	//注視点
	m_Target = m_pl->GetPos();
	m_Target.y += 50.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();

	//Y軸回りの回転
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(m_toCameraPos);

	//X軸回りの回転
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(m_toCameraPos);

	CVector3 toCameraDir = m_toCameraPos;
	toCameraDir.Normalize();

	if (toCameraDir.y < -0.5f) {
		m_toCameraPos = toCameraPosOld;
	}
	else if (toCameraDir.y > 0.8f) {
		m_toCameraPos = toCameraPosOld;
	}

	//視点
	m_position = m_Target + m_toCameraPos;

	MainCamera().SetTarget(m_Target);
	MainCamera().SetPosition(m_position);
	MainCamera().Update();
}
