#include<stdio.h>
#include<string.h>
#include "gamesettings.h"

int ReadFile(int &N, char order[15], int &leave, int &bead1, int &bead2) {
	char temp[20], color[20];
	char star = '*';
	int t;
	FILE* settings;
	settings = fopen("gameset.txt", "rt");
	if (!settings) {
		printf("Can not open file!");
		return 0;
	}
	fscanf(settings, "%s", temp);
	while (!feof(settings)) {
		if (strcmp(temp, "Size") == 0) {
			fscanf(settings, "%s", temp);
			fscanf(settings, "%d%c%d", &N, &star, &t);
		}
		if (strcmp(temp, "Beads_order") == 0) {
			fscanf(settings, "%s", temp);
			for (int i = 0; i<6; i++){
				fscanf(settings, "%s", &order[i]);
			}
		}
		if (strcmp(temp, "leave_camp_value") == 0) {
			fscanf(settings, "%s", temp);
			fscanf(settings, "%d", &leave);
		}
		if (strcmp(temp, "First_Color") == 0){
			fscanf(settings, "%s", temp);
			fscanf(settings, "%s", temp);
			if (strcmp(temp, "green") == 0) bead1 = 2;
			else bead1 = 3;
		}
		if (strcmp(temp, "Second_Color") == 0){
			fscanf(settings, "%s", temp);
			fscanf(settings, "%s", temp);
			if (strcmp(temp, "green") == 0) bead2 = 2;
			else bead2 = 3;
		}
		fscanf(settings, "%s", temp);
	}
	fclose(settings);
}

