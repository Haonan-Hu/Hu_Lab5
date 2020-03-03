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
  void insert(int entry);
  bool search(int entry);

private:
  int* m_arr; //the original random number array of size 1000003
  int* m_Quadratic; // quadratic probing method hash table
  int* m_DoubleHashing; // Double hashing

  int m = 1000003 ; // HashTable size m
  int R = 773;  // Double hashing value
  int k = 25; //Maximum k value

  int quadraticProbing(int entry);
  int doublehashing(int entry);
  int doublehashing_plus(int entry);
};
#endif
