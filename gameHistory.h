#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

struct bestWiner{
	char name[20];
	int winNum;
	int loseNum;
	int drawNum;
};
struct bestPlayer{
	char name[20];
	int winNum;
	int loseNum;
	int drawNum;
};
struct game {
	int gameNum;
	int winNum;
	int loseNum;
	int drawNum;
};

void printBestPlayers(bestPlayer bestPlayers[], int countBestPlayer);

void  insertionSort(int  A[], int n);

void printGameHistory(game g, int countBestPlayer);

#endif