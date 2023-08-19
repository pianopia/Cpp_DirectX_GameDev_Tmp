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


extern VOID FPSInit(VOID);	// 初期化
extern VOID FPSCheck(VOID); // 計測
extern VOID FPSDraw(VOID);	// 描画
extern VOID FPSWait(VOID);	// 待機