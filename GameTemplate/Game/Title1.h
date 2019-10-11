#pragma once
class Title1:public IGameObject
{
public:
	Title1();
	~Title1();



	bool Start();

	void Update();


	prefab::CFontRender* Font=nullptr;


prefab::CSpriteRender* m_spriteRender2 = nullptr;
CVector2 m_position = {0, 0};

	CVector3 m_color = {1.0f,0.0f,0.0f};

	float x = 0;
	float y = 60;
	float yT = 0;
	float ySpeed = 0.0f;
	float Newton = - 0.5f;

	int getcount = 0;
	int getcount2 = 0;


};

