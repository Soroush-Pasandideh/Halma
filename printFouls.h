#ifndef PRINTFOULS_H
#define PRINTFOULS_H

int PrintFouls_pos(int state[20][20], int pos_x1, int pos_y1, int N,int Turn);

int PrintFouls_des(int state[20][20], int pos_x2, int pos_y2, int pos_x1, int pos_y1, int N);

int PrintFouls_specialrule(int count1, int count2, char &r);

void PrintFouls_specialRuleDestination(int order, char &r);

int printEndGame(int order, char &r);

#endif
