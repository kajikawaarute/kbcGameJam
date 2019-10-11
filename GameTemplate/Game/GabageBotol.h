#pragma once
//class GarbageBase;
class Player;
class GetGarbageCount;
class Timer;
class GabageBotol : public IGameObject
{
public:
	GabageBotol();
	~GabageBotol();
	bool Start();
	void NearPlayer();
	void Update();

	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 GarbageNewPos = CVector3::Zero;
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデルレンダー
	Player *m_player = nullptr;
	GetGarbageCount* m_getGra = nullptr;	//拾ったゴミカウントのインスタンス
	Timer* m_timer = nullptr;
	int GetCount = 0;
	//GarbageBase Base;
};

