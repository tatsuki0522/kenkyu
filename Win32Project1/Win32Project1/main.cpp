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
	DxLib_Init();	// DX���C�u��������������
	WaitKey();	// �L�[���͑҂�
	DxLib_End();	// DX���C�u�����I������
	return 0;
}