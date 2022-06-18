#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "gamesettings.h"
#include<conio.h>
#include "sign.h"

int SignInName(FILE **user, player players[]){
	char name[20], temp[20];
	char A;
	int i;
	while (1){
		system("cls");
		fseek(*user, 0, SEEK_SET);
		printf("\n\n\n\n\n\nPlease enter your username:\n\n");
		scanf("%s", temp);
		fread(&name, sizeof(name), 1, *user);
		while (!feof(*user)){
			if (strcmp(temp, name) == 0) {
				printf("\n\nUser found!\n\n");
				break;
			}
			fread(&name, sizeof(name), 1, *user);
		}
		if (strcmp(temp, name) == 0){
			for(i=0; ; i++){
		        if(strcmp(players[i].name,name) == 0) break;
            }
            break;
		} 
		if (feof(*user)) {
			printf("\n\nUser not found!\n\nWould you like to sign up?\n\nEnter \"y\" if you want to sign up or \"n\" if you want to try again:\n");
			A = getch();
			if (A == 'n') continue;
			else break;
		}
	}
	if (A == 'y'){
		SignUpname(players);
		SignUpPass();
		saveplayershistory(players);
	}
    return i;
}
