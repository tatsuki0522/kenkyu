#include "define.h"
#include "main.h"
#include "Dxlib.h"

void Player_move(struct Button_t *button, struct Myself_t *mys)
{
	if ((button->button & BUTTON_RIGHT) != 0){
		mys->x += SPEED_MINE;
	}
	if ((button->button & BUTTON_LEFT) != 0){
		mys->x -= SPEED_MINE;
	}
	if ((button->button & BUTTON_UP) != 0){
		mys->y -= SPEED_MINE;
	}
	if ((button->button & BUTTON_DOWN) != 0){
		mys->y += SPEED_MINE;
	}
}

void Player_main(struct Ball_t *ball, struct Button_t *button, struct Myself_t *mys)
{
	Player_move(button, mys);
}