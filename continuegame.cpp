#include <stdio.h>
#include "gamesettings.h"

void ContinueGame(int place, int state[][20], int &turn, int &leave, char &playercount){
	FILE *Continue = fopen("SavedGame.dat", "rb");
	if(!Continue) printf("Can not open file!");
	int i, temp;
	int array[20][20] = { { 0 } };
	char Temp;
	for (i = 0; i<place; i++){
		fseek(Continue, (20 * 20) * sizeof(int), SEEK_CUR);
		fseek(Continue, 2 * sizeof(int), SEEK_CUR);
		fseek(Continue, 1 * sizeof(char), SEEK_CUR);
	}
	fread(state, sizeof(int), 20 * 20, Continue);
	fread(&turn, sizeof(int), 1, Continue);
	fread(&leave, sizeof(int), 1, Continue);
	fread(&playercount, sizeof(char), 1, Continue);
	fclose(Continue);
}