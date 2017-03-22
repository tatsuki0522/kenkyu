#ifndef _MAIN_H_
#define _MAIN_H_

struct Mob_t{
	bool f;		//存在フラグ
	int x, y;	//座標情報
	int kind;	//	種類
	int way;		//向き、方向
};

struct Bool_t {
	bool f;
	int x, y;
	int kind;

};

struct Myself_t {
	int x, y;
	int score;	//スコア
	int res;	//残基	residueの略
};

struct Button_t {
	//各ボタンの状態	0=無効,1=有効
	//restは長押し対策	restrictionの略
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