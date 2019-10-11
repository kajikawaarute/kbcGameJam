#pragma once
class Score : public IGameObject
{
public:
	Score();
	~Score();
	bool Start();
	void Update();

	int GetScore()
	{
		return m_score;
	}
	prefab::CSpriteRender* m_sprite = nullptr;
	prefab::CFontRender* m_font = nullptr;
	int m_score = 0;
};

