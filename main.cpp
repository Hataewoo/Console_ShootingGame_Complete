#include "Include.h"

// �밡���� ǥ���
// int    n�̸�
// char   c�̸�
// bool   b�̸�	
// DWORD  dw�̸�
// short  s�̸�
// long   l�̸�
// ����ü �ɹ������� 
// int m_n�̸�
// char  m_c�̸�
// �۷ι� g_?�̸�
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
	InitialConsole();//�ʱ�ȭ�Լ�
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
