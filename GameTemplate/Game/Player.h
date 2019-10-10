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
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;						//���W
	CVector3 m_moveSpeed = CVector3::Zero;						//�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CVector3 m_scale = CVector3::One;
	CCharacterController m_charaCon;							//�L�����N�^�[�R���g���[���[

	CAnimationClip m_animationClip[enAnimationClip_num];	//�A�j���[�V�����N���b�v�B

	int ChangeHIroiMo = 0;
	
};

