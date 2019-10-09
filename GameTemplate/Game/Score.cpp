#include "stdafx.h"
#include "Score.h"

Score::Score()
{
}

Score::~Score()
{
}

bool Score::Start()
{
	m_font = NewGO<prefab::CFontRender>(0);
	m_font->SetPosition({ 400.0f, 200.0f });

	return true;
}

void Score::Update()
{
	wchar_t text[256];
	swprintf(text, L"ƒXƒRƒA %d", m_score);
	m_font->SetText(text);
}
