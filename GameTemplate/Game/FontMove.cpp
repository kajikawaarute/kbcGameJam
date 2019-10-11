#include "stdafx.h"
#include "FontMove.h"


FontMove::FontMove()
{
}


FontMove::~FontMove()
{
}


bool FontMove::Start() {


	return true;


}



void FontMove:: Update()
	{
		



		if (getcount == 0 && y > -320) {
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


			x += 10;

		}


		y += ySpeed;

		m_position = { x,y };

		


	}

	