#pragma once
class Title :public IGameObject

{
public:
	Title();
	~Title();

	prefab::CFontRender* Font=nullptr;

	prefab::CSpriteRender* m_spriteRender = nullptr;
prefab::CSpriteRender* m_spriteRender1 = nullptr;

prefab::CSoundSource* m_soundsource = nullptr;


	CVector2 m_position = {0, 0};
	CVector3 m_color = {1.0f,0.0f,0.0f};

	int m_timer = 0;
	

	CVector3 m_pos = CVector3::Zero;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	

	bool Start();

	void Update();


	float x = 0;
	float y = 60;
	float yT = 0;
	float ySpeed = 0.0f;
	float Newton = - 0.5f;

	int getcount = 0;
	int getcount2 = 0;



};

