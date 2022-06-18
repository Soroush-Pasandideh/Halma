#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "gamesettings.h"
#include "sign.h"

int SignInPass(player players[]){
	char pass[20], temp[20] = { 0 };
	char C;
	int i = 0,j;
	FILE *passcode = fopen("info.dat", "rb");
	if (!passcode) printf("Can not open file!\n\n");
	j = SignInName(&passcode, players);
	while (1){
		i = 0;
		printf("\n\nPlease enter your password:\n\n");
		while (1){
			C = getch();
			if (C == '\r') break;
			temp[i] = C;
			printf("*");
			i++;
		}
		i = 0;
		fread(&pass, sizeof(pass), 1, passcode);
		while (!feof(passcode) && i<1){
			if (strcmp(temp, pass) == 0) {
				printf("\n\nSign in complete!");
				break;
			}
			fread(&pass, sizeof(pass), 1, passcode);
			i++;
		}
		if (strcmp(temp, pass) == 0) break;
		if (feof(passcode) || i == 1) {
			printf("\n\nWrong password!  If you have forgotten your password you can sign up again!\n");
			do{
				printf("\nWould you like to sign up?\n\nEnter \"y\" if you want to sign up or \"n\" if you want to try again:\n");
				C = getch();
				if (C != 'n' && C != 'y') printf("You pressed a wrong key.Try again!");
			} while (C != 'n' && C != 'y');
		}
		if (C == 'n') {
			system("cls");
			fseek(passcode, -2 * sizeof(pass), SEEK_CUR);
			continue;
		}
		else if (C == 'y') break;
	}
	if (C == 'y'){
		SignUpname(players);
		SignUpPass();
		saveplayershistory(players);
	}
	fclose(passcode);
	return j;
}
