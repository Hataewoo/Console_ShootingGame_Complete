#include "Include.h"

CEffect::CEffect()
{
	x = -1000;
	y = -1000;
	body = '*';
	effectmove = GetTickCount64();
	IsActive = false;
	index = 0;

	fColor = LIGHTMAGENTA;
	bColor = BLACK;
}

CEffect::~CEffect()
{
}

void CEffect::form()
{
	if (!IsActive) return;

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			DrawCharEx3(x + i - 1, y + j - 1, effect[index][j][i], fColor, bColor);

	if (effectmove < GetTickCount())
	{
		effectmove = GetTickCount() + 100;
		index++;
	}

	if (index > 2) Death();
}


void CEffect::EffectDraw(int _x,int _y)
{
	effectmove = GetTickCount() + 100;
	index = 0;
	IsActive = true;
	x = _x;
	y = _y;
}

void CEffect::Update()
{
	form();
}

void CEffect::Move()
{

}


void CEffect::Clipping()
{

}

void CEffect::Death()
{
	index = 0;
	x = -9999;
	y = 9999;
	IsActive = false;
}
