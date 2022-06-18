#include<stdio.h>
#include "gameHistory.h"
#include "general.h"

void printBestPlayers(bestPlayer bestPlayers[], int countBestPlayer){
	if (countBestPlayer ==1){
		setTextColor(14, 0);
		printf("                                       the best player is << %s >>", bestPlayers[0].name);
	}
	else {
		setTextColor(14, 0);
		printf("                                       the best players are :\n");
		for (int i = 0; i < countBestPlayer; i++){
			printf("                                             << %s >>\n", bestPlayers[i].name);
		}
	}
}