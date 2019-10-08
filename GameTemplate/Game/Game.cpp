#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GarbageBox.h"
#include "GarbagePaper.h"
#include "GabageBotol.h"

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");

	m_paper = NewGO<GarbagePaper>(0, "Paper");
	m_gabagebox = NewGO<GarbageBox>(0, "GarbageBox");
	//m_botol = NewGO<GabageBotol>(0, "Botol");
	return true;
}

void Game::Update()
{
}