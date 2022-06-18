#include <stdio.h>
#include "gamesettings.h"

void SaveGame(int place, int state[][20], int turn, int leave, char playercount){
	FILE *save = fopen("SavedGame.dat", "r+b");
	int i, temp;
	int array[20][20] = { { 0 } };
	char Temp;
	for (i = 0; i < place; i++){
		fseek(save, (20 * 20) * sizeof(int), SEEK_CUR);
		fseek(save, 2 * sizeof(int), SEEK_CUR);
		fseek(save, 1 * sizeof(char), SEEK_CUR);
	}
	fwrite(state, sizeof(int), 20 * 20, save);
	fwrite(&turn, sizeof(int), 1, save);
	fwrite(&leave, sizeof(int), 1, save);
	fwrite(&playercount, sizeof(char), 1, save);
	fclose(save);
}
