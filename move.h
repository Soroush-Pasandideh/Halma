#ifndef MOVE_H
#define MOVE_H

int moveTurn1(int state[20][20], int &turn, int &allow, int &X, int &Y, int &leave_camp_value, int n, int L, char &R, unsigned long int beads);

int moveTurn2(int state[20][20], int &turn, int &allow, int &X, int &Y, int &leave_camp_value, int n, int L, char &R, unsigned long int beads);

int Comp(int state[20][20], int turn, int &allow, int &X, int &Y, int leave_camp_value, int n, int L, char &result, unsigned long int beads);

void Jumpagain(int state[20][20], int turn, int &Allow, char c, int x, int y, int n, int bead1, int bead2);

int move(int state[20][20], int turn, int &allow, int &X, int &Y, int leave_camp_value, int n, int L, char &result, unsigned long int beads);

int computerTurn1(int state[20][20], int &turn, int &allow, int &X, int &Y, int &leave_camp_value, int n, int L, char &R, unsigned long int beads);

int computerTurn2(int state[20][20], int &turn, int &allow, int &X, int &Y, int &leave_camp_value, int n, int L, char &R, unsigned long int beads);
#endif
