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
  for(int i = 0; i < m; i++)
  {
    m_Quadratic[i] = 0;
    m_DoubleHashing[i] = 0;
  }
}

HashTable::~HashTable()
{
  delete[] m_Quadratic;
  delete[] m_DoubleHashing;
}

void HashTable::insert_q(int entry)
{
  int index = 0;
  index = quadraticProbing(entry);
  if(index != -1)
  {
    m_Quadratic[index] = entry;
  }
}

void HashTable::insert_d(int entry)
{
  int index = 0;
  index = doublehashing(entry);
  if(index != -1)
  {
    m_DoubleHashing[index] = entry;
  }
}

void HashTable::search_q(int entry)
{
  if(found_q(entry))
  {
    success_q++;
  }
  else
  {
    notSuccess_q++;
  }
}

void HashTable::search_d(int entry)
{
  if(found_d(entry))
  {
    success_d++;
  }
  else
  {
    notSuccess_d++;
  }
}

bool HashTable::found_q(int entry)
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

bool HashTable::found_d(int entry)
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
      index = (entry % m + i * doublehashing_plus(entry)) % m;
    }

    if(m_DoubleHashing[index] == entry)
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
      temp = (entry % m + i * i) % m;
    }
    if(m_Quadratic[temp] == 0)
    {
      index = temp;
      break;
    }
  }
  return index;
}

int HashTable::doublehashing(int entry)
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
      temp = (entry % m + i * doublehashing_plus(entry)) % m;
    }
    if(m_DoubleHashing[temp] == 0)
    {
      index = temp;
      break;
    }
  }
  return index;
}

int HashTable::doublehashing_plus(int entry)
{
  int h = R - (entry % R);
  return h;
}

int HashTable::getSuccess_q()const
{
  return success_q;
}

int HashTable::getNotSuccess_q()const
{
  return notSuccess_q;
}

int HashTable::getSuccess_d()const
{
  return success_d;
}

int HashTable::getNotSuccess_d()const
{
  return notSuccess_d;
}
