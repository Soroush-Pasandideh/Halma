#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "move.h"
#include "general.h"
void Jumpagain(int state[20][20], int turn, int &Allow, char c, int x, int y, int n, int bead1, int bead2){
	srand(time(NULL));
	int pos_x1, pos_y1, pos_x2, pos_y2, N, i, j, sw, countB, countA, countM;
	N = n - 1;
	if (turn == 1){
		while (1) {//.....barresi mikone ke voroodi motabar beshe
			pos_x1 = x;
			pos_y1 = y;
			printf("Enter the position of jump destination for bead %d,%d:\n\nTo stop jumping enter \" 0 0 \"\n\n", pos_x1 + 1, pos_y1 + 1);
			scanf("%d %d", &pos_x2, &pos_y2);
			if (pos_x2 == 0 && pos_y2 == 0) {
				Allow = 0;
				break;
			}
			pos_x2--;
			pos_y2--;
			if ((abs(pos_x2 - pos_x1) != 2 && abs(pos_x2 - pos_x1) != 0) || (abs(pos_y2 - pos_y1) != 2 && abs(pos_y2 - pos_y1) != 0)){
				printf("Invalid jump!\n\n");
				continue;
			}
			if (pos_x2<0 || pos_x2>N || pos_y2<0 || pos_y2>N) {
				printf("The position is out of range!\n\n");
				continue;
			}
			if (state[pos_x2][pos_y2] != 0){
				printf("Position already taken!\n\n");
				continue;
			}
			if (pos_x2 != pos_x1 && pos_y1 != pos_y2 && (abs(pos_x2 - pos_x1) != abs(pos_y2 - pos_y1))) {
				printf("Invalid move!\n\n");
				continue;
			}
			if (pos_x2 == pos_x1){
				if (pos_y2 > pos_y1){
					for (i = pos_y1 + 1, sw = 1; i < pos_y2; i++){

						if (state[pos_x1][i] != 0) {
							sw = 0;
						}
					}
				}
				if (pos_y2<pos_y1){
					for (i = pos_y1 - 1, sw = 1; i>pos_y2; i--){

						if (state[pos_x1][i] != 0) {
							sw = 0;
						}
					}
				}

				if (sw) {
					printf("Invalid jump!\n\n");
					continue;
				}
			}
			if (pos_y2 == pos_y1){
				if (pos_x2 > pos_x1){
					for (i = pos_x1 + 1, sw = 1; i < pos_x2 && sw; i++) {
						if (state[i][pos_y1] != 0){
							sw = 0;
						}
					}
				}
				if (pos_x2<pos_x1){
					for (i = pos_x1 - 1, sw = 1; i>pos_x2 && sw; i--) {

						if (state[i][pos_y1] != 0){
							sw = 0;

						}
					}
				}
				if (sw) {
					printf("Invalid jump!\n\n");
					continue;
				}
			}
			if (abs(pos_x2 - pos_x1) == abs(pos_y2 - pos_y1)) {
				if (pos_x2 > pos_x1 && pos_y2 > pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 + 1, sw = 1; i < pos_x2 && j<pos_y2; i++, j++) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						printf("Invalid jump!\n\n");
						continue;
					}
				}
				if (pos_x2>pos_x1 && pos_y2 < pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 - 1, sw = 1; i<pos_x2 && j>pos_y2; i++, j--) {
						if (state[i][j] != 0){
							sw = 0;

						}
					}
					if (sw) {
						printf("Invalid jump!\n\n");
						continue;
					};
				}
				if (pos_x2<pos_x1 && pos_y2>pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 + 1, sw = 1; i > pos_x2 && j < pos_y2; i--, j++) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						printf("Invalid jump!\n\n");
						continue;
					}
				}
				if (pos_x2<pos_x1 && pos_y2<pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 - 1, sw = 1; i>pos_x2 && j>pos_y2; i--, j--) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						printf("Invalid jump!\n\n");
						continue;
					}
				}
			}
			x = pos_x2;
			y = pos_y2;
			if (pos_x2 != 0) {
				state[pos_x2][pos_y2] = state[pos_x1][pos_y1];
				state[pos_x1][pos_y1] = 0;
			}
			border(state, n, bead1, bead2);
			printf("Please enter: \" 1 \": jump again.\n\n              \" 0 \": next player\n\n ");
			int Sw;
			scanf("%d", &Sw);
			if (Sw == 0) Allow = 0;
			if (Sw == 1) continue;
			else break;
		} //while 

	}//if turn

	else{//....if (turn==2) 
		while (1) {//.....barresi mikone ke voroodi motabar beshe
			pos_x1 = x;
			pos_y1 = y;
			if (c == '2'){
				printf("Enter the position of jump destination for bead %d,%d:\n\nTo stop jumping enter \" 0 0 \"\n\n", pos_x1 + 1, pos_y1 + 1);
				scanf("%d %d", &pos_x2, &pos_y2);
				if (pos_x2 == 0 && pos_y2 == 0){
					Allow = 0;
					break;
				}
				pos_x2--;
				pos_y2--;
			}
			if (c == '1'){
				pos_x2 = rand() % 10 + 1;
				pos_y2 = rand() % 10 + 1;
			}
			if ((abs(pos_x2 - pos_x1) != 2 && abs(pos_x2 - pos_x1) != 0) || (abs(pos_y2 - pos_y1) != 2 && abs(pos_y2 - pos_y1) != 0)){
				if (c == '2'){
					printf("Invalid jump!\n\n");
					continue;
				}
				else continue;
			}
			if (pos_x2<0 || pos_x2>N || pos_y2<0 || pos_y2>N){
				if (c == '2'){
					printf("The position is out of range\n\n");
					continue;
				}
				else continue;
			}
			if (state[pos_x2][pos_y2] != 0){
				if (c == '2'){
					printf("Position already taken!\n\n");
					continue;
				}
				else continue;
			}
			if (pos_x2 != pos_x1 && pos_y1 != pos_y2 && (abs(pos_x2 - pos_x1) != abs(pos_y2 - pos_y1))) {
				if (c == '2'){
					printf("Invalid move!\n\n");
					continue;
				}
				else continue;
			}
			if (pos_x2 == pos_x1){
				if (pos_y2 > pos_y1){
					for (i = pos_y1 + 1, sw = 1; i < pos_y2; i++) {

						if (state[pos_x1][i] != 0) {
							sw = 0;
						}
					}
				}
				if (pos_y2<pos_y1){
					for (i = pos_y1 - 1, sw = 1; i>pos_y2; i--) {

						if (state[pos_x1][i] != 0) {
							sw = 0;
						}
					}
				}
				if (sw) {
					if (c == '2'){
						printf("Invalid jump!\n\n");
						continue;
					}
					else continue;
				}
			}
			if (pos_y2 == pos_y1){
				if (pos_x2 > pos_x1){
					for (i = pos_x1 + 1, sw = 1; i < pos_x2 && sw; i++) {

						if (state[i][pos_y1] != 0){
							sw = 0;
						}
					}
				}
				if (pos_x2<pos_x1){
					for (i = pos_x1 - 1, sw = 1; i>pos_x2 && sw; i--) {

						if (state[i][pos_y1] != 0){
							sw = 0;
						}
					}
				}
				if (sw) {
					if (c == '2'){
						printf("Invalid jump!\n\n");
						continue;
					}
					else continue;
				}
			}
			if (abs(pos_x2 - pos_x1) == abs(pos_y2 - pos_y1)){
				if (pos_x2 > pos_x1 && pos_y2 > pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 + 1, sw = 1; i < pos_x2 && j < pos_y2; i++, j++) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						if (c == '2'){
							printf("Invalid jump!\n\n");
							continue;
						}
						else continue;
					}
				}

				if (pos_x2 > pos_x1 && pos_y2 < pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 - 1, sw = 1; i<pos_x2 && j>pos_y2; i++, j--) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						if (c == '2'){
							printf("Invalid jump!\n\n");
							continue;
						}
						else continue;
					}
				}
				if (pos_x2<pos_x1 && pos_y2>pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 + 1, sw = 1; i > pos_x2 && j < pos_y2; i--, j++) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						if (c == '2'){
							printf("Invalid jump!\n\n");
							continue;
						}
						else continue;
					}
				}
				if (pos_x2<pos_x1 && pos_y2<pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 - 1, sw = 1; i>pos_x2 && j>pos_y2; i--, j--) {
						if (state[i][j] != 0){
							sw = 0;
						}
					}
					if (sw) {
						if (c == '2'){
							printf("Invalid jump!\n\n");
							continue;
						}
						else continue;
					}
				}
			}
			x = pos_x2;
			y = pos_y2;
			if (pos_x2 != 0) {
				state[pos_x2][pos_y2] = state[pos_x1][pos_y1];
				state[pos_x1][pos_y1] = 0;
			}
			border(state, n, bead1, bead2);
			printf("Please enter: \" 1 \": jump again.\n\n              \" 0 \": next player\n\n ");
			int Sw;
			scanf("%d", &Sw);
			if (Sw == 0) Allow = 0;
			if (Sw == 1) continue;
			else break;
		} //while

	}//else
}//move

