#include "stdafx.h"
#include "GarbageBox.h"
#include "Player.h"
#include "Score.h"
#include "GetGarbageCount.h"

bool GarbageBox::Start()
{

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/GarbageBox.cmo");
	
	m_skinModelRender->SetScale(m_scale);

	m_pl = FindGO<Player>("pl");
	m_score = FindGO<Score>("score");
	m_garbageCount = FindGO<GetGarbageCount>("ggc");

	return true;
}


void GarbageBox::Update()
{
	CVector3 v = m_position - m_pl->GetPos();
	if (v.Length() < 100 && Pad(0).IsPress(enButtonB) && m_garbageCount->m_GetCount != 0)
	{
		m_score->m_score += m_garbageCount->m_GetCount;
		m_garbageCount->m_GetCount = 0;
	}


	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}