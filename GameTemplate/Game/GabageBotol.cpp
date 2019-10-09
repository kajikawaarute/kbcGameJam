#include "stdafx.h"
#include "GabageBotol.h"
//#include "GarbageBase.h"
#include "Player.h"
bool GabageBotol::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/PetBotol.cmo");

	m_skinModelRender->SetScale(m_scale);
	return true;
}

void GabageBotol::NearPlayer()
{
	if (m_player == nullptr)
	{
		m_player = FindGO<Player>("pl");
	}
	CVector3 PlGarbage = m_player->m_position - m_position;

	if (Pad(0).IsTrigger(enButtonA) && PlGarbage.Length() < 500.0f)
	{
		GarbageNewPos = m_position;
		m_position = GarbageNewPos + m_player->m_position;
	}
}

void GabageBotol::Update()
{
	NearPlayer();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}