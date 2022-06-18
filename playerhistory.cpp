#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "sign.h"

void playerhistory(player players[], int place){
	system("cls");
	FILE *find = fopen("playershistory.dat", "rb");
	fread(players, sizeof(player), 100, find);
	printf("\n\n\n\n\n\n\n\nGames Played:%d\n\n", players[place].gamesno);
	printf("Victories:%d\n\n", players[place].victories);
	printf("Defeats:%d\n\n", players[place].defeats);
	printf("Draws:%d\n\n", players[place].draws);
	printf("press any key To go back to the menu...");
	getch();
	system("cls");
	fclose(find);
}
