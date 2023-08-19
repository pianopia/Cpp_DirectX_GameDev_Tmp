#include "DxLib.h"
#include "fps.h"
#include "music.h"

#define GameWidth	1920
#define GameHeight	1080
#define GameColor	32
#define GameVSync	TRUE
#define GameIcon	555

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationSystemLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(GameWidth, GameHeight, GameColor);
	SetWindowSize(GameWidth, GameHeight);
	SetWindowText("Wings");
	// SetBackgroundColor(255, 0, 0);
	SetWaitVSyncFlag(GameVSync);
	SetAlwaysRunFlag(FALSE);
	SetWindowIconID(GameIcon);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	if (Music_Init() == FALSE)
	{
		return -1;
	}


	SetDrawScreen(DX_SCREEN_BACK);

	FPSInit();

	int x = 0;
	int FontHandle;
	FontHandle = CreateFontToHandle("ＭＳ 明朝", 80, 5, DX_FONTTYPE_NORMAL);

	PlayMusic(TitleBGM);

	// メインループ
	while (TRUE)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}

		if (ClearDrawScreen() != 0)
		{
			break;
		}

		{
			FPSCheck();
			
			//DrawString(800, 600, "Hello, World", GetColor(255,255,255));

			int gh = LoadGraph("star.png");
			DrawGraph(x, 0, gh, TRUE);
			DrawGraph(x + 20, 100, gh, TRUE);
			DrawGraph(x + 40, 200, gh, TRUE);
			DrawGraph(x + 60, 300, gh, TRUE);
			DrawGraph(x + 80, 400, gh, TRUE);
			DrawGraph(x + 100, 500, gh, TRUE);
			x += 10;
			if (x > 1980)
			{
				x = 0;
			}

			//DrawString(940, 150, "Wings", GetColor(255, 255, 255));
			DrawFormatStringToHandle(830, 200, GetColor(255, 255, 255), FontHandle, "Wings");

		
			FPSDraw();
			FPSWait();
		}
	
		ScreenFlip();
	}

	

	//WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
