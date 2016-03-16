/*******************************************
File: main.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Interface
Date: 15 March 2016
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t* solution(int16_t array[], uint8_t n_rows, uint8_t n_shifts)
{
  int16_t *rotated_array = malloc(n_rows * sizeof(int16_t));
  size_t array_index;
  size_t rotated_array_index = n_shifts % n_rows;
  for(array_index = 0; rotated_array_index != n_rows; ++array_index, ++rotated_array_index)
    rotated_array[rotated_array_index] = array[array_index];
  for(rotated_array_index = 0; array_index != n_rows; ++array_index, ++rotated_array_index)
    rotated_array[rotated_array_index] = array[array_index];
  return rotated_array;
}

int main(void)
{
  int16_t *array = malloc(5 * sizeof(int16_t));
  for(size_t i = 0; i < 5; i++) array[i] = i;

  array = solution(array, 5, 5);

  for(size_t i = 0; i < 5; i++) printf("%d ", array[i]);
}
