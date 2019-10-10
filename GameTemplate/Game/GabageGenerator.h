#pragma once
class GabageGenerator : public IGameObject
{
public:
	GabageGenerator();
	~GabageGenerator();
	void Update();

	float m_timer = 0.0f;   //タイマー
};

