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
	DeleteGO(Font2);
	DeleteGO(Font3);
	/*DeleteGO(Font4);
	DeleteGO(Font5);
	DeleteGO(Font6);
	DeleteGO(Font7);
	DeleteGO(Font8);*/
	DeleteGO(m_spriterender4);


}


CVector2 Result::FontMove(float x1,float y1) {

	float yT = 0;
	float ySpeed = 0.0f;
	float Newton = -0.5f;

	int getcount = 0;
	int getcount2 = 0;
    if (getcount == 0 && y1 > -320) {
		ySpeed += Newton;

	}


	else if (getcount2 == 0) {
		getcount = 1;
	}


		if (getcount == 1) {
		
			ySpeed = 10.0f;

			getcount2 = 1;

			getcount = 2;

		}


		if (getcount2 == 1) {
			ySpeed -= 0.5f;


			x1 += 10;

		}
	

		y1 += ySpeed;
	

		CVector2 m_position = {x1,y1};

	return m_position;

}

bool Result::Start()
{

	
	

	if (m_score == nullptr) {
		m_score = FindGO<Score>("score");
	}
	
	//int a = m_score->m_score;

m_spriterender = NewGO<prefab::CSpriteRender>(0);

m_spriterender->Init(L"sprite/result01.dds", 720.0f, 1280.0f);


m_spriterender4 = NewGO<prefab::CSpriteRender>(0);





Font1= NewGO<prefab::CFontRender>(0);
Font2 = NewGO<prefab::CFontRender>(0); 
Font3 = NewGO<prefab::CFontRender>(0);
Font4 = NewGO<prefab::CFontRender>(0);
Font5 = NewGO<prefab::CFontRender>(0); 
Font6 = NewGO<prefab::CFontRender>(0);
Font7 = NewGO<prefab::CFontRender>(0);
Font8 = NewGO<prefab::CFontRender>(0);


Font2->SetText(L"‚Ü‚½");
Font3->SetText(L"‚ ‚»‚ñ‚Å‚Ë"); 
//Font4->SetText(L"‚ ");
//Font5->SetText(L"‚»");
//Font6->SetText(L"‚ñ");
//Font7->SetText(L"‚Å");
//Font8->SetText(L"‚Ë");


m_ef = NewGO < prefab::CEffect >(0);//‚Ê‚©‚·‚ÈIIv

//‚±‚Ì’†‚ÉƒXƒRƒA‚ðŠi”[‚µ‚Ü‚·B

wchar_t text[256];
swprintf(text, L"ƒXƒRƒA %d", m_score->m_score);
Font1->SetText(text);


//prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
m_ef->Play(L"effect/fucukikai.efk");


CVector3 efPos = m_position;
efPos.y = 50.0f;
m_ef->SetPosition(efPos);



return true;


}



void Result::Update() {


	

	if (x<0)
	{

x += 10;

	}


	m_position1= { x,y /*0.0f,0.0f */ };

	Font1->SetPosition(m_position1);
	Font1->SetScale(scale);
	Font1->SetColor(Setcolor);



	timer++;
	if (timer == 300) {

		m_spriterender4->Init(L"sprite/shousan.dds", 200.0f, 200.0f);
		m_spriterender4->SetPosition({-400.0f, -200.0f, 0.0f});

	}

	if (timer == 400) {
		NewGO<Title>(0);
		DeleteGO(this);

		


	}

	//Font28

	

	timer1++;



	position3 = FontMove(xa, y3);


	if (timer1 > 10) {
	
	position4= FontMove(xb, y4);


	
	}
	/*if (timer1 > 20) {


		position5 = FontMove(xc, y5);



	}
	if (timer1 > 30) {
		
		position6 = FontMove(xd, y6);


	}
	if (timer1 > 40) {


		position7 = FontMove(xe, y7);

	}
	if (timer1 > 50) {

		
		position8 = FontMove(xf, y8);



	}
	if (timer1 > 60) {
	

		position9 = FontMove(xg, y9);


	}*/
	
	if (getcount11 == 0 && ey1 > -20) {

		ySpeed1 += Newton1;



	}

	//’n–Ê‚É‚Ô‚Â‚©‚Á‚½‚Æ‚«‚Ìˆ—‚Q

	//‚R
	else if (getcount21 == 0) {

		getcount11 = 1;

	}

	//@‚S
	if (getcount11 == 1) {

		ySpeed1 = 10.0f;

		getcount21 = 1;

		getcount11 = 2;




	}
	//‚T
	if (getcount21 == 1) {

		ySpeed1 -= 0.5f;






		ex1 += 10;


	}




	ey1 += ySpeed1;


	e_position4 = { ex1,ey1 };

	if (getcount11 == 0 && y > -20) {

		ySpeed1 += Newton;



	}

	//’n–Ê‚É‚Ô‚Â‚©‚Á‚½‚Æ‚«‚Ìˆ—‚Q

	//‚R
	else if (getcount2 == 0) {

		getcount = 1;

	}

	//@‚S
	if (getcount == 1) {

		ySpeed1 = 10.0f;

		getcount2 = 1;

		getcount = 2;




	}
	//‚T
	if (getcount2 == 1) {

		ySpeed -= 0.5f;






		ex += 10;


	}




	ey += ySpeed;


	e_position3 = { ex,ey };


		Font2->SetPosition(e_position3);
	Font3->SetPosition(e_position4);

	Font2->SetScale(3.0f);
	Font3->SetScale(3.0f);

	Font2->SetColor({ 1.0f,1.0f,0.0f });
	Font3->SetColor({ 0.6f,0.2f,1.0f });



	//	Font4->SetPosition(e_position5);
	//Font5->SetPosition(e_position6);
	//	Font6->SetPosition(e_position7);
	//Font7->SetPosition(e_position8);
	//Font8->SetPosition(e_position9);
}