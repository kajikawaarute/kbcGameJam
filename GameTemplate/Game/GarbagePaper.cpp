#include "stdafx.h"
#include "GarbagePaper.h"
//#include "GarbageBase.h"
#include "Player.h"
GarbagePaper::GarbagePaper()
{

}
GarbagePaper::~GarbagePaper()
{
	DeleteGO(m_skinModelRender);
}

bool GarbagePaper::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Paper.cmo");

	m_skinModelRender->SetScale(m_scale);
	return true;
}

void GarbagePaper::NearPlayer()
{
	if (m_player == nullptr)
	{
		m_player = FindGO<Player>("pl");
	}
	CVector3 PlGarbage = m_player->m_position - m_position;

	if (Pad(0).IsTrigger(enButtonA) && PlGarbage.Length() < 500.0f)
	{
		DeleteGO(this);
	}
}
void GarbagePaper::Update()
{
	NearPlayer();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}
