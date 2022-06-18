#include<string.h>
#include "gamesettings.h"

void defaultSet(int &N,char order[15], int &leave, int &bead1, int &bead2){
	if(N == 0) N = 10;
	if(leave == 0) leave = 40;
	if(bead1 == 0) {
		if(bead2 != 3) bead1 = 3;
		else bead1 = 2;
	}
	if(bead2 == 0) {
		if(bead1 != 3) bead2 = 3;
		else bead2 = 2;
	}
	if(order[0] == 0) {
		strcpy(order,"12343");
		}
	}

