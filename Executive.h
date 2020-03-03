/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "HashTable.h"
#include <fstream>

class executive
{
public:
  HashTable m_hash;
  ~executive(){};
  /**
  * @pre none
  * @post run the user controled panel
  */
  void run();

};
#endif
