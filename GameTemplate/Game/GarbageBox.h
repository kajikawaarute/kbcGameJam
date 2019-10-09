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
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f�������_�[

	Player* m_pl = nullptr;		//�v���C���[�̃C���X�^���X
	Score* m_score = nullptr;	//�X�R�A�̃C���X�^���X
	GetGarbageCount* m_garbageCount; //�E�����S�~�J�E���g�̃C���X�^���X
};