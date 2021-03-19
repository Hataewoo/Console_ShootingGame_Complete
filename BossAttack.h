#pragma once

class CBossAttack : public CUnit
{

public:
	CBossAttack();
	~CBossAttack();

	virtual void Update();
	virtual void Move();
	virtual void Clipping();
	void BossBulletCreate();
	void Death();

private:

};