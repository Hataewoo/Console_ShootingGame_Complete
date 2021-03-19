#include "Include.h"

CBossAttack::CBossAttack()
{
	x = 2345;
	y = -234;
	attack = 2;
	speed = 1;
	IsActive = false;
	body = '+';

	fColor = MAGENTA;
	bColor = BLACK;
}

CBossAttack::~CBossAttack()
{

}

void CBossAttack::Update()
{
	BossBulletCreate();
	Move();
	Clipping();
}

void CBossAttack::Move()
{
	if (IsActive)
	{
		y += speed;
	}
}

void CBossAttack::Clipping()
{
	if (y > 29)
	{
		Death();
	}
}

DWORD BossBulletDelay = GetTickCount64();

void CBossAttack::BossBulletCreate()
{
	if (IsActive == false &&  BossBulletDelay < GetTickCount64())
	{
		x = rand() % 118 + 1;
		y = 5;
		IsActive = true;
		BossBulletDelay = GetTickCount64() + 100;
	}
}

void CBossAttack::Death()
{
	if (IsActive)
	{
		IsActive = false;
		x = 897;
		y = -7892;
	}
}

