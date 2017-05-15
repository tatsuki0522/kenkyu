#ifndef _DEFINE_H_
#define _DEFINE_H_

#define TRUE 1
#define FALSE 0
//向きに関する定義
#define UP_SIDE 1
#define DOWN_SIDE 2
#define RIGHT_SIDE 3
#define LEFT_SIDE 4
//数に関する定義
#define MAX_MOB 30
#define MAX_BALL 100
#define SPEED_MINE 5
//ファイルに関する情報
#define BALL_MIDIUM_GRAPH "system/photos/enemyboll_m.png"
#define BALL_SMALL_GRAPH "system/photos/enemyboll_small.png"
#define GRAPH_PLAYER "system/photos/player.png"
//ビット演算
#define BIT_FLAG_1 0X01
#define BIT_FLAG_2 0X02
#define BIT_FLAG_4 0X04
#define BIT_FLAG_8 0X08
#define BIT_FLAG_16 0X10
#define BIT_FLAG_32 0X20
#define BIT_FLAG_64 0X40
#define BIT_FLAG_128 0X80

#define BUTTON_UP BIT_FLAG_1
#define BUTTON_DOWN BIT_FLAG_4
#define BUTTON_RIGHT BIT_FLAG_2
#define BUTTON_LEFT BIT_FLAG_8
#define BUTTON_Z BIT_FLAG_16
#define BUTTON_SHIFT BIT_FLAG_32

//Kind
#define BOLL_KIND_ENY 1

#endif