#include "stdafx.h"
#include "GarbageBox.h"

bool GarbageBox::Start()
{

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/GarbageBox.cmo");
	
	m_skinModelRender->SetScale(m_scale);
	return true;
}


void GarbageBox::Update()
{
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}