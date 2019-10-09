#pragma once

class Stage :public IGameObject

{
public:
	Stage();
	~Stage();
	bool Start();

	prefab::CSkinModelRender* m_skinmodelrender=nullptr;
	CPhysicsStaticObject m_staticObject;



	



};

