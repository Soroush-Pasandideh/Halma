#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "move.h"
int Comp(int state[20][20], int turn, int &allow, int &X, int &Y, int leave_camp_value, int n, int L, char &result, unsigned long int beads){
	 srand(time(NULL));
	 int N;
	N = n - 1;
    if (turn == 1){	
		if (!(computerTurn1(state, turn, allow, X, Y, leave_camp_value, N, L, result, beads)))
			return 0;
		else return 1;
  }//if turn
  else if(turn == 2){
	  if (!(computerTurn2(state, turn, allow, X, Y, leave_camp_value, N, L, result, beads)))
		  return 0;
	  else return 1;
    }//else
}
