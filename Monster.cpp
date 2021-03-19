#include "Include.h"

CMonster::CMonster()
{
	x = 0;
	y = 0;
	body = '0';
	speed = 1;
	attack = 1;
	hp = 10;
	IsActive = false;
	fColor = RED;
	bColor = BLACK;
	moveTime = GetTickCount64();

	srand(time(NULL));
}

CMonster::~CMonster()
{

}

void CMonster::Update()
{
	MonsterCreate();
	Move();
	//MonsterCollision();
	Clipping();
}

void CMonster::Move()
{
	if (IsActive && moveTime < GetTickCount64())
	{
		y += speed;
		moveTime = GetTickCount64() + 200;
	}
}
void CMonster::Clipping()
{
	if (IsActive && y > 28)
	{
		Death();
	}
}

DWORD MonsterDelay = GetTickCount64();

void CMonster::MonsterCreate()
{
	if (IsActive == false && MonsterDelay < GetTickCount64())
	{
		x = rand() % 118 + 1;
		y = 5;
		IsActive = true;
		MonsterDelay = GetTickCount64() + 500;
	}
}

void CMonster::Death()
{
	x = 9999;
	y = 9999;
	IsActive = false;
}
