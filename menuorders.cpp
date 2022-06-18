#include<stdio.h>
#include<stdlib.h>
#include "gamesettings.h"
#include "sign.h"

void Menuorders(char &order, char &playercount, int nameplace, player players[], int state[][20], int &turn, int &leave){
	system("cls");
	while (1){
		order = Menu();
		if (order == 'g') {
			saveGameHistory(players);
			system("cls");
		}
			if (order == 'p') {
				playerhistory(players, nameplace);
				system("cls");
			}
			if (order == '1' || order == '2') {
				playercount = order;
				system("cls");
				printf("\n\n\nYou have decided a %c player game.", order);
				continue;
			}
			if (order == 'n'){
				players[nameplace].gamesno++;
				saveplayershistory(players);
				break;
			}
			if (order == 'c') {
				ContinueGame(nameplace, state, turn, leave, playercount);
				break;
			}
		}
	}
