#include<stdio.h>
#include "printFouls.h"

int PrintFouls_pos(int state[][20], int pos_x1, int pos_y1, int N,int Turn){
	if (state[pos_x1][pos_y1] == 0){
		printf("There's no bead in this position!\n\n");
		return  0;
	}
	if (pos_x1<0 || pos_x1>N || pos_y1<0 || pos_y1>N){
		printf("The position is out of range\n\n");
		return  0;
	}
	if(Turn == 1){
	    if (state[pos_x1][pos_y1] == 2){
	    	printf("You can't move the other player's bead ! please choose yours.\n\n ");
	    	return  0;
	}
}
    else if(Turn == 2){
    	if (state[pos_x1][pos_y1] == 1){
	    	printf("You can't move the other player's bead ! please choose yours.\n\n ");
	    	return  0;
	}
	}
}
