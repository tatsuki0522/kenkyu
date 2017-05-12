#include "boll.h"
#include"main.h"
#include"define.h"
#include"mt.h"
#include"boll.h"
#include<DxLib.h>

void Ball_main(struct Ball_t *ball){
	Ball_create(ball);
}

void Ball_create(struct Ball_t *ball){

	int y, k=0;

	for (y = 0; y < MAX_BALL; y++){

		if (k<=0||k<genrand_int32()%100==0)

				if ((ball+y)->f == FALSE){
					
						(ball + y)->f = TRUE;
						(ball + y)->x = 100;
						(ball + y)->y = 100;
					}
				}
				if ((ball + y)->f == TRUE){
					(ball + y)->x;
					(ball + y)->y--;

				}

			}

