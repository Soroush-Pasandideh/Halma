#ifndef GENERAL_H
#define GENERAL_H
#include <windows.h>

void setTextColor(int textColor, int backColor);

void border(int state[20][20], int n, int bead1, int bead2);

void next_turn(int &turn);

void delay(int milli_seconds);

#endif
