#pragma once
class Result :public IGameObject
{
public:
	Result();
	~Result();

	prefab::CSpriteRender* m_spriterender = nullptr;
	prefab::CSpriteRender* m_spriterender1 = nullptr;
	prefab::CSpriteRender* m_spriterender2 = nullptr;

	prefab::CFontRender* Font1 = nullptr;

	int i = 0.0f;
	int y = 0.0f;

	CVector2 m_position1 = {i,y /*0.0f,0.0f */};



	bool Start();


	void Update();


};

