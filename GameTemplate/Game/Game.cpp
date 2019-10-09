#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "Player.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GarbageBox.h"
#include "GarbagePaper.h"
#include "GabageBotol.h"
#include "Title.h"
#include  "Score.h"
#include "GetGarbageCount.h"
#include "Stage.h"



Game::Game()
{
	m_gc = NewGO<GameCamera>(0, "gc");
	m_pl = NewGO<Player>(0, "pl");
	m_score = NewGO<Score>(0, "score");
	m_getGraCount = NewGO<GetGarbageCount>(0, "ggc");
	m_stage = NewGO<Stage>(0, "stage01");

}


Game::~Game()
{
	m_gc = FindGO<GameCamera>("gc");
	DeleteGO(m_gc);
	m_pl = FindGO<Player>("pl");
	DeleteGO(m_pl);
	m_score = FindGO<Score>("score");
	DeleteGO(m_score);
	m_getGraCount = FindGO<GetGarbageCount>("ggc");
	DeleteGO(m_getGraCount);
	
	m_stage = FindGO<Stage>("stage01");
	DeleteGO(m_stage);


	Title* TL = FindGO<Title>("Title1");
	DeleteGO(TL);

	

	DeleteGOs("GarbageBox");
	DeleteGOs("Botol");
	DeleteGOs("Paper");
}
bool Game::Start()
{

	m_paper = NewGO<GarbagePaper>(0, "Paper");
	m_gabagebox = NewGO<GarbageBox>(0, "GarbageBox");
	//m_botol = NewGO<GabageBotol>(0, "Botol");
	return true;
}

void Game::Update()
{
}