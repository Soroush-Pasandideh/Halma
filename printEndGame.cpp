#include<stdio.h>
#include<conio.h>
#include "printFouls.h"
#include "general.h"

int printEndGame(int order, char &r){
	if (order == 1){
		r = 'v';
		setTextColor(12, 0);
		printf("player 1's camp is completely filled by player 2 , so...\n\n");
		setTextColor(10, 0);
		printf("    ***player 1 won***\n\n");
		setTextColor(8, 0);
		printf("       GAME OVER\n\n");
	}
	else{
		r = 'L';
		setTextColor(12, 0);
		printf("player 2's camp is completely filled by player 1 , so...\n\n");
		setTextColor(10, 0);
		printf("    ***player 2 won***\n\n");
		setTextColor(8, 0);
		printf("       GAME OVER\n\n");
	}
	printf("press any key to Quit the game...\n\n");
	getch();
	return 0;
}