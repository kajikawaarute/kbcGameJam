#pragma once

class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();

	CVector3 m_toCameraPos;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_Target = CVector3::Zero;
	Player* m_pl = nullptr;			//プレイヤーのインスタンス
};

