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


	CVector2 m_position = {1, 0};
	CVector3 m_color = {1.0f,0.0f,0.0f};

	int m_timer = 0;
	

	CVector3 m_pos = CVector3::Zero;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	

	bool Start();

	void Update();



};

