#include<stdio.h>
#include "sign.h"


void saveplayershistory(player players[]){
	FILE *write = fopen("playershistory.dat", "wb");
    fwrite(players, sizeof(player) , 100, write);
	fclose(write);
}