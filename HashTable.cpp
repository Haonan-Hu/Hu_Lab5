/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/
#include "HashTable.h"
#include <stdlib.h>
#include <math.h>

HashTable::HashTable()
{
  m_Quadratic = new int[m];
  m_DoubleHashing = new int[m];
}

HashTable::~HashTable()
{
  delete[] m_Quadratic;
  delete[] m_DoubleHashing;
}

void HashTable::insert(int entry)
{
  int index = 0;
  index = quadraticProbing(entry);
  if(index != -1)
  {
    m_Quadratic[index] = entry;
    // std::cout << index << "\n";
  }
  else
  {
    std::cout << "Error\n";
  }
}

void HashTable::search(int entry)
{
  if(found(entry))
  {
    success++;
  }
  else
  {
    notSuccess++;
  }
}

bool HashTable::found(int entry)
{
  bool found = false;
  for(int i = 0; i < k;i++)
  {
    int index = 0;
    if(i == 0)
    {
      index = entry % m;
    }
    else
    {
      index = (entry % m + i*i) % m;
    }

    if(m_Quadratic[index] == entry)
    {
      found = true;
      break;
    }
  }
  return found;
}

int HashTable::quadraticProbing(int entry)
{
  int index = -1;
  for(int i = 0; i < k; i++)
  {
    int temp = 0;
    if(i == 0)
    {
      temp = entry % m;
    }
    else
    {
      temp = (entry % m + i*i) % m;
    }
    if(m_Quadratic[temp] == 0)
    {
      index = temp;
      break;
    }
  }
  return index;
}

int HashTable::getSuccess()const
{
  return success;
}

int HashTable::getNotSuccess()const
{
  return notSuccess;
}

int doublehashing(int entry)
{
  return 1;
}

int doublehashing_plus(int entry)
{
  return 1;
}
