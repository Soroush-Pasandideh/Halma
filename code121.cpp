#include "code.h"

void code121(int state[][20], int n){
	int i,j;
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			state[i][j] = 1;
		}
	}
	for(i=n-1; i>n-3; i--){
		for(j= n-1; j>n-3; j--){
			state[i][j] = 2;
		}
	}
}
