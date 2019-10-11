#include "stdafx.h"
#include "GabageGenerator.h"
#include "GabageBotol.h"
#include "GarbagePaper.h"

GabageGenerator::GabageGenerator()
{
}
GabageGenerator::~GabageGenerator()
{
}

void GabageGenerator::Update()
{
	m_timer+= GameTime().GetFrameDeltaTime();
	if (m_timer >= 3.0f) {
		
		//60�t���[�����ƂɃS�~�𐶐�����B
		GabageBotol* botol = NewGO<GabageBotol>(0, "Botol");
		//X���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float botolS = Random().GetRandDouble();
		botol->m_position.x = CMath::Lerp(botolS, -2000.0f, 2000.0f);
		//Z���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float botolT = Random().GetRandDouble();
		//CMath::Leap�֐��͓�̒l�̊Ԃ���`�⊮����
		botol->m_position.z = CMath::Lerp(botolT, -3000.0f, 3000.0f);
		botol->m_position.y = 5.0f;
		botol->m_scale = { 5.0f,5.0f,5.0f };

		GarbagePaper* paper = NewGO<GarbagePaper>(0, "Paper");
		//X���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float PaperS = Random().GetRandDouble();
		paper->m_position.x = CMath::Lerp(PaperS, -2000.0f, 2000.0f);
		//Z���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float PaperT = Random().GetRandDouble();
		//CMath::Leap�֐��͓�̒l�̊Ԃ���`�⊮����֐��B
		paper->m_position.z = CMath::Lerp(PaperT, -2800.0f, 2800.0f);
		paper->m_position.y = 20.0f;
		paper->m_scale = { 5.0f,5.0f,5.0f };


		GarbagePaper* paper2 = NewGO<GarbagePaper>(0, "Paper2");
		//X���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float Paper2S = Random().GetRandDouble();
		paper2->m_position.x = CMath::Lerp(Paper2S, -3800.0f, -10.0f);
		//Z���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float Paper2T = Random().GetRandDouble();
		//CMath::Leap�֐��͓�̒l�̊Ԃ���`�⊮����֐��B
		paper2->m_position.z = CMath::Lerp(Paper2T, 1600.0f, 3800.0f);
		paper2->m_position.y = 330.0f;
		paper2->m_scale = { 5.0f,5.0f,5.0f };
		m_timer = 0;  //�^�C�}�[�����Z�b�g
	}
}
