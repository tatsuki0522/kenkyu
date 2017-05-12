#include <time.h>
#include "MT.h"
#include "main.h"
#include "define.h"
#include "DxLib.h"
#include "boll.h"
#include "Player.h"
//#include "dxlib\DxLib.h"

int ball_midium_graph;
int ball_small_graph;
int graph_player;
int mx, my;

void Draw(struct Button_t *button)
{
	DrawFormatString(1560, 115, GetColor(255, 255, 255), "Score:");
	DrawFormatString(20, 0, GetColor(255, 255, 255), "x=%d,y=%d", mx, my);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "button=%Xrest=%X", (button->button), button->rest);
	DrawLine(200, 0, 200, 1080, GetColor(255, 255, 255));
	DrawLine(1200, 0, 1200, 1080, GetColor(255, 255, 255));
	DrawRotaGraph(288, 400, 1, 0, ball_midium_graph, 1, 0);
	DrawRotaGraph(200, 200, 1, 0, ball_small_graph, 1, 0);
	DrawRotaGraph(mx, my, 1, 0, graph_player, 1, 0);
}

void Button_rest(int key_state, char *button, char *rest, char type)
{
	*rest &= ~type;
	if (key_state == TRUE) {
		if (!(type & *button)) *rest |= type;
		*button |= type;
	}
	else *button &= ~type;
	
}

void Button(struct Button_t *button)
{
	GetMousePoint(&mx, &my);
	Button_rest(CheckHitKey(KEY_INPUT_UP), &button->button, &button->rest, BUTTON_UP);
	Button_rest(CheckHitKey(KEY_INPUT_RIGHT), &button->button, &button->rest, BUTTON_RIGHT);
	Button_rest(CheckHitKey(KEY_INPUT_DOWN), &button->button, &button->rest, BUTTON_DOWN);
	Button_rest(CheckHitKey(KEY_INPUT_LEFT), &button->button, &button->rest, BUTTON_LEFT);
	Button_rest(CheckHitKey(KEY_INPUT_Z), &button->button, &button->rest, BUTTON_Z);
	Button_rest((CheckHitKey(KEY_INPUT_RSHIFT) | CheckHitKey(KEY_INPUT_LSHIFT)), &button->button, &button->rest, BUTTON_SHIFT);
}

void Game(struct Button_t *button,struct Ball_t *ball,struct Myself_t *mys)
{
	button->button = 0;
	button->rest = 0;
	while (1) {
		ProcessMessage();			//プロセスの連絡
		ClearDrawScreen();			//画面の削除

		Draw(button);				//絵画をすべて処理
		Button(button);				//ボタンの入力状況を取得
		Ball_main(ball);
		Player_main(ball, button,mys);
		if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)break;

		ScreenFlip();				//裏画面を表画面に反映
	}
}

void Load()
{
	ball_midium_graph = LoadGraph(BALL_MIDIUM_GRAPH);
	ball_small_graph = LoadGraph(BALL_SMALL_GRAPH);
	graph_player = LoadGraph(GRAPH_PLAYER);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(FALSE);
	SetGraphMode(1920, 1080, 32);
	DxLib_Init();	// DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面処理
	SetFontSize(40);
	//////変数の定義/////
	struct Mob_t *mob;
	struct Ball_t * balls;
	struct Myself_t *mys;
	struct Button_t *button;
	button = (Button_t *)malloc(sizeof(Button_t)*MAX_BALL);
	mob = (Mob_t *)malloc(sizeof(mob)*MAX_MOB);
	balls = (Ball_t *)malloc(sizeof(Ball_t)*MAX_BALL);
	mys = (Myself_t *)malloc(sizeof(Myself_t));
	////////ファイルの読み込み///////
	Load();
	///////関数への処理渡し//////
	Game(button,balls,mys);
	///////終了命令////////
	free(mob);
	free(balls);
	free(mys);
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}