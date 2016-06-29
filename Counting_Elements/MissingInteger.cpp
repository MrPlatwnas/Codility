/*
Author: Platon-Nikolaos Kiorpelidis
Purpose: Solution to problem MissingInteger from Codility.com
Date: 28-6-2016
Language: C++
*/

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

uint32_t solution(vector<int32_t> my_vector)
{
  bool *bool_table = NULL;
  bool_table = new bool[my_vector.size()];

  for(size_t i = 0; i < my_vector.size(); i++)
    bool_table[i] = false;

  vector<int32_t>::iterator it = my_vector.begin();
  for(size_t i = 0; i < my_vector.size(); i++)
  {
    if(my_vector[i] <= my_vector.size())
    {
      bool_table[my_vector[i] - 1] = true;
    }
  }

  for(size_t i = 0; i < my_vector.size(); i++)
  {
    if(bool_table[i] == 0)
      return(i + 1);
  }
}

int main()
{
  uint32_t num_integers;
  cin >> num_integers;  //reads the amount of numbers.

  int32_t *array = NULL;
  array = new int32_t[num_integers];  //creates the array.

  for(size_t i = 0; i < num_integers; i++)
  {
    cin >> array[i];  //reads the numbers.
  }

  vector<int32_t> my_vector(array, array + num_integers); //creates a vector and stores the array in it.

  uint32_t missing_element = solution(my_vector);

  cout << missing_element << endl;

  return 0;
}
