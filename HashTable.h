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
  void search(int entry);
  int getSuccess()const;
  int getNotSuccess()const;

private:
  int* m_Quadratic; // quadratic probing method hash table
  int* m_DoubleHashing; // Double hashing

  int m = 1000003 ; // HashTable size m
  int R = 773;  // Double hashing value
  int k = 25; //Maximum k value
  int success = 0;
  int notSuccess = 0;

  bool found(int entry);
  int quadraticProbing(int entry);
  int doublehashing(int entry);
  int doublehashing_plus(int entry);
};
#endif
