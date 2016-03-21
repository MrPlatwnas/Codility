/*******************************************
File: FrogJmp.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Solution to FrogJmp problem
Date: 21 March 2016
Elapsed Time: 2 mins 47 secs
*******************************************/

#include <stdio.h>
#include <stdint.h>

uint32_t solution(uint32_t start_pos, uint32_t end_pos, uint32_t step)
{
  start_pos = end_pos - start_pos;
  return start_pos % step ? (start_pos / step) + 1 : start_pos / step;
}

int main(int argc, const char *argv[])
{
  uint32_t start_pos;
  uint32_t end_pos;
  uint32_t step;

  printf("Input starting position: ");
  scanf("%u", &start_pos);

  printf("Input ending position: ");
  scanf("%u", &end_pos);

  printf("Input the step: ");
  scanf("%d", &step);

  uint32_t n_jumps = solution(start_pos, end_pos, step);
  printf("Number of jumps is: %u\n", n_jumps);

  return 0;
}
