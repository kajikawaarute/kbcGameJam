#include "stdafx.h"
#include "GetGarbageCount.h"



GetGarbageCount::GetGarbageCount()
{
}

GetGarbageCount::~GetGarbageCount()
{
	DeleteGO(m_font);
	DeleteGO(m_sprite);
}

bool GetGarbageCount::Start()
{
	m_font = NewGO<prefab::CFontRender>(0);
	m_font->SetPosition({ -500.0f, 200.0f });

	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/gomi.dds", 150, 100);
	m_sprite->SetPosition({ -550.0f, 200.0f, 0.0f });
	return true;
}

void GetGarbageCount::Update()
{
	wchar_t text[256];
	swprintf(text, L"E‚Á‚½ƒSƒ~ %d", m_GetCount);
	m_font->SetText(text);

}
