#pragma once
class FontMove :  public  IGameObject
{
public:
	FontMove();
	~FontMove();

bool Start();


void Update();



CVector2 m_position = { 0, 0 };





float x = 0;
float y = 60;
float yT = 0;
float ySpeed = 0.0f;

float Newton = -0.5f;

int getcount = 0;
int getcount2 = 0;







};




