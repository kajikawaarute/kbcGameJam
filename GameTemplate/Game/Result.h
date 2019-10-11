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
prefab::CFontRender* Font2 = nullptr;
prefab::CFontRender* Font3 = nullptr;
prefab::CFontRender* Font4 = nullptr;
prefab::CFontRender* Font5 = nullptr;
prefab::CFontRender* Font6 = nullptr;
prefab::CFontRender* Font7 = nullptr;
prefab::CFontRender* Font8 = nullptr;
prefab::CSpriteRender* m_spriterender4 = nullptr;



	float x = -400.0f;
	float y = 100.0f;
	CVector2 m_position1;
	float scale=3.0f;
	CVector3 Setcolor = {0.0f,1.0f,0.0f};


	CVector2 position3 = {xa,y3};
	CVector2 position4 = {xb,y4};
	CVector2 position5 = {xc,y5};
	CVector2 position6 = {xd,y6};
	CVector2 position7 = {xe,y7};
	CVector2 position8 = { xf,y8 };
	CVector2 position9 = { xg,y9 };

	//CVector2 m_position2 = {-300.0f,-300.0f};

	float y3=400.0f,y4=400.0f, y5=400.0f, y6=400.0f, y7=400.0f, y8=400.0f, y9=400.0f ;
	float xa =0.0f;
	float xb = 150.0f;
	float xc = 200.0f;
	float xd = 300.0f;
	float xe = 400.0f;
	float xf = 450.0f;
	float xg = 500.0f;



	//effect
	prefab::CEffect* m_ef = nullptr;
	CVector3 m_position=CVector3::Zero;

	//time
	int timer = 0;

	int timer1 = 0;

	bool Start();


	void Update();
	CVector2 FontMove(float a,float b);
	//1

	float ex = 0;
	float ey = 400;
	float yT = 0;
	float ySpeed = 0.0f;
	float Newton = -0.5f;

	int getcount = 0;

	CVector2 e_position3;



	int getcount2 = 0;
	//2
	float ex1 = 0;
	float ey1 = 400;
	float yT1 = 0;
	float ySpeed1 = 0.0f;
	float Newton1 = -0.5f;

	int getcount11 = 0;

	CVector2 e_position4;



	int getcount21 = 0;


};
	


	//font1

	