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
	void AnimationController();

	CVector3 GetPos()
	{
		return m_position;
	}

	enum EnAnimationClip {
		enAnimationClip_Player_Idle,
		enAnimationClip_Player_Run,
		enAnimationClip_Player_Gomihiroi,
		enAnimationClip_num
	};
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_moveSpeed = CVector3::Zero;						//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale = CVector3::One;
	CCharacterController m_charaCon;							//キャラクターコントローラー

	CAnimationClip m_animationClip[enAnimationClip_num];	//アニメーションクリップ。

	int ChangeHIroiMo = 0;
	
};

