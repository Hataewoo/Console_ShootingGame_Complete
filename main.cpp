#include "Include.h"

// 헝가리안 표기법
// int    n이름
// char   c이름
// bool   b이름	
// DWORD  dw이름
// short  s이름
// long   l이름
// 구조체 맴버변수는 
// int m_n이름
// char  m_c이름
// 글로벌 g_?이름
// int nVlaue = 0;
// void Quit();

CStateCtrl stateCtrl;

CLogoState logoState;
CMenuState menuState;
CGameState gameState;

char effect[3][3][3] =
{
	{
		{' ',' ',' '},
		{' ','*',' '},
		{' ',' ',' '}
	},
	{
		{' ','*',' '},
		{'*','*','*'},
		{' ','*',' '}
	},
	{
		{'*',' ','*'},
		{' ','*',' '},
		{'*',' ','*'}
	}
};

int BulletCount = 30;

int main()
{
	InitialConsole();//초기화함수
	SetWindowTitle("Shooting");
	CSound::Init();
	CSound* sound = new CSound("bgm.mp3", false);
	sound->play();

	stateCtrl.StateAdd(E_LOGO, &logoState);
	stateCtrl.StateAdd(E_MENU, &menuState);
	stateCtrl.StateAdd(E_GAME, &gameState);

	stateCtrl.StateChange(E_LOGO);

	while (true)
	{
		CheckInput();
		ClearScreenEx3(BLACK);

		stateCtrl.Update();
		stateCtrl.Draw();

		Flip();
		EngineSync(30);
		sound->Update();
	}

	delete sound;
	CSound::Release();

	ReleaseConsole();
	return 0;
}
