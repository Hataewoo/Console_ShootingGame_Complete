#include "Include.h"
CLogoState::CLogoState()
{

}
CLogoState::~CLogoState()
{

}
int x;
int y;
DWORD Blink = GetTickCount64();
bool ChangeColor = false;
void CLogoState::Draw()
{
	if (IsAnyKey() && UI < 3600)
	{
		UI = 3600;
	}
	//DrawStrEx3(0, 0, "Logo State", WHITE, BLACK);
	for (int i = 0; i < UI; i++)
	{
		y = i % 30;
		x = i / 30;
		if (LogoUI[y][x] == 0)
		{
			for (int i = UI; i < 3600; i++)
			{
				y = i % 30;
				x = i / 30;
				if (LogoUI[y][x] != 0)
				{
					break;
				}
				UI++;
			}
		}
		if (LogoUI[y][x] == 1)
			DrawFillBoxEx3(x, y, 1, 1, DARKGRAY);
		else if (LogoUI[y][x] == 2)
			DrawFillBoxEx3(x, y, 1, 1, RED);
		else if (LogoUI[y][x] == 3)
			DrawFillBoxEx3(x, y, 1, 1, YELLOW);
		else if (LogoUI[y][x] == 4)
			DrawFillBoxEx3(x, y, 1, 1, LIGHTGRAY);
		else if (LogoUI[y][x] == 5)
			DrawFillBoxEx3(x, y, 1, 1, BLUE);
		else if (LogoUI[y][x] == 6)
			DrawFillBoxEx3(x, y, 1, 1, RED);
		else if (LogoUI[y][x] == 7)
			DrawFillBoxEx3(x, y, 1, 1, LIGHTRED);
		else if (LogoUI[y][x] == 8)
			DrawFillBoxEx3(x, y, 1, 1, GREEN);
		else if (LogoUI[y][x] == 9)
			DrawFillBoxEx3(x, y, 1, 1, LIGHTGREEN);
	}
	if (UI < 3600)
	{
		UI++;
	}
	else
	{
		if (ChangeColor)
		{
			DrawStrEx3(50, 22, "Press Space to Start", BLACK, BLACK);
		}
		else if (!ChangeColor)
		{
			DrawStrEx3(50, 22, "Press Space to Start", YELLOW, BLACK);
		}
		if (Blink < GetTickCount64())
		{
			if (ChangeColor)
				Blink = GetTickCount64() + 1000;
			else
				Blink = GetTickCount64() + 250;
			ChangeColor = !ChangeColor;
		}
	}
}
void CLogoState::Update()
{
	if (IsKey(VK_SPACE) && UI >= 3600)
	{
		UI = 0;
		stateCtrl.StateChange(E_MENU);
	} 
}

void CLogoState::Exit()
{

}

void CLogoState::Start()
{

}