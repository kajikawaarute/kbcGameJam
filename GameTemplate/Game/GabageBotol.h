#pragma once
class GabageBotol : public IGameObject
{
private:
	bool Start();
	void Update();

	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデルレンダー
};

