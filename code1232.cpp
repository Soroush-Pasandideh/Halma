#include "code.h"

void code1232(int state[][20], int n){
	int i, j;
	for (i = 0; i<3; i++){
		while (i <= 1){
			for (j = 0; j<3; j++){
				state[i][j] = 1;
			}
			i++;
		}
		if (i == 2) {
			for (j = 0; j<2; j++){
				state[i][j] = 1;
			}
		}
	}
	for (i = n - 1; i>n - 4; i--){
		while (i >= n - 2){
			for (j = n - 1; j>n - 4; j--){
				state[i][j] = 2;
			}
			i--;
		}
		if (i == n - 3){
			for (j = n - 1; j>n - 3; j--){
				state[i][j] = 2;
			}
		}
	}
}