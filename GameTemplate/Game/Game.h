#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class GameCamera;
class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();

	GameCamera* m_gc = nullptr;		//�Q�[���J�����̃C���X�^���X
	Player* m_pl = nullptr;			//�v���C���[�̃C���X�^���X
};

