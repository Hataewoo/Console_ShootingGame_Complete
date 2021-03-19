#pragma once

class CBullet : public CUnit
{

public:
	CBullet();
	~CBullet();

	virtual void Update();
	virtual void Move();
	virtual void Clipping();
	void Death();
	void BulletCreate(int posx, int posy);

private:

};
