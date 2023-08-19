#pragma once

#include "DxLib.h"

#define GameFPS					60

#define MicroSecond		1000000.0f
#define MillSecond		1000.0f
#define WaitTimeMill		  3000

typedef struct _FPS
{
	LONGLONG FirstTakeTime = 0;
	LONGLONG NowTakeTime = 0;
	LONGLONG OldTakeTime = 0;

	float Deltatime = 0.000001f;
	int FrameCount = 1;
	float Average = 0.0f;
}FPS;

extern FPS fps;


extern VOID FPSInit(VOID);	// èâä˙âª
extern VOID FPSCheck(VOID); // åvë™
extern VOID FPSDraw(VOID);	// ï`âÊ
extern VOID FPSWait(VOID);	// ë“ã@