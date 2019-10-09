#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
{
}


Stage::~Stage()
{

	DeleteGO(m_skinmodelrender);
}


bool Stage::Start() {                                                                                                                                          

	m_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelrender->Init(L"modelData/stage.cmo");

	m_staticObject.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One, m_skinmodelrender);

	return true;

}