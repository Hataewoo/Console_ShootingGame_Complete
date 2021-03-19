#include "Include.h"

CBossAttack2::CBossAttack2()
{
	x = -2345;
	y = 234;
	attack = 1;
	speed = 1;
	IsActive = false;
	body = '+';

	Arrow = false;

	fColor = RED;
	bColor = BLACK;
}

CBossAttack2::~CBossAttack2()
{

}

void CBossAttack2::Update()
{
	BossLaserCreate();
	Move();
	Clipping();
}

void CBossAttack2::Move()
{
	if (IsActive && Arrow)
	{
		x += speed;
	}
	else if (IsActive && !Arrow)
	{
		x -= speed;
	}
}

void CBossAttack2::Clipping()
{
	if (x > 119)
	{
		Death();
	}
	else if (x < 0)
	{
		Death();
	}
}

DWORD BossLaserDelay = GetTickCount64();

void CBossAttack2::BossLaserCreate()
{
	if (IsActive == false && BossLaserDelay < GetTickCount64())
	{
		if (rand() % 2)
		{
			x = 119;
			Arrow = false;
		}
		else
		{
			x = 0;
			Arrow = true;
		}

		y = rand() % 15 + 15 ;
		IsActive = true;
		BossLaserDelay = GetTickCount64() + 150;
	}
}

void CBossAttack2::Death()
{
	if (IsActive)
	{
		IsActive = false;
		x = -897;
		y = 7892;
	}
}
