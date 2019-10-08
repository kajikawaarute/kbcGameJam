#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class GarbageBox;
class GarbagePaper;
class GabageBotol;
class GameCamera;
class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	GarbageBox* m_gabagebox = nullptr;
	GarbagePaper* m_paper = nullptr;
	GabageBotol* m_botol = nullptr;

	GameCamera* m_gc = nullptr;		//ゲームカメラのインスタンス
	Player* m_pl = nullptr;			//プレイヤーのインスタンス
};

