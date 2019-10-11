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
	GabageGenerator* m_generator = nullptr;  //�S�~�W�F�l���[�^�[�̃C���X�^���X

	Stage* m_stage = nullptr;


	GameCamera* m_gc = nullptr;		//�Q�[���J�����̃C���X�^���X
	Player* m_pl = nullptr;			//�v���C���[�̃C���X�^���X
	Score* m_score = nullptr;		//�X�R�A�̃C���X�^���X
	CLevel m_level;                 //���x��
	GetGarbageCount* m_getGraCount = nullptr;	//�E�����S�~�J�E���g�̃C���X�^���X
	Timer* m_timer = nullptr;		//�^�C�}�[�̃C���X�^���X
	prefab::CDirectionLight* m_dirLight = nullptr;		//�f�B���N�V�������C�g�̃C���X�^���X
	prefab::CDirectionLight* m_dirLight2 = nullptr;		//�f�B���N�V�������C�g2�̃C���X�^���X
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CSpriteRender* m_sprite = nullptr;
	bool m_clearFlag = false;
	int m_time = 0.0f;
	int m_time2 = 0.0f;

};

