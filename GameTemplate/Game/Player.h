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

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;						//���W
	CVector3 m_moveSpeed = CVector3::Zero;						//�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CCharacterController m_charaCon;							//�L�����N�^�[�R���g���[���[
	
};

