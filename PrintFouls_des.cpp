#include<stdio.h>
#include<math.h>
#include "printFouls.h"
int PrintFouls_des(int state[][20], int pos_x2, int pos_y2, int pos_x1, int pos_y1, int N){
	if (pos_x2<0 || pos_x2>N || pos_y2<0 || pos_y2>N) {
		printf("The position is out of range!\n\n");
		return  0;
	}
	if (state[pos_x2][pos_y2] != 0){
		printf("Position already taken!\n\n");
		return  0;
	}
	if (pos_x2 != pos_x1 && pos_y1 != pos_y2 && (abs(pos_x2 - pos_x1) != abs(pos_y2 - pos_y1))) {
		printf("Invalid move!\n\n");
		return  0;
	}
	else return 1;
}