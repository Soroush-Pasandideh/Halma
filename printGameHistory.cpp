#include<stdio.h>
#include "gameHistory.h"
#include "general.h"

void printGameHistory(game g, int countBestPlayer){
	setTextColor(14, 0);
	printf("\n\n\n\n\n\n\n\n                                        *** GAME STATISTICS ***\n\n");
	setTextColor(6, 0);
	printf("                                       the number of games is    %d\n\n", g.gameNum);
	setTextColor(10, 0);
	printf("                                       the number of wins is     %d\n\n", g.winNum);
	setTextColor(12, 0);
	printf("                                       the number of loses is    %d\n\n", g.loseNum);
	setTextColor(3, 0);
	printf("                                       the number of draws is    %d\n\n", g.drawNum);
}