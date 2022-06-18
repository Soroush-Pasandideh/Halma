#include <iostream>
#include<stdio.h>
#include "general.h"
// this function recieves the state of border and prints it
void border(int state[20][20], int n, int bead1, int bead2){
	system("cls");
	setTextColor(12, 0);
	printf("\n Open Menu(m)\n Save and quit(s)\n Quit(q)");
	setTextColor(15, 0);
	printf("\n\n\n\n");
	printf("             ");
	for (int h = 1; h <= n; h++){
		if (h < 10) printf("  %d  ", h);
		else printf("  %d ", h);
	}
	printf("\n");
	int i = 0;
	for (int row = 0; row < 2 * n + 1; row++){
		if (row % 2 == 0){
			printf("             ");
			for (int h = 0; h < n; h++){
				printf("=");
			}
			i++;
		}
		else{
			if (i < 10) printf("            %d", i);
			else printf("           %d", i);
		}
		for (int column = 0; column < 2 * n + 1; column++){

			if (row % 2 == 0) {
				printf("==");
			}
			else{
				if (column % 2 == 0) {
					printf("||");
				}
				else{
					if (state[row / 2][column / 2] == 0) printf("   ");
					else{
						if (state[row / 2][column / 2] == 1) {
							setTextColor(bead1, 0);
							printf(" o ");
						}
						else if (state[row / 2][column / 2] == 2){
							setTextColor(bead2, 0);
							printf(" o ");
						}
						setTextColor(15, 0);
					}
				}
			}
		}
		printf("\n");
	}
}
