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
  void test1(); // recording success/not success search number and cpu time for 0.1m
  void test2(); // recording success/not success search number and cpu time for 0.1m
  void test3(); // recording success/not success search number and cpu time for 0.1m
  void test4(); // recording success/not success search number and cpu time for 0.1m
  void test5(); // recording success/not success search number and cpu time for 0.1m

private:
  HashTable m_hash1;
  HashTable m_hash2;
  HashTable m_hash3;
  HashTable m_hash4;
  HashTable m_hash5;

  int* m_arr1;
  int* m_arr2;
  int* m_arr3;
  int* m_arr4;
  int* m_arr5;

  double* m_cpuTime;
  int* m_success;
  int* m_notSuccess;
};
#endif
