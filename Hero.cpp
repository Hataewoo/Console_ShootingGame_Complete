#include "Include.h"

CHero::CHero()
{
	x = 59;
	y = 29;
	body = 'A';
	speed = 1;
	attack = 10;
	hp = 4;
	IsActive = true;
	fColor = WHITE;
	bColor = BLACK;
}
CHero::~CHero()
{

}

void CHero::Update()
{
	Move();
	Clipping();

}
void CHero::Move()
{
	if (IsKey(VK_UP))
	{
		y -= speed;
	}

	if (IsKey(VK_LEFT))
	{
		x -= speed;
	}

	if (IsKey(VK_DOWN))
	{
		y += speed;
	}

	if (IsKey(VK_RIGHT))
	{
		x += speed;
	}
}
void CHero::Clipping()
{
	if (y > 28)
		y = 28;
	if (y < 5)
		y = 5;
	if (x > 118)
		x = 118;
	if (x < 1)
		x = 1;
}

void CHero::Death()
{
	IsActive = false;
	x = 8945;
	y = -8945;
}



