#include "stdafx.h"
#include "GabageBotol.h"
//#include "GarbageBase.h"
#include "Player.h"
#include "GetGarbageCount.h"
GabageBotol::GabageBotol()
{

}
GabageBotol::~GabageBotol()
{
	DeleteGO(m_skinModelRender);
}
bool GabageBotol::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/PetBotol.cmo");
	//m_position = { 300.0f, 0.0f, 500.0f };
	m_skinModelRender->SetScale(m_scale);

	m_getGra = FindGO<GetGarbageCount>("ggc");
	//m_position = { 300.0f, 0.0f, 500.0f };
	//m_skinModelRender->SetScale(m_scale);
	return true;
}

void GabageBotol::NearPlayer()
{
	if (m_player == nullptr)
	{
		m_player = FindGO<Player>("pl");
	}
	CVector3 PlGarbage = m_player->m_position - m_position;

	if (Pad(0).IsTrigger(enButtonA) && PlGarbage.Length() < 400.0f)
	{
		GetCount++;
		m_getGra->Add_GarbageCount(GetCount);
		DeleteGO(this);
	}
}

void GabageBotol::Update()
{
	NearPlayer();
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}