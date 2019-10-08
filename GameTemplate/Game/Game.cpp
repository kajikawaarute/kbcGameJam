#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "Player.h"
#include "tkEngine/light/tkDirectionLight.h"

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
	return true;
}

void Game::Update()
{
}