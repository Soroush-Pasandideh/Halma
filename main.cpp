#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "sign.h"
#include "rules.h"
#include "gamesettings.h"
#include "general.h"
#include "code.h"
#include "move.h"
#include "printFouls.h"
#include "gameHistory.h"

int main(){
	player players[100] = { 0 };
	int leave_camp_value = 0, nameplace;
	int n = 0, L = 0, color1 = 0, color2 = 0;
	int Turn = 1, allow = 0, def = 0, jump_x, jump_y;
	int state[20][20] = { { 0 } };
	char beadorder[15] = { 0 }, order, playercount, sign, sw;
	srand(time(NULL));
	while (1){
		system("cls");
		printf("\n\n\n\n\n\n\nDo you want to sign in or sign up?\n\nEnter \"I\" to sign in or \"U\" to sign up:\n");
		sign = getch();
		if (sign == 'U' || sign == 'u'){
			readhistory(players);
			nameplace = SignUpname(players);
			saveplayershistory(players);
			SignUpPass();
			break;
		}
		else if (sign == 'I' || sign == 'i'){
			readhistory(players);
			nameplace = SignInPass(players);
			break;
		}
		else {
			printf("\nYou pressed a wrong key.Try again:\n\n");
			delay(1500);
			continue;
		}
	}
	ReadFile(n, beadorder, L, color1, color2);
	defaultSet(n, beadorder, L, color1, color2);
	unsigned long int beads = atoi(beadorder);
	setTextColor(12, 0);
	delay(800);
	Menuorders(order, playercount, nameplace, players, state, Turn, leave_camp_value);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                            WELCOME TO HALMA!!\n\n\n\n");
	delay(1000);
	setTextColor(11, 0);
	if (order == 'n'){
		if (beads == 1232) code1232(state, n);
		else if (beads == 12343) code12343(state, n);
		else if (beads == 123454) code123454(state, n);
		else if (beads == 121) code121(state, n);
	}
	border(state, n, color1, color2);
	if (order == 'n'){
		printf("player1 is");
		setTextColor(color1, 0);
		printf(" o");
		setTextColor(15, 0);
		printf(" and player2 is");
		setTextColor(color2, 0);
		printf(" o");
		setTextColor(15, 0);
		printf("!!\n\n");
		printf("whoever plays first will be player1!!\n\n");
	}
	while (1){
		char Result;
		if (!endGame(state, Result, n, beads, order, Result)){
			if (Result == 'v') players[nameplace].victories++;
			if (Result == 'L') players[nameplace].defeats++;
			if (Result == 'd') players[nameplace].draws++;
			saveplayershistory(players);
			break;
		}
		leave_camp_value++;
		if (leave_camp_value == L + 1){
			if (!(specialrule(state, Result, n, beads, 1))){
				if (Result == 'v') players[nameplace].victories++;
				if (Result == 'L') players[nameplace].defeats++;
				if (Result == 'd') players[nameplace].draws++;
				saveplayershistory(players);
				break;
			}
		}
		if (playercount == '2'){
			if (move(state, Turn, allow, jump_x, jump_y, leave_camp_value, n, L, Result, beads)){
				border(state, n, color1, color2);
				next_turn(Turn);
				printf("please enter: \" 1 \" : Next player\n\n              \" 2 \" : Jump again\n");
				while (1){
					sw = getch();
					if (sw != '1' && sw != '2' && sw != 's' && sw != 'm' && sw != 'q'){
						printf("You pressed a wrong key. Try again:\n");
						continue;
					}
					if (sw == '1' || sw == '2' || sw == 'q') break;
					if (sw == 's'){
						SaveGame(nameplace, state, Turn, leave_camp_value, playercount);						break;
					}
					if (sw == 'm') {
						SaveGame(nameplace, state, Turn, leave_camp_value, playercount);
						Menuorders(order, playercount, nameplace, players, state, Turn, leave_camp_value);
						setTextColor(15, 0);
						border(state, n, color1, color2);
						break;
					}
				}
				if (sw == '1') allow = 0;
				if (sw == '2') {
					if (allow != 1) printf("Not allowed!\n\n");
					else{
						next_turn(Turn);
						Jumpagain(state, Turn, allow , playercount, jump_x, jump_y, n, color1, color2);
						border(state, n, color1, color2);
						next_turn(Turn);
					}
					allow = 0;
				}
				if (sw == 'q' || sw == 's') break;
			}
			else {//if (!(move(state, Turn, allow...
				if (Result == 'v') players[nameplace].victories++;
				if (Result == 'L') players[nameplace].defeats++;
				if (Result == 'd') players[nameplace].draws++;
				saveplayershistory(players);
				printf("..GAME OVER..");
				break;
			}
		}
		if (playercount == '1'){
			if (Comp(state, Turn, allow, jump_x, jump_y, leave_camp_value, n, L, Result, beads)){
				border(state, n, color1, color2);
				next_turn(Turn);
				if (Turn == 2){
					printf("please enter: \" 1 \" : Next player\n\n              \" 2 \" : Jump again\n\n");
					while (1){
						sw = getch();
						if (sw != '1' && sw != '2' && sw != 's' && sw != 'm' && sw != 'q'){
							printf("You pressed a wrong key. Try again:\n");
							continue;
						}
						if (sw == '1' || sw == '2' || sw == 'q') break;
						if (sw == 's'){
							SaveGame(nameplace, state, Turn, leave_camp_value, playercount);
							break;
						}
						if (sw == 'm') {
							SaveGame(nameplace, state, Turn, leave_camp_value, playercount);
							Menuorders(order, playercount, nameplace, players, state, Turn, leave_camp_value);
							setTextColor(15, 0);
							border(state, n, color1, color2);
							break;
						}
					}
					if (sw == '1') {
						allow = 0;
						delay(1500);
					}
					if (sw == '2') {
						if (allow != 1){
							printf("Not allowed!\n\n");
							delay(1500);
						}
						else{
							next_turn(Turn);
							Jumpagain(state, Turn, allow, playercount, jump_x, jump_y, n, color1, color2);
							border(state, n, color1, color2);
							next_turn(Turn);
						}
						allow = 0;
						delay(1500);
					}
					if (sw == 'q' || sw == 's') break;
				}
				else if (Turn == 1){
					int r = 0;
					while (!allow && r < 5){
						int next = rand() % 2 + 1;
						if (next == 1) allow = 0;
						if (next == 2){
							if (allow == 1){
								next_turn(Turn);
								Jumpagain(state, Turn, allow, order, jump_x, jump_y, n, color1, color2);
								border(state, n, color1, color2);
								next_turn(Turn);
							}
						}
						r++;
					}
					allow = 0;
				}
			}
			else {//if (!(Comp(state, Turn, allow)))....agar EndGameSw==0
				if (Result == 'v') players[nameplace].victories++;
				if (Result == 'L') players[nameplace].defeats++;
				if (Result == 'd') players[nameplace].draws++;
				saveplayershistory(players);
				printf("..GAME OVER..");
				break;
			}
		}
	}
}

