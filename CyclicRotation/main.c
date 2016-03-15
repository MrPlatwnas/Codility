/*******************************************
File: main.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Interface
Date: 15 March 2016
*******************************************/

#include <stdio.h>
#include <stdint.h>

void solution(int16_t array[], uint8_t n_rows, uint8_t n_shifts)
{
  uint8_t index;
  while(n_shifts)
  {
    uint16_t last_number = array[n_rows - 1];
    for(index = n_rows - 1; index > 0; index--)
    {
      array[index] = array[index - 1];
    }
    array[0] = last_number;
    n_shifts--;
  }
}

int main(void)
{
  int16_t array[3] = {1, 2, 3};
  solution(array, 3, 1);
  printf("%d\n", array[0]);
  printf("%d\n", array[1]);
  printf("%d\n", array[2]);
}
