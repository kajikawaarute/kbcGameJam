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
	if (m_timer >= 60.0f) {
		m_timer = 0;  //�^�C�}�[�����Z�b�g
		//60�t���[�����ƂɃS�~�𐶐�����B
		//X���W�������_���ɂ���B
		//Y���W�������_���ɂ���B
	}
}
