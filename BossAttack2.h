#pragma once

class CBossAttack2 : public CUnit
{

public:
	CBossAttack2();
	~CBossAttack2();

	bool Arrow;

	virtual void Update();
	virtual void Move();
	virtual void Clipping();
	void BossLaserCreate();
	void Death();

private:

};