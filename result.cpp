#include <time.h>
#include<stdio.h>
#include "general.h"
void delay(int milli_seconds){//dar anjam barname vaghfe ijad mikonad
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
