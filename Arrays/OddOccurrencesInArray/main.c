/*******************************************
File: main.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Interface
Date: 16 March 2016
Elapsed Time: 4 min 38 sec
*******************************************/

#include <stdio.h>
#include <stdint.h>

uint32_t solution(uint32_t array[], uint32_t n_rows)
{
  size_t index;
  uint32_t odd_element = array[0];
  for (index = 1; index != n_rows; ++index)
    odd_element ^= array[index];
  return odd_element;
}

int main(void)
{
  uint32_t array[] = {1, 1, 3, 5, 5};
  uint32_t odd_element = solution(array, 5);

  printf("The odd times element is: %d\n", odd_element);
}
