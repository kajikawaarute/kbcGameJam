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
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f�������_�[
	Player* m_player = nullptr;
	//Score* m_score = nullptr;	//�X�R�A�̃C���X�^���X
	GetGarbageCount* m_getGra = nullptr;	//�E�����S�~�J�E���g�̃C���X�^���X
	Timer* m_timer = nullptr;		//�^�C�}�[�̃C���X�^���X
	int GetCount = 0;
};

