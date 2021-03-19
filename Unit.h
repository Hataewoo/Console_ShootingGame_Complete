#pragma once

class CUnit
{
public:
	CUnit();
	~CUnit();

	int x;
	int y;
	char body;
	int hp;
	int attack;
	int speed;
	bool IsActive;

	DWORD fColor;
	DWORD bColor;

	virtual void Update() = 0;
	virtual void Draw();
	virtual void Move() = 0;
	virtual void Clipping() = 0;

private:

};