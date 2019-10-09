#include "stdafx.h"
#include "GetGarbageCount.h"

bool GetGarbageCount::Start()
{
	m_font = NewGO<prefab::CFontRender>(0);
	m_font->SetPosition({ -500.0f, 200.0f });
	return true;
}

void GetGarbageCount::Update()
{
	wchar_t text[256];
	swprintf(text, L"E‚Á‚½ƒSƒ~ %d", m_GetCount);
	m_font->SetText(text);

}
