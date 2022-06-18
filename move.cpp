#include<math.h>
#include "move.h"
int move(int state[20][20], int turn, int &allow, int &X, int &Y, int leave_camp_value, int n, int L, char &result, unsigned long int beads){
     int N;
	N = n - 1;
	if (turn == 1){
		if (!(moveTurn1(state, turn, allow, X, Y, leave_camp_value, N, L, result ,beads)))
			return 0;
		else return 1;//if moveTurn1(state, turn, allow, X, Y, leave_camp_value, N, L)==1
	}

	else{//....if (turn==2) 
		if (!(moveTurn2(state, turn, allow, X, Y, leave_camp_value, N, L, result, beads)))
			return 0;
		else return 1;//if moveTurn1(state, turn, allow, X, Y, leave_camp_value, N, L)==1
	}//else
}//move
