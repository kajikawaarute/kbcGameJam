#include "stdafx.h"
#include "Result.h"


Result::Result()
{
}


Result::~Result()
{

	DeleteGO(m_spriterender);
	DeleteGO(m_spriterender1);
	DeleteGO(m_spriterender2);


}

bool Result::Start()
{



m_spriterender = NewGO<prefab::CSpriteRender>(0);

m_spriterender->Init(L"sprite/result01.dds", 720.0f, 1280.0f);

Font1 = NewGO<prefab::CFontRender>(0);

return true;


}


void Result::Update() {




	Font1->SetPosition(m_position1);

		
}