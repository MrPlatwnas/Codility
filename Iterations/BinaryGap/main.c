/*******************************************
File: main.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Interface
Date: 15 March 2016
Elapsed Time: 28 mins 17 secs
*******************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint16_t solution(uint32_t input_number)
{
  bool binary_gap_edge = false;

  uint16_t binary_gap_max = 0;
  uint16_t binary_gap = 0;
  uint8_t digit;
  while(input_number > 0)
  {
    digit = input_number & 1;
    input_number >>= 1;

    if(((!digit && binary_gap_max) || digit) && !binary_gap_edge)
    {
      if(!digit) binary_gap++;
      binary_gap_edge = true;
    }
    else if(binary_gap_edge && !digit)
    {
      binary_gap++;
    }
    else if(binary_gap && binary_gap_edge && digit)
    {
      binary_gap_edge = false;
      if(binary_gap > binary_gap_max) binary_gap_max = binary_gap;
      binary_gap = 0;
    }
  }
  return binary_gap_max;
}

int main(void)
{
  uint32_t input_number;

  printf("Give a number: ");
  scanf("%d", &input_number);

  uint16_t binary_gap;
  binary_gap = solution(input_number);
  printf("%d has %d binary gap\n", input_number, binary_gap);
}
