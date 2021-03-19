#pragma once

class CEffect : public CUnit
{

public:
	CEffect();
	~CEffect();

	int effectmove;
	int index;

	virtual void Update();
	virtual void Move();
	virtual void Clipping();
	void Death();
	void form();
	void EffectDraw(int x,int y);


private:

};      