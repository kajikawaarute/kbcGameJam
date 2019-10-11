#include "stdafx.h"
#include "GarbageBox.h"
#include "Player.h"
#include "Score.h"
#include "GetGarbageCount.h"
#include "Timer.h"

GarbageBox::~GarbageBox()
{

	DeleteGO(m_skinModelRender);

}

bool GarbageBox::Start()
{

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/GarbageBox.cmo");
	
	m_skinModelRender->SetScale(m_scale);

	m_pl = FindGO<Player>("pl");
	m_score = FindGO<Score>("score");
	m_garbageCount = FindGO<GetGarbageCount>("ggc");
	m_timer = FindGO<Timer>("timer");

	return true;
}


void GarbageBox::Update()
{
	CVector3 v = m_position - m_pl->GetPos();
	if (v.Length() < 200 && Pad(0).IsPress(enButtonB) && m_garbageCount->m_GetCount != 0 && m_timer->m_timer >= 0.5f)
	{
		//âπÇçƒê∂
		prefab::CSoundSource* sound = NewGO<prefab::CSoundSource>(0);
		sound->Init(L"sound/GetGarbageBox.wav");
		sound->Play(false);

		m_score->m_score += m_garbageCount->m_GetCount;
		m_garbageCount->m_GetCount = 0;
	}


	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}