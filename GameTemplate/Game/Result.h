#pragma once
#include "Score.h"

class Result :public IGameObject
{
public:
	Result();
	~Result();

	prefab::CSpriteRender* m_spriterender = nullptr;
	prefab::CSpriteRender* m_spriterender1 = nullptr;
	prefab::CSpriteRender* m_spriterender2 = nullptr;
	Score* m_score = nullptr;


	prefab::CFontRender* Font1 = nullptr;

	float x = -400.0f;
	float y = 0.0f;

	CVector2 m_position1;

	CVector3 m_position=CVector3::Zero;

	prefab::CEffect* m_ef = nullptr;
	int timer = 0;

	bool Start();


	void Update();


};

