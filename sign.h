#ifndef SIGN_H
#define SIGN_H
#include<stdio.h>

	struct player{
		char name[20];
		int gamesno;
		int victories;
		int defeats;
		int draws;
	};

int SignUpname(player players[]);

void SignUpPass();

int SignInName(FILE **user, player players[]);

int SignInPass(player players[]);

void saveplayershistory(player players[]);

void playerhistory(player players[], int place);

void readhistory(player players[]);

void saveGameHistory(player players[]);

#endif
