#include<stdio.h>
#include "printFouls.h"
#include "general.h"

void PrintFouls_specialRuleDestination(int order, char &r){
	if (order == 1){
		r = 'v';
		setTextColor(12, 0);
		printf("player 1 ,you can't go back to your camp out of the leave_camp_value , so...\n\n ");
		setTextColor(10, 0);
		printf("		      *** player 2 won ***\n\n");
		setTextColor(8, 0);
		printf("	                   GAME OVER\n\n");
	}
	else{
		r = 'L';
		setTextColor(12, 0);
		printf("player 2 ,you can't go back to your camp out of the leave_camp_value , so...\n\n ");
		setTextColor(10, 0);
		printf("		      *** player 1 won ***\n\n");
		setTextColor(8, 0);
		printf("	                   GAME OVER\n\n");
	}
}
