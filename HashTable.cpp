/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/
#include "HashTable.h"
#include <stdlib.h>

HashTable::HashTable()
{

}

HashTable::~HashTable()
{
  delete[] m_arr;
  delete[] m_Quadratic;
  delete[] m_DoubleHashing;
}

void HashTable::insert(int entry)
{

}

bool HashTable::search(int entry)
{
  return true;
}

int HashTable::quadraticProbing(int entry)
{
  return 1;
}

int doublehashing(int entry)
{
  return 1;
}

int doublehashing_plus(int entry)
{
  return 1;
}
