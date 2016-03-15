/*******************************************
File: functions.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Binary Gap challenge functions
Date: 15 March 2016
*******************************************/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

uint16_t solution(uint32_t input_number)
{
  bool binary_gap_edge = false;

  uint16_t binary_gap_max = 0;
  uint16_t binary_gap = 0;
  uint8_t digit;
  while(input_number > 0)
  {
    digit = input_number % 2;
    input_number /= 2;

    if(digit) binary_gap_edge = true;
    else if(binary_gap_edge && !digit) binary_gap++;
    else if(binary_gap && binary_gap_edge && !digit)
    {
      binary_gap_edge = false;
      if(binary_gap > binary_gap_max) binary_gap_max = binary_gap;
      binary_gap = 0;
    }
  }
  return binary_gap_max;
}
