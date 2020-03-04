/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

class HashTable
{
public:
  HashTable();
  ~HashTable();

  bool isEmptry()const;
  void insert_q(int entry);
  void insert_d(int entry);

  void search_q(int entry);
  void search_d(int entry);

  int getSuccess_q()const;
  int getNotSuccess_q()const;

  int getSuccess_d()const;
  int getNotSuccess_d()const;

private:
  int* m_Quadratic; // quadratic probing method hash table
  int* m_DoubleHashing; // Double hashing

  int m = 1000003 ; // HashTable size m
  int R = 773;  // Double hashing value
  int k = 25; //Maximum k value

  int success_q = 0;
  int notSuccess_q = 0;

  int success_d = 0;
  int notSuccess_d = 0;

  bool found_q(int entry);
  bool found_d(int entry);
  int quadraticProbing(int entry);
  int doublehashing(int entry);
  int doublehashing_plus(int entry);
};
#endif
