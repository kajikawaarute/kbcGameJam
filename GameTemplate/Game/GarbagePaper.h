#pragma once
class GarbagePaper : public IGameObject
{
public:
	bool Start();
	void Update();

	const CVector3& GetPaperPos() const
	{
		return m_position;
	}
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデルレンダー
};

