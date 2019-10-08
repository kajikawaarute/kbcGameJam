#include "stdafx.h"
#include "GarbagePaper.h"

bool GarbagePaper::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Paper.cmo");

	m_skinModelRender->SetScale(m_scale);
	return true;
}

void GarbagePaper::Update()
{
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}
