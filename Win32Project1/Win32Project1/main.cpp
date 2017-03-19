//#include <time.h>
//#include "MT.h"
//#include "main.h"
//#include "define.h"
//#include "DxLib.h"
#include "dxlib\DxLib.h"

void Game()
{

}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	DxLib_Init();	// DXライブラリ初期化処理
	WaitKey();	// キー入力待ち
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}