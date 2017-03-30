#include <time.h>
#include "MT.h"
#include "main.h"
#include "define.h"
#include "DxLib.h"
//#include "dxlib\DxLib.h"

int boll_midium_graph;
int boll_small_graph;
int mx, my;

void Draw(struct Button_t *button)
{
	
	DrawFormatString(20, 0, GetColor(255, 255, 255), "x=%d,y=%d", mx, my);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "up=%d,down=%d",button->up,button->down);
	DrawLine(0, 0, 0, 500, GetColor(255, 255, 255));
	DrawLine(380, 0,380, 500, GetColor(255, 255, 255));
	DrawRotaGraph(288, 400, 1, 0, boll_midium_graph, 1, 0);
	DrawRotaGraph(200, 200, 1, 0, boll_small_graph, 1, 0);
}

void Button(struct Button_t *button)
{
	GetMousePoint(&mx, &my);
	if (CheckHitKey(KEY_INPUT_UP) == TRUE)button->up = TRUE;
	else button->up = FALSE;
	if (CheckHitKey(KEY_INPUT_DOWN) == TRUE)button->down = TRUE;
	else button->down = FALSE;
	if (CheckHitKey(KEY_INPUT_RIGHT) == TRUE)button->right = TRUE;
	else button->right = FALSE;
	if (CheckHitKey(KEY_INPUT_LEFT) == TRUE)button->left = TRUE;
	else button->left = TRUE;
}

void Game(struct Button_t *button)
{
	while (1) {
		ProcessMessage();	//�v���Z�X�̘A��
		ClearDrawScreen();	//��ʂ̍폜
		Draw(button);				//�G������ׂď���
		Button(button);
		ScreenFlip();		//����ʂ�\��ʂɔ��f
	}
}

void Load()
{
	boll_midium_graph = LoadGraph(BOLL_MIDIUM_GRAPH);
	boll_small_graph = LoadGraph(BOLL_SMALL_GRAPH);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	DxLib_Init();	// DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);	//����ʏ���
	//////�ϐ��̒�`/////
	struct Mob_t *mob;
	struct Boll_t * bools;
	struct Myself_t *mys;
	struct Button_t *button;
	button = (Button_t *)malloc(sizeof(Button_t)*MAX_BALL);
	mob = (Mob_t *)malloc(sizeof(mob)*MAX_MOB);
	bools = (Boll_t *)malloc(sizeof(Boll_t)*MAX_BALL);
	mys = (Myself_t *)malloc(sizeof(Myself_t));
	////////�t�@�C���̓ǂݍ���///////
	Load();
	///////�֐��ւ̏����n��//////
	Game(button);
	///////�I������////////
	free(mob);
	free(bools);
	free(mys);
	DxLib_End();	// DX���C�u�����I������
	return 0;
}