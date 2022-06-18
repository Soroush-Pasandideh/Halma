#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "gamesettings.h"
#include "general.h"

char Menu(){
	char order;
	setTextColor(11, 0);
	printf("\n\n\n\n\n\n           * If you want to start a new game, you have to choose the number of players before pressing n!! *");
	printf("\n\n\n\n\n\n                                                    MENU\n\n");
	printf("                                                Game History(g)\n\n");
	printf("                                               Player History(p)\n\n");
	printf("                                             2 players or 1 player?(1or2)\n\n");
	printf("                                                  New Game(n)\n\n");
	printf("                                                Continue Game(c)\n\n");
	while (1){
		order = getch();
		if (order != 'g' && order != 'p' && order != '1' && order != '2' && order != 'n' && order != 'c')
			printf("You pressed a wrong key! Try again:\n\n");
		else break;
	}
	return order;
}
