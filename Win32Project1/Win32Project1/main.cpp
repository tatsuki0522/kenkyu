#include <time.h>
#include "MT.h"
#include "main.h"
#include "define.h"
#include "DxLib.h"
//#include "dxlib\DxLib.h"

int boll_small_graph;

void Draw()
{
	DrawRotaGraph(200, 200, 1, 0, boll_small_graph, 1, 0);
}

void Game()
{
	while (1) {
		ProcessMessage();	//プロセスの連絡
		ClearDrawScreen();	//画面の削除
		Draw();				//絵画をすべて処理
		ScreenFlip();		//裏画面を表画面に反映
	}
}

void Load()
{
	boll_small_graph = LoadGraph(BOLL_SMALL_GRAPH);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	DxLib_Init();	// DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面処理
	//////変数の定義/////
	struct Mob_t *mob;
	struct Boll_t * bools;
	struct Myself_t *mys;
	mob = (Mob_t *)malloc(sizeof(mob)*MAX_MOB);
	bools = (Boll_t *)malloc(sizeof(Boll_t)*MAX_BALL);
	mys = (Myself_t *)malloc(sizeof(Myself_t));
	////////ファイルの読み込み///////
	Load();
	///////関数への処理渡し//////
	Game();
	///////終了命令////////
	free(mob);
	free(bools);
	free(mys);
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}