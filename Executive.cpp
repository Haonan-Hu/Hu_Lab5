/*
Author: Haonan Hu
File: Executive.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Executive.h"
#include <iostream>

executive::executive()
{
  m_arr1 = new int[1000003];
  m_arr2 = new int[1000003];
  m_arr3 = new int[1000003];
  m_arr4 = new int[1000003];
  m_arr5 = new int[1000003];
}
executive::~executive()
{
  delete[] m_arr1;
  delete[] m_arr2;
  delete[] m_arr3;
  delete[] m_arr4;
  delete[] m_arr5;
}

void executive::run()
{
  double elapse = 0.0;


  // Initializing the first array with input size of 0.1m
  int random;
  srand(time(NULL));
  int input1 = floor(1000003 * 0.1);

  for(int i = 0; i < input1; i++)
  {
    random = rand() % 5000000 + 1;
    m_arr1[i] = random;
  }

  std::clock_t c_start = std::clock();
  // Inserting into HashTable
  for(int i = 0; i < input1; i++)
  {
    m_hash.insert(m_arr1[i]);
  }
  std::clock_t c_end = std::clock();
  elapse = ((double) c_end - c_start) / CLOCKS_PER_SEC;

  // Searching in the HashTable
  int searchInput = floor(1000003 * 0.01);
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash.search(random);
  }
  std::cout << m_hash.getSuccess() << '\n';
  std::cout << m_hash.getNotSuccess() << '\n';
  std::cout << "CPU time used: " << elapse << " s\n";

}
