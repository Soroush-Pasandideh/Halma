#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "move.h"
#include "printFouls.h"
#include "rules.h"

int computerTurn2(int state[20][20], int &turn, int &allow, int &X, int &Y, int &leave_camp_value, int n, int L, char &R, unsigned long int beads){
	int pos_x1, pos_y1, pos_x2, pos_y2, N, i, j, sw, countB, countA, countM;
	extern int EndGameSw;
	while (1){
		pos_x1 = rand() % (n+1) + 1;
		pos_y1 = rand() % (n+1) + 1;
		pos_x1--;
		pos_y1--;
		if (state[pos_x1][pos_y1] == 0) continue;
		if (state[pos_x1][pos_y1] == 1) continue;
		while (1){
			pos_x2 = rand() % (n+1) + 1; // can i replace 10 with n???
			pos_y2 = rand() % (n+1) + 1;
			pos_x2--;
			pos_y2--;
			if (leave_camp_value > L){
				if (!(specialrule(state, R, n, beads, 2)))
					return 0;
			}
			if (state[pos_x2][pos_y2] != 0) continue;
			if (pos_x2 != pos_x1 && pos_y1 != pos_y2 && (abs(pos_x2 - pos_x1) != abs(pos_y2 - pos_y1))) continue;

			if (pos_x2 == pos_x1){
				if (pos_y2 > pos_y1){
					for (i = pos_y1 + 1, sw = 1, countM = 0; i<pos_y2; i++) {

						if (state[pos_x1][i] != 0) {
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_y2 - pos_y1) > 1) {
							continue;
						}
						else allow = 1;
					}
				}
				if (pos_y2<pos_y1){
					for (i = pos_y1 - 1, sw = 1, countM = 0; i>pos_y2; i--) {

						if (state[pos_x1][i] != 0) {
							sw = 0;
							countM++;
						}
					}
					if (countM > 1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_y2 - pos_y1) > 1) {
							continue;
						}
						else allow = 1;
					}
				}
				if (sw == 0) {
					if (pos_y2 > pos_y1){
						for (i = pos_y1 + 1, countB = 0; state[pos_x1][i] == 0; i++, countB++);
						for (i++, countA = 0; i < pos_y2; i++, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}

					if (pos_y2<pos_y1){
						for (i = pos_y1 - 1, countB = 0; state[pos_x1][i] == 0; i--, countB++);
						for (i--, countA = 0; i>pos_y2; i--, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
				}
			}
			if (pos_y2 == pos_y1){
				if (pos_x2 > pos_x1){
					for (i = pos_x1 + 1, sw = 1, countM = 0; i<pos_x2 && sw; i++) {

						if (state[i][pos_y1] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1) > 1) {
							continue;
						}
						else allow = 1;
					}
				}
				if (pos_x2<pos_x1){
					for (i = pos_x1 - 1, sw = 1, countM = 0; i>pos_x2 && sw; i--) {
						if (state[i][pos_y1] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM > 1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1) > 1) {
							continue;
						}
						else allow = 1;
					}
				}
				if (sw == 0){
					if (pos_x2 > pos_x1){
						for (i = pos_x1 + 1, countB = 0; state[i][pos_y1] == 0; i++, countB++);
						for (i++, countA = 0; i < pos_x2; i++, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
					if (pos_x2<pos_x1){
						for (i = pos_x1 - 1, countB = 0; state[i][pos_y1] == 0; i--, countB++);
						for (i--, countA = 0; i>pos_x2; i--, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
				}

			}
			if (abs(pos_x2 - pos_x1) == abs(pos_y2 - pos_y1)){
				if (pos_x2 > pos_x1 && pos_y2 > pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 + 1, sw = 1, countM = 0; i<pos_x2 && j<pos_y2; i++, j++) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1)>1 || abs(pos_y2 - pos_y1) > 1) {
							continue;
						}
						else allow = 1;
					}
					if (sw == 0){
						for (i = pos_x1 + 1, j = pos_y1 + 1, countB = 0; state[i][j] == 0; i++, j++, countB++);
						for (i++, j++, countA = 0; i < pos_x2, j<pos_y2; i++, j++, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
				}

				if (pos_x2>pos_x1 && pos_y2<pos_y1){
					for (i = pos_x1 + 1, j = pos_y1 - 1, sw = 1, countM = 0; i<pos_x2 && j>pos_y2; i++, j--) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1) > 1 || abs(pos_y2 - pos_y1) > 1) {
							continue;
						}
						else allow = 1;
					}
					if (sw == 0){
						for (i = pos_x1 + 1, j = pos_y1 - 1, countB = 0; state[i][j] == 0; i++, j--, countB++);
						for (i++, j--, countA = 0; i<pos_x2, j>pos_y2; i++, j--, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
				}
				if (pos_x2<pos_x1 && pos_y2>pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 + 1, sw = 1, countM = 0; i > pos_x2 && j<pos_y2; i--, j++) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM>1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1) > 1 || abs(pos_y2 - pos_y1) > 1) {
							continue;
						}
						else allow = 1;
					}
					if (sw == 0){
						for (i = pos_x1 - 1, j = pos_y1 + 1, countB = 0; state[i][j] == 0; i--, j++, countB++);
						for (i--, j++, countA = 0; i > pos_x2, j < pos_y2; i--, j++, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
				}
				if (pos_x2<pos_x1 && pos_y2<pos_y1){
					for (i = pos_x1 - 1, j = pos_y1 - 1, sw = 1, countM = 0; i>pos_x2 && j>pos_y2; i--, j--) {
						if (state[i][j] != 0){
							sw = 0;
							countM++;
						}
					}
					if (countM > 1) {
						continue;
					}
					if (countM == 0){
						if (abs(pos_x2 - pos_x1) > 1 || abs(pos_y2 - pos_y1) > 1) {
							continue;
						}
						else allow = 1;
					}
					if (sw == 0){
						for (i = pos_x1 - 1, j = pos_y1 - 1, countB = 0; state[i][j] == 0; i--, j--, countB++);
						for (i--, j--, countA = 0; i > pos_x2, j > pos_y2; i--, j--, countA++);
						if (countB != countA) {
							continue;
						}
						else if (countB == 0) allow = 1;
					}
				}
			}
			break;
		} //while
		if (pos_x2 == 0 && pos_y2 == 0) continue;
		else break;
	}
	state[pos_x2][pos_y2] = state[pos_x1][pos_y1];
	state[pos_x1][pos_y1] = 0;
	
	return 1;
}
