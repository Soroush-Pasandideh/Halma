#include<stdio.h>
#include "rules.h"
#include "printFouls.h"

int specialruleDestination(int pos_x2, int pos_y2, int turn, int state[][20], char &result){
	int i, j;
	if (turn == 1){
		for (i = 0; i < 4; i++){
			while (i <= 1){
				for (j = 0; j < 4; j++){
					if (state[i][j] == 1){
					PrintFouls_specialRuleDestination(1,result);
						return  0;
					}
					i++;
				}
			}
			if (i == 2) for (j = 0; j < 3; j++){
				if (state[i][j] == 1){
						PrintFouls_specialRuleDestination(1,result);
						return 0;
				}
			}
			if (i == 3) for (j = 0; j < 2; j++){
				if (state[i][j] == 1){
					PrintFouls_specialRuleDestination(1,result);
					return 0;
				}
			}
		}
	}//.......................barresi e camp e player1
	if (turn == 2){
		for (i = 9; i>5; i--){
			while (i >= 8){
				for (j = 9; j > 5; j--){
					if (state[i][j] == 2){
						PrintFouls_specialRuleDestination(2,result);
						return 0;
					}
					i--;
				}
			}
			if (i == 7) for (j = 9; j > 6; j--){
				if (state[i][j] == 2){
						PrintFouls_specialRuleDestination(2,result);
						return 0;
				}
			}

			if (i == 6) for (j = 9; j > 7; j--){
				if (state[i][j] == 2){
						PrintFouls_specialRuleDestination(2,result);
						return 0;
				}
			}
		}
	}
	else return 1;
}
//.......................barresi  camp e player2

