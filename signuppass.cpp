#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "sign.h"

void SignUpPass(){
	char pass[20];
	FILE *passcode = fopen("info.dat", "ab");
	char C;
	int i = 0;
	printf("\n\nPlease enter your password:\n\n");
	while (1){
		C = getch();
		if (C == '\r') break;
		pass[i] = C;
		printf("*");

		i++;
	}
	pass[i] = NULL;
	fwrite(&pass, sizeof(pass), 1, passcode);

	fclose(passcode);

}
