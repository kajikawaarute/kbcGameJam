#pragma once
//class GarbageBase;
class Player;
//class Score;
class GetGarbageCount;
class Timer;
class GarbagePaper : public IGameObject
{
public:
	GarbagePaper();
	~GarbagePaper();
	bool Start();
	void NearPlayer();
	void Update();

	const CVector3& GetPaperPos() const
	{
		return m_position;
	}
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 GarbageNewPos = CVector3::Zero;
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデルレンダー
	Player* m_player = nullptr;
	//Score* m_score = nullptr;	//スコアのインスタンス
	GetGarbageCount* m_getGra = nullptr;	//拾ったゴミカウントのインスタンス
	Timer* m_timer = nullptr;		//タイマーのインスタンス
	int GetCount = 0;
};

