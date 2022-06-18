#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "gameHistory.h"
#include "sign.h"
#include "general.h"

void saveGameHistory(player players[]){
	system("cls");
	int winArray[100];
	int loseArray[100];
	int drawArray[100];
	int countbestPlayer = 0, countbestWiners = 0;
	int i, j, playersNum;
	bestWiner bestWiners[100];
	bestPlayer bestPlayers[100];
	game g = { 0, 0, 0, 0 };
	for (i = 0; i < players[i].name[0]; i++){//..........meghdar dehi avalie be bestwiner
		bestWiners[i].winNum = 0;
		bestWiners[i].loseNum = 0;
		bestWiners[i].drawNum = 0;
	}
	FILE *playershistory = fopen("playershistory.dat", "rb");
	if (!playershistory) printf("Can not open file!");
	fread(players, sizeof(player), 100, playershistory);
	for (i = 0; i < players[i].name[0]; i++){
		g.gameNum += players[i].gamesno;
		g.winNum += players[i].victories;
		winArray[i] = players[i].victories;
		g.loseNum += players[i].defeats;
		loseArray[i] = players[i].defeats;
		g.drawNum += players[i].draws;
		drawArray[i] = players[i].draws;
	}
	playersNum = i;
	insertionSort(winArray, playersNum);
	insertionSort(loseArray, playersNum);
	insertionSort(drawArray, playersNum);
	for (i = 0; i < players[i].name[0]; i++){
		if (players[i].victories == winArray[playersNum - 1]){
			strcpy(bestWiners[i].name, players[i].name);
			bestWiners[i].winNum = players[i].victories;
			bestWiners[i].loseNum = players[i].defeats;
			bestWiners[i].drawNum = players[i].draws;
			countbestWiners++;
		}
	}
	for (i = 0; i < players[i].name[0]; i++){
		if (bestWiners[i].drawNum == drawArray[playersNum - 1]){
			strcpy(bestPlayers[i].name, bestWiners[i].name);
			bestPlayers[i].winNum = bestWiners[i].winNum;
			bestPlayers[i].loseNum = bestWiners[i].loseNum;
			bestPlayers[i].drawNum = bestWiners[i].drawNum;
			countbestPlayer++;
		}
	}
	printGameHistory(g, countbestPlayer);
	printBestPlayers(bestPlayers, countbestPlayer);
	setTextColor(15, 0);
	printf("\n\npress any key To go back to the menu...");
	getch();
}