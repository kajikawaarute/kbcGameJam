#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Stage.h"

class GarbageBox;
class GarbagePaper;
class GabageBotol;
class GameCamera;
class Player;
class Score;
class GetGarbageCount;
class Stage;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	GarbageBox* m_gabagebox = nullptr;
	GarbagePaper* m_paper = nullptr;
	GabageBotol* m_botol = nullptr;


	Stage* m_stage = nullptr;


	GameCamera* m_gc = nullptr;		//ゲームカメラのインスタンス
	Player* m_pl = nullptr;			//プレイヤーのインスタンス
	Score* m_score = nullptr;		//スコアのインスタンス
	GetGarbageCount* m_getGraCount = nullptr;	//
};

