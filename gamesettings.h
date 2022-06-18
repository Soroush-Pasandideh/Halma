#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include "sign.h"

void SaveGame(int place, int state[][20], int turn, int leave, char playercount);

void ContinueGame(int place, int state[][20], int &turn, int &leave, char &playercount);

int ReadFile(int &N, char order[15], int &leave, int &bead1, int &bead2);

void defaultSet(int &N, char order[15], int &leave, int &bead1, int &bead2);

char Menu();

void Menuorders(char &order, char &playercount, int nameplace, player players[], int state[][20], int &turn, int &leave);

#endif
