#include "stdafx.h"
#include "Result.h"
#include "Title.h"
#include "Score.h"


Result::Result()
{
}


Result::~Result()
{

	DeleteGO(m_spriterender);
	/*DeleteGO(m_spriterender1);
	DeleteGO(m_spriterender2);*/
	DeleteGO(Font1);
	//DeleteGO(m_ef);


}

bool Result::Start()
{

	
	

	if (m_score == nullptr) {
		m_score = FindGO<Score>("score");
	}
	
	//int a = m_score->m_score;

m_spriterender = NewGO<prefab::CSpriteRender>(0);

m_spriterender->Init(L"sprite/result01.dds", 720.0f, 1280.0f);


Font1 = NewGO<prefab::CFontRender>(0);
m_ef = NewGO < prefab::CEffect >(0);//ぬかすな！！」

//この中にスコアを格納します。

wchar_t text[256];
swprintf(text, L"スコア %d", m_score->m_score);
Font1->SetText(text);


//prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
m_ef->Play(L"effect/fucukikai.efk");


CVector3 efPos = m_position;
efPos.y = 50.0f;
m_ef->SetPosition(efPos);



return true;


}


void Result::Update() {


	x += 10;


	m_position1= { x,y /*0.0f,0.0f */ };

	Font1->SetPosition(m_position1);



	timer++;


	if (timer == 400) {
		NewGO<Title>(0);
		DeleteGO(this);

		


	}
		
}