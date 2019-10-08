#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GarbageBox.h"
#include "GarbagePaper.h"
#include "GabageBotol.h"

Game::Game()
{
	NewGO<GameCamera>(0, "gc");
}


Game::~Game()
{
	GameCamera* gc = FindGO<GameCamera>("gc");
	DeleteGO(gc);
}
bool Game::Start()
{

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