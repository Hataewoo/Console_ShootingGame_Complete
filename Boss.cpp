#include "Include.h"


CBoss::CBoss()
{
	x = 2345;
	y = 234;
	hp = 100;
	attack = 1;
	speed = 1;
	IsActive = false;

	fColor = RED;
	bColor = BLACK;
}

CBoss::~CBoss()
{
}

void CBoss::Update()
{
	Create();
	Death();
}

void CBoss::Clipping()
{
	
}

void CBoss::Move()
{

}

void CBoss::Create()
{
	if (IsActive)
	{
		x = 60;
		y = 14;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				if (BossUI[i][j] == 1)
					DrawFillBoxEx3(j + 50, i + 5, 1, 1, LIGHTMAGENTA);
				if (BossUI[i][j] == 2)
					DrawFillBoxEx3(j + 50, i + 5, 1, 1, RED);
			}
		}
	}
}

void CBoss::Death()
{
	if (hp < 0)
	{
		IsActive = false;
		x = 4321;
		y = -4321;
	}
}

void CBoss::DamagedEffect()
{
	if (IsActive)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				if (BossUI[i][j] == 1 || BossUI[i][j] == 2)
					DrawFillBoxEx3(j + 50, i + 5, 1, 1, BLACK);
			}
		}
	}
}
