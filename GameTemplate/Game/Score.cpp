#include "stdafx.h"
#include "Score.h"

Score::Score()
{
}

Score::~Score()
{
	DeleteGO(m_font);
	DeleteGO(m_sprite);
}

bool Score::Start()
{
	m_font = NewGO<prefab::CFontRender>(0);
	m_font->SetPosition({ -500.0f, 100.0f });

	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/gomibako.dds", 100, 100);
	m_sprite->SetPosition({ -550.0f, 100.0f, 0.0f });
	return true;
}

void Score::Update()
{
	wchar_t text[256];
	swprintf(text, L"ŽÌ‚Ä‚½ƒSƒ~ %d", m_score);

	m_font->SetText(text);


}
