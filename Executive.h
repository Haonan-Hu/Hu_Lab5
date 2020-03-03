/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "HashTable.h"
#include <math.h>
#include <ctime>

class executive
{
public:
  executive();
  ~executive();
  void run();

private:
  HashTable m_hash;

  int* m_arr1;
  int* m_arr2;
  int* m_arr3;
  int* m_arr4;
  int* m_arr5;
};
#endif
