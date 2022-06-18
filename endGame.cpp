#include<stdio.h>
#include<conio.h>
#include "rules.h"
#include "printFouls.h"
#include "general.h"

int endGame(int state[][20], char &result, int n, unsigned long int beads, int order, char &r){
	int i, j, count1 = 0, count2 = 0, code, endGameSwPlayer1 = 1, endGameSwPlayer2 = 1;
	switch (beads){
	case 123454:code = 5;
		break;
	case 12343:code = 4;
		break;
	case 1232:code = 3;
		break;
	case 121:code = 2;
		break;
	}
	for (i = 0; i < code; i++){
		while (i <= 1){
			for (j = 0; j < code; j++){
				if (state[i][j] != 2){
					endGameSwPlayer2 = 0;
				}
			}
			i++;
		}
		if (code == 2) break;
		if (i == 2) {
			for (j = 0; j < code - 1; j++){
				if (state[i][j] != 2){
					endGameSwPlayer2 = 0;
				}
			}
		}
		if (code == 3) break;
		if (i == 3){
			for (j = 0; j < code - 2; j++){
				if (state[i][j] != 2){
					endGameSwPlayer2 = 0;
				}
			}
		}
		if (code == 4) break;
		if (i == 4){
			for (j = 0; j < code - 3; j++){
				if (state[i][j] != 2){
					endGameSwPlayer2 = 0;
				}
			}
		}
	}
	for (i = n - 1; i > n - code - 1; i--){
		while (i >= n - 2){
			for (j = n - 1; j > n - code - 1; j--){
				if (state[i][j] != 1){
					endGameSwPlayer1 = 0;
				}
			}
			i--;
		}
		if (code == 2) break;
		if (i == n - 3){
			for (j = n - 1; j > n - code; j--){
				if (state[i][j] != 1){
					endGameSwPlayer1 = 0;
				}
			}
		}
		if (code == 3) break;
		if (i == n - 4){
			for (j = n - 1; j > n - code + 1; j--){
				if (state[i][j] != 1){
					endGameSwPlayer1 = 0;
				}
			}
		}
		if (code == 4) break;
		if (i == n - 5){
			for (j = n - 1; j > n - code + 2; j--){
				if (state[i][j] != 1){
					endGameSwPlayer1 = 0;
				}
			}
		}
	}

	//.......................barresi  camp e player2
	if (endGameSwPlayer1 == 1)
		return printEndGame(1,r);
	//bayed v , l , d ro dorost konam...
	if (endGameSwPlayer2 == 1)
		return printEndGame(2,r);
	//bayed v , l , d ro dorost konam...
	else return 1;
}
