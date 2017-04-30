#ifndef _MAIN_H_
#define _MAIN_H_

struct Mob_t{
	bool f;		//存在フラグ
	double x, y;	//座標情報
	int kind;	//	種類
	int way;		//向き、方向
};

struct Boll_t {
	bool f;
	int x, y;
	int kind;

};

struct Myself_t {
	double x, y;
	int score;	//スコア
	int res;	//残基	residueの略
};

struct Button_t {
	//各ボタンの状態	0=無効,1=有効
	//ビットフラグについてはdefine.hを参照。
	//restは長押し対策	restrictionの略
	char button, rest;
};

#endif