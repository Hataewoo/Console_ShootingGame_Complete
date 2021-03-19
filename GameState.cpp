#include "Include.h"

CGameState::CGameState()
{

}
CGameState::~CGameState()
{

}

void CGameState::Draw()
{
	//DrawStrEx3(0, 0, "Game State", WHITE, BLACK);
	m_Hero.Draw();
	for (int i = 0; i < Max; i++)
	{
		m_Bullet[i].Draw();
		m_Monster[i].Draw();
		m_Item[i].Draw();
		m_BossAttack[i].Draw();
		m_BossAttack2[i].Draw();
	}

	//UI
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++)
			if (GameUI[i][j] == 1)
				DrawFillBoxEx3(j, i, 1, 1, LIGHTCYAN);

	//시간(점수)
	if (Playtime < GetTickCount64())
	{
		timeScore++;
		Playtime = GetTickCount64() + 1000;
	}
	sprintf(time, "Time : %d", timeScore);
	DrawStrEx3(3, 2, time, LIGHTGREEN, BLACK);

	//체력
	DrawStrEx3(100, 2, "PlayerHp: ", RED, BLACK);
	for (int i = 0; i < m_Hero.hp; i++)
	{
		DrawFillBoxEx3(i * 2 + 110, 2, 1, 1, RED);
	};
	//보스체력
	if (timeScore > 15)
	{
		for (int i = 0; i < m_Boss.hp; i++)
		{
			DrawFillBoxEx3(i + 1, 5, 1, 1, RED);
		};
	}
	//캐릭터 죽으면 실행
	HeroDieUI();
	HeroWinUI();
}

void CGameState::Update()
{
	/*if (IsKey(VK_F1))
	{
		stateCtrl.StateChange(E_LOGO);
	}*/
	m_Hero.Update();
	if (timeScore == 15)
		m_Boss.IsActive = true;
	for (int i = 0; i < Max; i++)
	{	
		m_Bullet[i].Update();
		m_Effect[i].Update();
		if (m_Hero.IsActive)
			m_Bullet[i].BulletCreate(m_Hero.x, m_Hero.y);
		if (m_Boss.IsActive)
		{
			m_Item[i].IsActive = false;
			m_Monster[i].IsActive = false;
			m_BossAttack[i].Update();
			m_BossAttack2[i].Update();
		}
		else
			m_BossAttack[i].IsActive = false;
			m_Item[i].Update();
			m_Monster[i].Update();
	}

	//몬스터와 총알 충돌처리
	for (int j = 0; j < Max; j++) // 몬스터
		for (int k = 0; k < Max; k++) // 총알
			MonsterBulletCollision(&m_Bullet[k], &m_Monster[j]);
	//캐릭터와 몬스터 충돌처리
	//캐릭터와 보스몬스터의 충동처리
	for (int i = 0; i < Max; i++)
	{
		MonsterPlayerCollision(&m_Monster[i], &m_Hero);
		ItemPlayerCollision(&m_Item[i], &m_Hero);
		BossAttackPlayCollision(&m_BossAttack[i], &m_Hero);
		BossPlayerbulletCollision(&m_Boss, &m_Bullet[i]);//보스와 총알 충돌 처리
		BossAttack2PlayCollision(&m_BossAttack2[i], &m_Hero);
	}
	if (m_Boss.IsActive)
	{
		m_Boss.Update();
		//캐릭터가 보스에게 접근 금지
		if (m_Hero.y < 15)
		{
			m_Hero.y = 15;
		}
	}
}

void CGameState::Exit()
{

}

//모든 충돌함수
void CGameState::MonsterBulletCollision(CBullet* _bullet, CMonster* _monster)
{
	if (_bullet->x == _monster->x && _bullet->y <= _monster->y
		&& _bullet->IsActive && _monster->IsActive)
	{
		for (int a = 0; a < Max; a++) // 이펙트
		{
			if (!m_Effect[a].IsActive)
			{
				m_Effect[a].EffectDraw(_monster->x, _monster->y);
				m_Effect[a].IsActive = true;
				break;
			}
		}
		_bullet->Death();
		_monster->Death();
	}
}

void CGameState::MonsterPlayerCollision(CMonster* _Monster, CHero* _Hero)
{
	if (_Monster->x == _Hero->x && _Monster->y >= _Hero->y && _Monster->y <= _Hero->y + 1
		&& _Monster->IsActive && _Hero->IsActive)
	{
		_Monster->Death();
		_Hero->hp -= _Monster->attack;
		if (_Hero->hp == 0)
		{
			_Hero->Death();
		}
	}
}

void CGameState::ItemPlayerCollision(CItem* _Item, CHero* _Hero)
{
	if (_Item->x == _Hero->x && _Item->y >= _Hero->y && _Item->y <= _Hero->y + 1
		&& _Item->IsActive && _Hero->IsActive)
	{
		_Item->Death();
		if (_Hero->hp < 4)
		{
			_Hero->hp += _Item->attack;
		}
	}
}

void CGameState::BossAttackPlayCollision(CBossAttack* _BossAttack, CHero* _Hero)
{
	if (_BossAttack->x == _Hero->x && _BossAttack->y >= _Hero->y && _BossAttack->y <= _Hero->y + 1
		&& _BossAttack->IsActive && _Hero->IsActive)
	{
		_BossAttack->Death();
		_Hero->hp -= _BossAttack->attack;
		if (_Hero->hp <= 0)
		{
			_Hero->Death();
		}
	}
}

void CGameState::BossPlayerbulletCollision(CBoss* _Boss, CBullet* _bullet)
{
	if (_bullet->x == _Boss->x && _bullet->y <= _Boss->y
		&& _bullet->IsActive && _Boss->IsActive)
	{
		for (int a = 0; a < Max; a++) // 이펙트
		{
			if (!m_Effect[a].IsActive)
			{
				m_Effect[a].EffectDraw(_Boss->x, _Boss->y);
				m_Effect[a].IsActive = true;
				break;
			}
		}
		_bullet->Death();
		_Boss->hp -= _bullet->attack;
		//피격효과
		_Boss->DamagedEffect();
			_Boss->Death();
	}
}

void CGameState::BossAttack2PlayCollision(CBossAttack2* _BossAttack2, CHero* _Hero)
{
	if (_BossAttack2->y == _Hero->y && _BossAttack2->x >= _Hero->x && _BossAttack2->x <= _Hero->x + 1
		&& _BossAttack2->IsActive && _Hero->IsActive)
	{
		_BossAttack2->Death();
		_Hero->hp -= _BossAttack2->attack;
		if (_Hero->hp <= 0)
		{
			_Hero->Death();
		}
	}
}


void CGameState::HeroDieUI()
{
	if (m_Hero.hp <= 0)
	{
		timeScore = 0;
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Width; j++)
			{
				if (DieUI[i][j] == 1)
					DrawFillBoxEx3(j, i, 1, 1, RED);
				else if (DieUI[i][j] == 0)
					DrawFillBoxEx3(j, i, 1, 1, BLACK);
			}

		DrawStrEx3(55,25,"R : Restart",WHITE,BLACK);
		if (IsKey(VK_R))
		{
			for (int i = 0; i < Max; i++)
			{
				m_Bullet[i].x = -9999;
				m_Bullet[i].y = -9999;
				m_Bullet[i].IsActive = false;
				m_Monster[i].IsActive = false;
				m_BossAttack[i].IsActive = false;
				m_BossAttack2[i].IsActive = false;
			}
			m_Hero.x = 59;
			m_Hero.y = 29;
			timeScore = 0;
			m_Hero.hp = 4;
			m_Boss.hp = 100;
			BulletCount = 30;
			m_Hero.IsActive = true;
			m_Boss.IsActive = false;
		}
	}
}

void CGameState::HeroWinUI()
{
	if (m_Boss.hp <= 0)
	{
		timeScore = 0;
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Width; j++)
			{
				if (winUI[i][j] == 1)
					DrawFillBoxEx3(j, i, 1, 1, YELLOW);
				else if (winUI[i][j] == 0)
					DrawFillBoxEx3(j, i, 1, 1, BLACK);
			}

		DrawStrEx3(55, 25, "X : Go to Logo", WHITE, BLACK);
		if (IsKey(VK_X))
		{
			for (int i = 0; i < Max; i++)
			{
				m_Bullet[i].x = 9999;
				m_Bullet[i].y = -9999;
				m_Bullet[i].IsActive = false;
				m_Monster[i].IsActive = false;
				m_BossAttack[i].IsActive = false;
				m_BossAttack2[i].IsActive = false;
			}
			m_Hero.x = 59;
			m_Hero.y = 29;
			timeScore = 0;
			m_Hero.hp = 4;
			m_Boss.hp = 100;
			BulletCount = 30;
			m_Hero.IsActive = true;
			m_Boss.IsActive = false;
			stateCtrl.StateChange(E_LOGO);
		}
	}
}


void CGameState::Start()
{
}