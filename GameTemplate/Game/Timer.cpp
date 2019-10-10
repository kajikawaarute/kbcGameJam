#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
	DeleteGO(m_font);
}

bool Timer::Start()
{
	m_font = NewGO<prefab::CFontRender>(0);
	m_font->SetPosition({ 0.0f, 200.0f });

	return true;
}

void Timer::Update()
{
	if (m_timer > 0.5) {
		m_timer -= GameTime().GetFrameDeltaTime();
	}
	wchar_t text[100];
	swprintf(text, L"Žc‚èŽžŠÔ@%.f", m_timer);
	m_font->SetText(text);
}
