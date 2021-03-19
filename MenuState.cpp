#include "Include.h"
CMenuState::CMenuState()
{

}
CMenuState::~CMenuState()
{

}

int mode;
bool KeyPressed = false;
void CMenuState::Draw()
{
	for (int i = 0; i < Height; i++)
		for(int j = 0; j < Width; j++)
			if(MenuUI[i][j] == 2)
				DrawFillBoxEx3(j, i, 1, 1, LIGHTGRAY);


	//DrawStrEx3(0, 0, "Menu State", WHITE, BLACK);
	DrawStrEx3(22, 4, "Start Game", WHITE, BLACK);
	DrawStrEx3(22, 7, "How To Play?", WHITE, BLACK);
	DrawStrEx3(22, 10, "Shop", WHITE, BLACK);
	DrawStrEx3(22, 13, "Exit", WHITE, BLACK);
	//위아래 키 눌렀을때
	if (!KeyPressed)
	{
		if (IsKey(VK_UP))
		{
			KeyPressed = true;
			mode--;
			if (mode < 0)
			{
				mode = 0;
			}
		}

		if (IsKey(VK_DOWN))
		{
			KeyPressed = true;
			mode++;
			if (mode > 3)
			{
				mode = 3;
			}
		}
	}
	else if (!IsKey(VK_UP) && !IsKey(VK_DOWN) && KeyPressed)
	{
		KeyPressed = false;
	}

	switch (mode)
	{
	case 0: DrawStrEx3(22, 4, "> Start Game", WHITE, BLACK);
			DrawStrEx3(46, 4, "Are you Ready?", WHITE, BLACK);
			DrawStrEx3(46, 5, "Kill all the Monster!", WHITE, BLACK);
			DrawStrEx3(46, 6, "Press Enter Key to Start", WHITE, BLACK);
			DrawStrEx3(80, 24, "I want Jaejin Hwang to die", RED, BLACK);				
		break;
	case 1: DrawStrEx3(22, 7, "> How To Play?", WHITE, BLACK);
			DrawStrEx3(46, 4, "Press the Arrow Key to move", WHITE, BLACK);
			DrawStrEx3(46, 5, "Press the Space to shoot", WHITE, BLACK);
		break;
	case 2: DrawStrEx3(22, 10, "> Shop", WHITE, BLACK);
			DrawStrEx3(46, 4, "Nothing ^^", WHITE, BLACK);
		break;
	case 3: DrawStrEx3(22, 13, "> Exit", WHITE, BLACK);
			DrawStrEx3(46, 4, "End of Game", WHITE, BLACK);
			DrawStrEx3(46, 5, "Press Enter Key to End", WHITE, BLACK);
		break;
	default: //
		break;
	}
}
void CMenuState::Exit()
{

}
void CMenuState::Start()
{

}
void CMenuState::Update()
{
	if (IsKey(VK_RETURN) && mode == 0)
	{
		stateCtrl.StateChange(E_GAME);
	}
	if (IsKey(VK_RETURN) && mode == 3)
	{
		exit(0);//system("taskkill /F /im console.exe");
	}
}