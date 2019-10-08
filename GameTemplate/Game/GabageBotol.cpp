#include "stdafx.h"
#include "GabageBotol.h"

bool GabageBotol::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/PetBotol.cmo");

	m_skinModelRender->SetScale(m_scale);
	return true;
}

void GabageBotol::Update()
{
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}