#include "stdafx.h"
#include "GarbagePaper.h"
//#include "GarbageBase.h"
#include "Player.h"
//#include "Score.h"
#include "GetGarbageCount.h"
#include "Timer.h"

GarbagePaper::GarbagePaper()
{

}
GarbagePaper::~GarbagePaper()
{
	DeleteGO(m_skinModelRender);
}

bool GarbagePaper::Start()
{
	//m_score = FindGO<Score>("score");
	m_getGra = FindGO<GetGarbageCount>("ggc");
	m_timer = FindGO<Timer>("timer");

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Paper.cmo");

	
	return true;
}

void GarbagePaper::NearPlayer()
{
	if (m_player == nullptr)
	{
		m_player = FindGO<Player>("pl");
	}
	CVector3 PlGarbage = m_player->m_position - m_position;

	if (Pad(0).IsTrigger(enButtonA) && PlGarbage.Length() < 150.0f && m_timer->m_timer >= 0.5f)
	{
		//âπÇçƒê∂
		prefab::CSoundSource* sound = NewGO<prefab::CSoundSource>(0);
		sound->Init(L"sound/GetGarbage.wav");
		sound->Play(false);

		GetCount++;
		m_getGra->Add_GarbageCount(GetCount);
		DeleteGO(this);
	}
}
void GarbagePaper::Update()
{
	NearPlayer();
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}
