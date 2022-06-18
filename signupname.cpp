#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "sign.h"
#include "general.h"

int SignUpname(player players[10]){
	int i;
	char name[20];
	FILE *user = fopen("info.dat", "a+b");
	char temp[20];
	if (!user) {
		printf("Can not open file!");

	}
	while (1){
		system("cls");
		printf("\n\n\n\n\n\nPlease enter your username:\n\n");
		scanf("%s", temp);
		fread(&name, sizeof(name), 1, user);
		while (!feof(user)){
			if (strcmp(temp, name) == 0){
				printf("\n\nUsername already exists! Try again!!");
				delay(700);
				break;
			}
			fread(&name, sizeof(name), 1, user);
		}
		if (strcmp(temp, name) == 0) continue;
		break;
	}
	strcpy(name, temp);
	int len = strlen(name);
//	name[len+1] = NULL;
	fwrite(&name, sizeof(name), 1, user);
	for(i=0; players[i].name[0]; i++);
	strcpy(players[i].name,name);
	fclose(user);
	return i;
}
