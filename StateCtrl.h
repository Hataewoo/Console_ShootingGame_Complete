#pragma once
class CStateCtrl
{
public:
	CState* m_pCurState;			// 현재 state
	CState* m_pPrevState;			// 전 state

	CState* m_pStates[E_SCENE_MAX];	//모든 스테이트들
public:
	CStateCtrl();
	~CStateCtrl();
public:
	void Init();
	bool StateAdd(int nIndex, CState* pState);
	bool StateRelease(int nIndex);
	bool StateChange(int nIndex);
public:
	void Update();
	void Draw();
};