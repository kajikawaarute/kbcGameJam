#include "stdafx.h"
#include "Title.h"
#include "Game.h"
//#include "FontMove.h"

Title::Title()
{
}


Title::~Title()
{

	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender1);
	DeleteGO(m_soundsource1);

}

bool Title::Start()
{


	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender1 = NewGO<prefab::CSpriteRender>(0);

	m_soundsource = NewGO<prefab::CSoundSource>(0);
	m_soundsource1 = NewGO<prefab::CSoundSource>(0);

m_spriteRender->Init(L"sprite/Title1.dds", 1270.0f, 720.0f);
		m_spriteRender1->Init(L"sprite/plse.dds", 1270.0f, 1270.0f);
		
m_soundsource->Init(L"sound/GAMESTARTsound.wav");
	m_soundsource1->Init(L"sound/game_maoudamashii_4_field11.wav");
	
//	// エフェクト関係の処理
//	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
//	//エフェクトを再生。
//	effect->Play(L"effect/fa.efk");
//	CVector3 emitPos = m_pos;
//	emitPos.y += 10.0f;
//	effect->SetPosition(emitPos);
//
//m_pos.z += Pad(0).GetLStickXF();
//m_pos.y += Pad(0).GetLStickYF();
//m_skinModelRender->SetPosition(m_pos);
//m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
		m_spriteRender1->SetPosition({ 0.0f, -400.0f, 0.0f });
	return true;
}

void Title::Update()
{


	




	




//
	//x=l_pos->y;

	//y=l_pos->x;


	//m_position = l_pos->m_position;

/*	if (bunki == 1)*/ 

	



		//NewGO < FontMove>  (0, "FontMove");
		//l_pos= FindGO<FontMove>("FontMove");

		

		//CVector2 pos = { 0.0f,1.0f};
	/*	int bunki1 = 1;
		bunki = 2;*/

	

	//if(bunki1==1&&bunki==2)
	



		m_soundsource1->Play(true);

		m_timer++;
		if (m_timer < 40) {
			m_spriteRender1->SetActiveFlag(false);

		}


		if (m_timer >= 40) {
			m_spriteRender1->SetActiveFlag(true);

		}


		if (m_timer > 79)
		{
			m_timer = 0;

		}


	if (Pad(0).IsPress(enButtonA)) {
		m_soundsource->Play(false);

		NewGO<Game>(0, nullptr);
		DeleteGO(this);



	}

}




