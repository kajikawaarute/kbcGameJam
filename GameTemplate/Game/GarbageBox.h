#pragma once

class Player;
class Score;
class GetGarbageCount;
class GarbageBox : public IGameObject
{
public:
	bool Start();

	void Update();

	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデルレンダー

	Player* m_pl = nullptr;		//プレイヤーのインスタンス
	Score* m_score = nullptr;	//スコアのインスタンス
	GetGarbageCount* m_garbageCount; //拾ったゴミカウントのインスタンス
};