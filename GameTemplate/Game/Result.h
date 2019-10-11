#pragma once
#include "Score.h"

class Result :public IGameObject
{
public:
	Result();
	~Result();
	//2d
	prefab::CSpriteRender* m_spriterender = nullptr;
	prefab::CSpriteRender* m_spriterender1 = nullptr;
	prefab::CSpriteRender* m_spriterender2 = nullptr;

	prefab::CSoundSource* m_sound = nullptr;

	//fontseikou
	Score* m_score = nullptr;
prefab::CFontRender* Font1 = nullptr;


	float x = -400.0f;
	float y = 100.0f;
	CVector2 m_position1;
	float scale=3.0f;
	CVector3 Setcolor = {0.0f,1.0f,0.0f};



	//font1

	float x1 = 0;
	float y1 = 60;
	float yT = 0;
	float ySpeed = 0.0f;
	float Newton = -0.5f;

	int getcount = 0;
	int getcount2 = 0;

	CVector2 m_position2;



	//effect
	prefab::CEffect* m_ef = nullptr;
	CVector3 m_position=CVector3::Zero;

	//time
	int timer = 0;

	











	bool Start();


	void Update();


};

