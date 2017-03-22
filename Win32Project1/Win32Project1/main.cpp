#include <time.h>
#include "MT.h"
#include "main.h"
#include "define.h"
#include "DxLib.h"
//#include "dxlib\DxLib.h"

void Draw()
{

}

void Game()
{
	while (1) {
		ProcessMessage();	//�v���Z�X�̘A��
		ClearDrawScreen();	//��ʂ̍폜
		Draw();				//�G������ׂď���
		ScreenFlip();		//����ʂ�\��ʂɔ��f
	}
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	DxLib_Init();	// DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);	//����ʏ���
	//////�ϐ��̒�`/////
	struct Mob_t *mob;
	struct Bool_t * bools;
	struct Myself_t *mys;
	mob = (Mob_t *)malloc(sizeof(mob)*MAX_MOB);
	bools = (Bool_t *)malloc(sizeof(Bool_t)*MAX_BALL);
	mys = (Myself_t *)malloc(sizeof(Myself_t));
	///////�֐��ւ̏����n��//////
	Game();
	///////�I������////////
	free(mob);
	free(bools);
	free(mys);
	DxLib_End();	// DX���C�u�����I������
	return 0;
}