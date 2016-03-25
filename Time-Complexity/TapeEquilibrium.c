/*******************************************
File: TapeEquilibrium.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Solution to TapeEquilibrium problem
Date: 25 March 2016
Elapsed Time: 6 mins 32 secs
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t solution(uint32_t *, uint32_t);

int main(int argc, const char *argv[])
{
  uint32_t n_cols;
  printf("How many numbers will you enter?: ");
  scanf("%u", &n_cols);

  uint32_t *array = malloc(n_cols * sizeof(uint32_t));

  printf("Enter the numbers:\n");
  for(uint32_t counter = 0; counter < n_cols; counter++)
    scanf("%u", &array[counter]);

  uint32_t minimal_diff = solution(array, n_cols);
  printf("The minimal difference is: %u\n", minimal_diff);
  return 0;
}

uint32_t solution(uint32_t *array, uint32_t n_cols)
{
  uint32_t minimal_diff;
  int32_t left_subarray_value;
  int32_t right_subarray_value;
  uint32_t minimal_subarray_split_position;
  for(uint32_t subarray_split = 1; subarray_split < n_cols; subarray_split++)
  {
    left_subarray_value = 0;
    right_subarray_value = 0;
    for(uint32_t index = 0; index < n_cols; index++)
    {
      if(index < subarray_split)
        left_subarray_value += array[index];
      else
        right_subarray_value += array[index];
    }
    uint32_t diff = abs(left_subarray_value - right_subarray_value);
    if(diff < minimal_diff || subarray_split == 1)
    {
      minimal_diff = diff;
      minimal_subarray_split_position = subarray_split;
    }
  }
  printf("minimal is at index: %u and element: %u\n", minimal_subarray_split_position, array[minimal_subarray_split_position]);
  return minimal_diff;
}
