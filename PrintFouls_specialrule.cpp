#include<stdio.h>
#include "printFouls.h"
#include "general.h"

int PrintFouls_specialrule(int count1, int count2, char &r){
	if (count1 > 0 && count2 == 0){
		r = 'L';
		setTextColor(12, 0);
		printf("player 1 ,your bead is in your camp out of the leave_camp_value , so...\n\n");
		setTextColor(10, 0);
		printf("		   *** player 2 won ***\n\n");
		return 0;
	}
	if (0 < count2&&count1 == 0){
		r = 'v';
		setTextColor(12, 0);
		printf("player 2 ,your bead is in your camp out of the leave_camp_value , so...\n\n");
		setTextColor(10, 0);
		printf("		   *** player 1 won ***\n\n");
		return 0;
	}
	if (count1 > 0 && count2 > 0){
		r = 'd';
		setTextColor(12, 0);
		printf("both player 1 and player 2 have a bead in their camp out of the leave_camp_value , so...\n\n");
		setTextColor(10, 0);
		printf("		  *** the game ended in a draw ***\n\n");
		return 0;
	}
	else return 1;
}
