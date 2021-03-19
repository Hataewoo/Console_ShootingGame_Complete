#include "Include.h"

CUnit::CUnit()
{
	x = 0;
	y = 0;
	body = ' ';
	hp = 3;
	attack = 1;
	speed = 1;
	IsActive = false;

	fColor = WHITE;
	bColor = BLACK;
}

CUnit::~CUnit()
{

}

void CUnit::Draw()
{
	if (IsActive)
	{
		DrawCharEx3(x, y, body, fColor, bColor);
	}
}