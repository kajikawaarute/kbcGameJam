#pragma once
class Timer : public IGameObject
{
public:
	Timer();
	~Timer();
	bool Start();
	void Update();

	prefab::CFontRender* m_font = nullptr;
	float m_timer = 30;
	

};

