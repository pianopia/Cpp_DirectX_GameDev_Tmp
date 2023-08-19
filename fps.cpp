#include <string>
#include "fps.h"

FPS fps;

VOID FPSInit(VOID)
{
	fps.FirstTakeTime = GetNowHiPerformanceCount();

	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.Deltatime = 0.000001f;
	fps.FrameCount = 1;
	fps.Average = 0.0f;

	return;
}

VOID FPSCheck(VOID)
{
	fps.NowTakeTime = GetNowHiPerformanceCount();

	// デルタタイムを計算
	fps.Deltatime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;

	// 現在の時刻を保存
	fps.OldTakeTime = fps.NowTakeTime;

	if (fps.FrameCount == GameFPS)
	{
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		float CalcAverage = TotalFrameTime / GameFPS;

		fps.Average = MicroSecond / CalcAverage;

		fps.FirstTakeTime = GetNowHiPerformanceCount();
		
		fps.FrameCount = 1;
	}
	else
	{
		fps.FrameCount++;
		DrawFormatString(300, 0, GetColor(255, 255, 255), "Frame: %d", fps.FrameCount);
	}

	return;
}

VOID FPSDraw(VOID)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%3.1f", fps.Average);

	return;
}

VOID FPSWait(VOID)
{
	int wait = 0;

	wait = MicroSecond / GameFPS * fps.FrameCount - (fps.NowTakeTime - fps.FirstTakeTime);

	wait /= MillSecond;

	if (wait > 0 && wait < WaitTimeMill)
	{
		WaitTimer(wait);
	}

	return;
}