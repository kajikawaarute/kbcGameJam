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
		m_timer = 0;  //タイマーをリセット
		//60フレームごとにゴミを生成する。
		//X座標をランダムにする。
		//Y座標をランダムにする。
	}
}
