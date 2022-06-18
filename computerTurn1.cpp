#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "move.h"
#include "printFouls.h"
#include "rules.h"

int computerTurn1(int state[20][20], int &turn, int &allow, int &X, int &Y, int &leave_camp_value, int n, int L, char &R, unsigned long int beads){
	int pos_x1, pos_y1, pos_x2, pos_y2, i, j, sw, countB, countA, countM;
	extern int EndGameSw;
	printf("Player 1,it's your turn!\n\n");
	while (1){//.....barresi mikone ke voroodi motabar beshe
		printf("Enter the position of your bead:\n\n");
		scanf("%d %d", &pos_x1, &pos_y1);
		pos_x1--;
		pos_y1--;
		// new((((((((((((((((((((((((
		if (!PrintFouls_pos(state, pos_x1, pos_y1, n,turn))
			continue;
		while (1) {//.....barresi mikone ke voroodi motabar beshe
			printf("Enter the position of destination:\n\nif you want to change your bead,enter\"0 0\"\n\n");
			scanf("%d %d", &pos_x2, &pos_y2);
			if (pos_x2 == 0 && pos_y2 == 0) break;
			pos_x2--;
			pos_y2--;

			if ((leave_camp_value)>L){
				if (!(specialrule(state, R, n, beads, 2)))
					return 0;
			}
			//new((((((((((((((((((((((
			if (!PrintFouls_des(state, pos_x2, pos_y2, pos_x1, pos_y1, n))
				continue;
			if (pos_x2 == pos_x1){
				if (pos_y2>pos_y1){
					for (i = pos_y1 + 1, sw = 1, countM = 0; i<pos_y2; i++) {

						if (state[pos_x1][i] != 0) {
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_y2 - pos_y1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (pos_y2<pos_y1){
					for (i = pos_y1 - 1, sw = 1, countM = 0; i>pos_y2; i--) {

						if (state[pos_x1][i] != 0) {
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_y2 - pos_y1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (sw == 0) {
					if (pos_y2>pos_y1){
						for (i = pos_y1 + 1, countB = 0; state[pos_x1][i] == 0; i++, countB++);
						for (i++, countA = 0; i<pos_y2; i++, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0) {
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}

					if (pos_y2<pos_y1){
						for (i = pos_y1 - 1, countB = 0; state[pos_x1][i] == 0; i--, countB++);
						for (i--, countA = 0; i>pos_y2; i--, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0) {
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
			}

			if (pos_y2 == pos_y1){
				if (pos_x2>pos_x1){
					for (i = pos_x1 + 1, sw = 1, countM = 0; i<pos_x2 && sw; i++) {

						if (state[i][pos_y1] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (pos_x2<pos_x1){
					for (i = pos_x1 - 1, sw = 1, countM = 0; i>pos_x2 && sw; i--) {

						if (state[i][pos_y1] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (sw == 0){
					if (pos_x2>pos_x1){
						for (i = pos_x1 + 1, countB = 0; state[i][pos_y1] == 0; i++, countB++);
						for (i++, countA = 0; i<pos_x2; i++, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0){
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
					if (pos_x2<pos_x1){
						for (i = pos_x1 - 1, countB = 0; state[i][pos_y1] == 0; i--, countB++);
						for (i--, countA = 0; i>pos_x2; i--, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0) {
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}

			}
			if (abs(pos_x2 - pos_x1) == abs(pos_y2 - pos_y1)) {
				if (pos_x2>pos_x1 && pos_y2>pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 + 1, sw = 1, countM = 0; i<pos_x2 && j<pos_y2; i++, j++) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1 || abs(pos_y2 - pos_y1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
					if (sw == 0){
						for (i = pos_x1 + 1, j = pos_y1 + 1, countB = 0; state[i][j] == 0; i++, j++, countB++);
						for (i++, j++, countA = 0; i<pos_x2, j<pos_y2; i++, j++, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0){
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (pos_x2>pos_x1 && pos_y2<pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 - 1, sw = 1, countM = 0; i<pos_x2 && j>pos_y2; i++, j--) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1 || abs(pos_y2 - pos_y1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
					if (sw == 0){
						for (i = pos_x1 + 1, j = pos_y1 - 1, countB = 0; state[i][j] == 0; i++, j--, countB++);
						for (i++, j--, countA = 0; i<pos_x2, j>pos_y2; i++, j--, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0){
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (pos_x2<pos_x1 && pos_y2>pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 + 1, sw = 1, countM = 0; i>pos_x2 && j<pos_y2; i--, j++) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1 || abs(pos_y2 - pos_y1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
					if (sw == 0){
						for (i = pos_x1 - 1, j = pos_y1 + 1, countB = 0; state[i][j] == 0; i--, j++, countB++);
						for (i--, j++, countA = 0; i>pos_x2, j<pos_y2; i--, j++, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0){
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
				if (pos_x2<pos_x1 && pos_y2<pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 - 1, sw = 1, countM = 0; i>pos_x2 && j>pos_y2; i--, j--) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						printf("Invalid jump!\n\n");
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1 || abs(pos_y2 - pos_y1)>1) {
							printf("Invalid move!\n\n");
							continue;
						}
						else{
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
					if (sw == 0){
						for (i = pos_x1 - 1, j = pos_y1 - 1, countB = 0; state[i][j] == 0; i--, j--, countB++);
						for (i--, j--, countA = 0; i>pos_x2, j>pos_y2; i--, j--, countA++);
						if (countB != countA) {
							printf("Invalid jump!\n\n");
							continue;
						}
						else if (countB == 0){
							allow = 1;
							X = pos_x2;
							Y = pos_y2;
						}
					}
				}
			}
			break;
		} //while 
		if (pos_x2 == 0 && pos_y2 == 0) continue;
		else break;
	}
	state[pos_x2][pos_y2] = state[pos_x1][pos_y1];
	state[pos_x1][pos_y1] = 0;
	
	return 1;
}
