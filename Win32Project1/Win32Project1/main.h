#ifndef _MAIN_H_
#define _MAIN_H_

struct Mob_t{
	bool f;		//���݃t���O
	int x, y;	//���W���
	int kind;	//	���
	int way;		//�����A����
};

struct Bool_t {
	bool f;
	int x, y;
	int kind;

};

struct Myself_t {
	int x, y;
	int score;	//�X�R�A
	int res;	//�c��	residue�̗�
};

struct Button_t {
	//�e�{�^���̏��	0=����,1=�L��
	//rest�͒������΍�	restriction�̗�
	bool up;
	bool rest_up;
	bool right;
	bool rest_right;
	bool down;
	bool rest_down;
	bool left;
	bool rest_left;
	bool enter;
	bool rest_enter;
	bool esc;
	bool z;
	bool rest_z;
};

#endif