#pragma once
class Title :public IGameObject

{
public:
	Title();
	~Title();


	prefab::CSpriteRender* m_spriteRender = nullptr;
prefab::CSpriteRender* m_spriteRender1 = nullptr;




prefab::CSoundSource* m_soundsource = nullptr;
prefab::CSoundSource* m_soundsource1 = nullptr;



	

	int m_timer = 0;
	

	CVector3 m_pos = CVector3::Zero;

	bool Start();

	void Update();

	//FontMove* l_pos = nullptr;
	
	//int bunki=0;
	//int bunki1 = 0;






};

