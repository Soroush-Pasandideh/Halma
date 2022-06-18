#include<stdio.h>
#include "gameHistory.h"

void  insertionSort(int  A[], int n) {
	int  i, j, cur;
	for (i = 1; i < n; i++) {
		cur = A[i];
		for (j = i - 1; j >= 0 && cur < A[j]; j--)
			A[j + 1] = A[j];
		A[j + 1] = cur;
	}
}
