#include<stdio.h>
#include<conio.h>
#include "rules.h"
#include "printFouls.h"
#include "general.h"

int specialrule(int state[][20], char &result, int n, unsigned long int beads, int order){//order==1 specialrule , order==2 specialruledestination
	int i, j, count1 = 0, count2 = 0, code;
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
				if (state[i][j] == 1){
					if (order == 1)
						count1++;
					if (order == 2){
						PrintFouls_specialRuleDestination(1, result);
						return  0;
					}
				}
			}
			i++;
		}
		if (code == 2) break;
		if (i == 2) {
			for (j = 0; j < code - 1; j++){
				if (state[i][j] == 1){
					if (order == 1)
						count1++;
					if (order == 2){
						PrintFouls_specialRuleDestination(1, result);
						return  0;
					}
				}
			}
		}
		if (code == 3) break;
		if (i == 3){
			for (j = 0; j < code - 2; j++){
				if (state[i][j] == 1){
					if (order == 1)
						count1++;
					if (order == 2){
						PrintFouls_specialRuleDestination(1, result);
						return  0;
					}
				}
			}
		}
		if (code == 4) break;
		if (i == 4){
			for (j = 0; j < code - 3; j++){
				if (state[i][j] == 1){
					if (order == 1)
						count1++;
					if (order == 2){
						PrintFouls_specialRuleDestination(1, result);
						return  0;
					}
				}
			}
		}
	}
	for (i = n - 1; i > n - code - 1; i--){
		while (i >= n - 2){
			for (j = n - 1; j > n - code - 1; j--){
				if (state[i][j] == 2){
					if (order == 1)
						count2++;
					if (order == 2){
						PrintFouls_specialRuleDestination(2, result);
						return  0;
					}
				}
			}
			i--;
		}
		if (code == 2) break;
		if (i == n - 3){
			for (j = n - 1; j > n - code; j--){
				if (state[i][j] == 2){
					if (order == 1)
						count2++;
					if (order == 2){
						PrintFouls_specialRuleDestination(2, result);
						return  0;
					}
				}
			}
		}
		if (code == 3) break;
		if (i == n - 4){
			for (j = n - 1; j > n - code + 1; j--){
				if (state[i][j] == 2){
					if (order == 1)
						count2++;
					if (order == 2){
						PrintFouls_specialRuleDestination(2, result);
						return  0;
					}
				}
			}
		}
		if (code == 4) break;
		if (i == n - 5){
			for (j = n - 1; j > n - code + 2; j--){
				if (state[i][j] == 2){
					if (order == 1)
						count2++;
					if (order == 2){
						PrintFouls_specialRuleDestination(2, result);
						return  0;
					}
				}
			}
		}
	}

	//.......................barresi  camp e player2
	if (order == 1){
		if (!(PrintFouls_specialrule(count1, count2, result))){
			setTextColor(8, 0);
			printf("	                GAME OVER\n\n");
			setTextColor(15, 0);
			printf("press any key to Quit the game...");
			getch();
			return 0;
		}
		else return 1;
	}
	return 1;
}
//..........barresi mishe ke aya mohre ii dar camp moonde boode ya na

