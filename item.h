#pragma once

class CItem : public CUnit
{
public:
	CItem();
	~CItem();

	DWORD moveTime;

	void Update();
	void Move();
	void Clipping();
	void ItemCreate();
	void Death();


private:

};