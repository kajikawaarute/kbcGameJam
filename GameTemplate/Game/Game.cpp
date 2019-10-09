#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "Player.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GarbageBox.h"
#include "GarbagePaper.h"
#include "GabageBotol.h"

Game::Game()
{
	m_gc = NewGO<GameCamera>(0, "gc");
	m_pl = NewGO<Player>(0, "pl");
}


Game::~Game()
{
	m_gc = FindGO<GameCamera>("gc");
	DeleteGO(m_gc);
	m_pl = FindGO<Player>("pl");
	DeleteGO(m_pl);
}
bool Game::Start()
{

	//m_paper = NewGO<GarbagePaper>(0, "Paper");
	m_gabagebox = NewGO<GarbageBox>(0, "GarbageBox");
	m_botol = NewGO<GabageBotol>(0, "Botol");
	return true;
}

void Game::Update()
{
}