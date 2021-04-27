//ヘッダーの読み込み
#include "DxLib.h"   //Dxlibを使う時は必要

#define GAME_TITLE "ゲームタイトル"
#define GAME_WIDTH 1280
#define GAME_HIGHT 720
#define GAME_COLOR 32
#define GAME_ICON_ID   333

// プログラムは WinMain から始まります
int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetMainWindowText(GAME_TITLE);
	SetGraphMode(GAME_WIDTH, GAME_HIGHT, GAME_COLOR);
	SetWindowSize(GAME_WIDTH, GAME_HIGHT);
	SetBackgroundColor(255, 255, 255);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
		//無限ループ
	}
	while (1)
	{
		if (CheckHitKeyAll() == 0)
		{
			break;
		}
		if (ProcessMessage() != 0)
		{
			break;
		}
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
