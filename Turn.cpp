#include<stdio.h>
#include "general.h"
void next_turn(int &turn){
  if (turn == 1){
    turn = 2;
  }
  else{
    turn = 1;
  }

}
