#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Turn();
	
	CVector3 GetPos()
	{
		return m_position;
	}

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_moveSpeed = CVector3::Zero;						//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CCharacterController m_charaCon;							//キャラクターコントローラー
	
};

