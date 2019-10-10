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
#include "Timer.h"


Game::Game()
{
	m_gc = NewGO<GameCamera>(0, "gc");
	m_pl = NewGO<Player>(0, "pl");
	m_score = NewGO<Score>(0, "score");
	m_getGraCount = NewGO<GetGarbageCount>(0, "ggc");
	m_dirLight = NewGO <prefab::CDirectionLight>(0);
	m_dirLight2 = NewGO <prefab::CDirectionLight>(0);
	//m_stage = NewGO<Stage>(0, "stage01");
	
	//ディレクションライトを設定
	m_dirLight->SetDirection({ -0.707f, -0.707f, 0.707f});
	m_dirLight->SetColor({ 1000.0f, 1000.0f, 1000.0f, 1.0f });
	GraphicsEngine().GetShadowMap().SetLightDirection({ 1.0f, 0.0f, 1.0f });

	m_dirLight2->SetDirection({ 0.707f, 0.707f, -0.707f });
	m_dirLight2->SetColor({ 1000.0f, 1000.0f, 1000.0f, 1.0f });
	GraphicsEngine().GetShadowMap().SetLightDirection({ 0.0f, 1.0f, 0.0f });

	//レベルの構築
	m_level.Init(L"level/KBCjam_StageLevel.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"GarbageBox") == true) {
			//ゴミ箱のオブジェクト
			GarbageBox* garbagebox = NewGO<GarbageBox>(0, "GarbageBox");
			garbagebox->m_position = objData.position;
			garbagebox->m_rotation = objData.rotation;
			garbagebox->m_scale = objData.scale;
			return true;
		}

		else if (objData.EqualObjectName(L"PetBotol") == true) {
			//ボトルのオブジェクト
			GabageBotol* botol = NewGO<GabageBotol>(0, "Botol");
			botol->m_position = objData.position;
			botol->m_rotation = objData.rotation;
			botol->m_scale = objData.scale;
			return true;
		}

		else if (objData.EqualObjectName(L"Paper") == true) {
			//紙ごみのオブジェクト
			GarbagePaper* paper = NewGO<GarbagePaper>(0, "Paper");
			paper->m_position = objData.position;
			paper->m_rotation = objData.rotation;
			paper->m_scale = objData.scale;
			return true;
		}
		return false;
	});

	m_stage = NewGO<Stage>(0, "stage01");
	m_timer = NewGO<Timer>(0, "timer");
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
	m_timer = FindGO<Timer>("timer");
	DeleteGO(m_timer);

	m_stage = FindGO<Stage>("stage01");
	DeleteGO(m_stage);

	DeleteGO(m_dirLight);

	Title* TL = FindGO<Title>("Title1");
	DeleteGO(TL);

	

	DeleteGOs("GarbageBox");
	DeleteGOs("Botol");
	DeleteGOs("Paper");
}
bool Game::Start()
{

	//m_paper = NewGO<GarbagePaper>(0, "Paper");
	//m_gabagebox = NewGO<GarbageBox>(0, "GarbageBox");
	//m_botol = NewGO<GabageBotol>(0, "Botol");
	return true;
}

void Game::Update()
{
}