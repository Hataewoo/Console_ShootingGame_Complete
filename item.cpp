#include "Include.h"

CItem::CItem()
{
	x = 0;
	y = 0;
	body = '+';
	speed = 1;
	attack = 1;
	hp = 10;
	IsActive = false;
	fColor = WHITE;
	bColor = RED;
	moveTime = GetTickCount64();
}

CItem::~CItem()
{

}

void CItem::Update()
{
	ItemCreate();
	Move();
	Clipping();
}

void CItem::Move()
{
	if (IsActive && moveTime < GetTickCount64())
	{
		y += speed;
		moveTime = GetTickCount64() + 50;
	}
}
void CItem::Clipping()
{
	if (IsActive && y > 28)
	{
		Death();
	}
}

DWORD ItemDelay = GetTickCount64() + 5000;

void CItem::ItemCreate()
{
	if (IsActive == false && ItemDelay < GetTickCount64())
	{
		x = rand() % 118 + 1;
		y = 5;
		IsActive = true;
		ItemDelay = GetTickCount64() + 10000;
	}
}

void CItem::Death()
{
	x = 9999;
	y = -9599;
	IsActive = false;
}
