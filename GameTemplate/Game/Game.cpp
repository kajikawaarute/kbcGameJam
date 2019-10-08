#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "tkEngine/light/tkDirectionLight.h"

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
	
	return true;
}

void Game::Update()
{
}