#include "Include.h"

CBullet::CBullet()
{
	x = -9999;
	y = -9999;
	body = '^';
	speed = 1;
	attack = 1;
	hp = 100;
	IsActive = false;
	fColor = WHITE;
	bColor = BLACK;
}

CBullet::~CBullet()
{

}

void CBullet::Update()
{
	//BulletCreate();
	Move();
	Clipping();
}

void CBullet::Move()
{
	if (IsActive)
	{
		y -= speed;
	}
}

void CBullet::Clipping()
{
	if (IsActive && y < 5)
	{
		Death();
	}

}

void CBullet::Death()
{
	x = -9999;
	y = -9999;
	IsActive = false;
}

DWORD BulletTimer = GetTickCount64(); 
DWORD BulletReload = GetTickCount64();

void CBullet::BulletCreate(int posx, int posy)
{
	DrawStrEx3(51, 1, "Bullets: ", WHITE, BLACK);
	//장전
	for (int i = 0; i < BulletCount - 1; i++)
	{
		DrawCharEx3(60 + i % 10, 1 + (int)i / 10, '0', YELLOW, BLACK);
	}
	if (BulletReload < GetTickCount64() && BulletCount == 0)
	{
		BulletCount = 29;
	}
	//발사
	if (IsKey(VK_SPACE))
	{
		if (IsActive == false && BulletCount != 0 && BulletTimer < GetTickCount64())
		{
			x = posx;
			y = posy;
			IsActive = true;
			BulletCount--;
			BulletTimer = GetTickCount64() + 50;
			if (BulletCount == 0)
			{
				BulletReload = GetTickCount64() + 3950;
			}
		}
	}
}