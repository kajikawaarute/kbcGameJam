#pragma once
class GetGarbageCount : public IGameObject
{
public:
	bool Start();
	void Update();

	void Add_GarbageCount(int count)
	{
		m_GetCount += count;
	}

	prefab::CFontRender* m_font = nullptr;
	int m_GetCount = 0;
};

