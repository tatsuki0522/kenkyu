#include "define.h"
#include "main.h"
#include "Dxlib.h"

void Player_move(struct Button_t *button, struct Myself_t *mys)
{
	if ((button->button & BUTTON_RIGHT)!=0){
		mys->x++;
	}
}

void Player_main(struct Ball_t *ball, struct Button_t *button,struct Myself_t *mys)
{
	Player_move(button, mys);
}