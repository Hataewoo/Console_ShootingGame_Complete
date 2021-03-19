#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <crtdbg.h>
#include "../ConsoleEx3/ConWrap.h"
#include "Define.h"
#include "mmsystem.h"
//------------------------------------
#include "State.h"
#include "StateCtrl.h"

#define Max 30
#define Width 120
#define Height 30

#include <time.h>
//#include <stdlib.h>
#include "Unit.h"
#include "Hero.h"
#include "Bullet.h"
#include "Monster.h"
#include "Effect.h"
#include "Boss.h"
#include "BossAttack.h"
#include "BossAttack2.h"
#include "item.h"
#include "CSound.h"

#include "LogoState.h"
#include "MenuState.h"
#include "GameState.h"

#include "Extern.h"

extern int BulletCount;
extern char effect[3][3][3];
#endif