#pragma once

class CHero : public CUnit
{
public:
	CHero();
	~CHero();

	virtual void Update();
	virtual void Move();
	virtual void Clipping();
	void Death();
	
	

private:

};