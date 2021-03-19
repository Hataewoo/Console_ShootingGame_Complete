#pragma once

class CMonster : public CUnit
{
public:
	CMonster();
	~CMonster();

	DWORD moveTime;

	void Update();
	void Move();
	void Clipping();
	void MonsterCreate();
	void Death();


private:

};