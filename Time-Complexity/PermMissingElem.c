/*******************************************
File: PermMissingElem.c
Author: Platon-Nikolaos Kiorpelidis
Purpose: Solution to PermMissingElem problem
Date: 25 March 2016
Elapsed Time: 4 mins 20 secs
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t sequence(uint32_t);
uint32_t solution(uint32_t *, uint32_t);

int main(int argc, const char *argv[])
{
  uint32_t n_cols;
  printf("How many numbers will you enter?: ");
  scanf("%d", &n_cols);

  uint32_t *array = NULL;
  array = malloc(n_cols * sizeof(uint32_t));

  printf("Enter the numbers:\n");
  for(uint32_t counter = 0; counter < n_cols; counter++)
    scanf("%d", &array[counter]);

  printf("The number missing is: %u\n", solution(array, n_cols));
  return EXIT_SUCCESS;
}

uint32_t solution(uint32_t *array, uint32_t n_cols)
{
  uint32_t all_numbers = sequence(n_cols + 1);

  uint32_t array_numbers = 0;
  for(uint32_t counter; counter < n_cols; counter++)
    array_numbers += array[counter];

  return (all_numbers - array_numbers);
}

uint32_t sequence(uint32_t number)
{
  uint32_t sequence_value = 0;
  for(uint32_t counter = 0; counter <= number; counter++)
    sequence_value += counter;
  return sequence_value;
}
