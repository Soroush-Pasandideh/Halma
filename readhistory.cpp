#include<stdio.h>
#include "sign.h"

void readhistory(player players[]){
	FILE *read = fopen("playershistory.dat", "rb");
	if(! read) printf("Can not open file!");
    fread(players, sizeof(player), 100, read);
	fclose(read);
}
