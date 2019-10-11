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
class Timer;
class GabageGenerator;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	//GarbageBox* m_gabagebox = nullptr;
	GarbagePaper* m_paper = nullptr;
	//GabageBotol* m_botol = nullptr;
	GabageGenerator* m_generator = nullptr;  //ゴミジェネレーターのインスタンス

	Stage* m_stage = nullptr;


	GameCamera* m_gc = nullptr;		//ゲームカメラのインスタンス
	Player* m_pl = nullptr;			//プレイヤーのインスタンス
	Score* m_score = nullptr;		//スコアのインスタンス
	CLevel m_level;                 //レベル
	GetGarbageCount* m_getGraCount = nullptr;	//拾ったゴミカウントのインスタンス
	Timer* m_timer = nullptr;		//タイマーのインスタンス
	prefab::CDirectionLight* m_dirLight = nullptr;		//ディレクションライトのインスタンス
	prefab::CDirectionLight* m_dirLight2 = nullptr;		//ディレクションライト2のインスタンス
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CSpriteRender* m_sprite = nullptr;
	bool m_clearFlag = false;
	int m_time = 0.0f;
	int m_time2 = 0.0f;

};

