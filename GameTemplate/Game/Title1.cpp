#include "stdafx.h"
#include "Title1.h"
#include "Title.h"


Title1::Title1()
{
}


Title1::~Title1()
{

	DeleteGO(m_spriteRender2);
	DeleteGO(Font);
		//NewGO<Title>(0,nullptr);


}

bool Title1::Start() {

	m_spriteRender2 = NewGO<prefab::CSpriteRender > (0);
	m_spriteRender2->Init(L"sprite/titlesceen1.dds", 1270.0f, 720.0f);
		Font = NewGO<prefab::CFontRender>(0);
		Font->SetText(L"KAJIMOTOGAMES");
		
		
		return true;

}


void Title1::Update() {



	if (getcount == 0 && y > -320) {
		ySpeed += Newton;

	}


	else if (getcount2 == 0) {
		getcount = 1;




		if (getcount == 1) {
			ySpeed = 10.0f;

			getcount2 = 1;

			getcount = 2;

		}


		if (getcount2 == 1) {
			ySpeed -= 0.5f;


			x += 10;

		}


		y += ySpeed;

		m_position = { x,y };


		Font->SetPosition(m_position);
		Font->SetColor(m_color);
	}

}
