#pragma once

class CState
{
public:
	int			m_nStateIndex;		// 현재 State 인덱스
	//CState*		m_pCurState;		// 현재 State 포인터(자기자신)

public:
	CState();
	~CState();

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Exit() = 0;

};