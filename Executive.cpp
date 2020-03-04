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

  m_cpuTime = new double[10]; // index 0-4 is cputime for quadratic probing, 5-9 is for DoubleHashing
  m_success = new int[10];  // index 0-4 is success for quadratic probing, 5-9 is for DoubleHashing
  m_notSuccess = new int[10]; // index 0-4 is not success for quadratic probing, 5-9 is for DoubleHashing
}
executive::~executive()
{
  delete[] m_arr1;
  delete[] m_arr2;
  delete[] m_arr3;
  delete[] m_arr4;
  delete[] m_arr5;

  delete[] m_cpuTime;
  delete[] m_success;
  delete[] m_notSuccess;
}

void executive::run()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  std::cout << "_____________________________________Performance (Quadratic Probing)_______________________________________\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Input size" << "\e[0m           |   100,000   |   200,000   |   300,000   |   400,000   |   500,000   |\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Builds(s)"  << "\e[0m            |" << m_cpuTime[0] << "     |" << m_cpuTime[1] << "     |" << m_cpuTime[2] << "     |" << m_cpuTime[3] << "     |"
            << m_cpuTime[4] << "     |\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Number of items" << '\n';
  std::cout << "\e[1m|  successfully found" << "\e[0m   |" << m_success[0] << "          |" << m_success[1] << "          |" << m_success[2] << "         |" << m_success[3] << "         |"
            << m_success[4] << "         |\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Number of items" << '\n';
  std::cout << "\e[1m|  not found" << "\e[0m            |" << m_notSuccess[0] << "         |" << m_notSuccess[1] << "        |" << m_notSuccess[2] << "       |" << m_notSuccess[3] << "         |"
            << m_notSuccess[4] << "        |\n";
  std::cout << "\e[1m___________________________________________________________________________________________________________\n\n\n\n\n";




  std::cout << "_____________________________________Performance (Double Hashing)_______________________________________\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Input size" << "\e[0m           |   100,000   |   200,000   |   300,000   |   400,000   |   500,000   |\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Builds(s)"  << "\e[0m            |" << m_cpuTime[5] << "     |" << m_cpuTime[6] << "     |" << m_cpuTime[7] << "     |" << m_cpuTime[8] << "     |"
            << m_cpuTime[9] << "     |\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Number of items" << '\n';
  std::cout << "\e[1m|  successfully found" << "\e[0m   |" << m_success[5] << "          |" << m_success[6] << "          |" << m_success[7] << "         |" << m_success[8] << "         |"
            << m_success[9] << "         |\n";
  std::cout << "___________________________________________________________________________________________________________\n";
  std::cout << "\e[1m|  Number of items" << '\n';
  std::cout << "\e[1m|  not found" << "\e[0m            |" << m_notSuccess[5] << "         |" << m_notSuccess[6] << "        |" << m_notSuccess[7] << "       |" << m_notSuccess[8] << "         |"
            << m_notSuccess[9] << "        |\n";
  std::cout << "\e[1m___________________________________________________________________________________________________________\n";
}

void executive::test1()
{
  double elapseQ = 0.0;
  double elapseD = 0.0;

  // Initializing the first array with input size of 0.1m
  int random;
  srand(time(NULL));
  int input = floor(1000003 * 0.1);

  for(int i = 0; i < input; i++)
  {
    random = rand() % 5000000 + 1;
    m_arr1[i] = random;
  }



  std::clock_t c_startQ = std::clock();
  // Inserting into HashTable for quadratic Probing
  for(int i = 0; i < input; i++)
  {
    m_hash1.insert_q(m_arr1[i]);
  }
  std::clock_t c_endQ = std::clock();
  elapseQ = ((double) c_endQ - c_startQ) / CLOCKS_PER_SEC;

  std::clock_t c_startD = std::clock();
  // Inserting into HashTable for doublehashing
  for(int i = 0; i < input; i++)
  {
    m_hash1.insert_d(m_arr1[i]);
  }
  std::clock_t c_endD = std::clock();
  elapseD = ((double) c_endD - c_startD) / CLOCKS_PER_SEC;



  // Searching in the HashTable
  int searchInput = floor(1000003 * 0.01);
  // quadratic Probing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash1.search_q(random);
  }
  // Doublehashing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash1.search_d(random);
  }

  m_cpuTime[0] = elapseQ;
  m_cpuTime[5] = elapseD;

  m_success[0] = m_hash1.getSuccess_q();
  m_success[5] = m_hash1.getSuccess_d();

  m_notSuccess[0] = m_hash1.getNotSuccess_q();
  m_notSuccess[5] = m_hash1.getNotSuccess_d();

}

void executive::test2()
{
  double elapseQ = 0.0;
  double elapseD = 0.0;

  // Initializing the first array with input size of 0.1m
  int random;
  srand(time(NULL));
  int input = floor(1000003 * 0.2);

  for(int i = 0; i < input; i++)
  {
    random = rand() % 5000000 + 1;
    m_arr2[i] = random;
  }



  std::clock_t c_startQ = std::clock();
  // Inserting into HashTable for quadratic Probing
  for(int i = 0; i < input; i++)
  {
    m_hash2.insert_q(m_arr2[i]);
  }
  std::clock_t c_endQ = std::clock();
  elapseQ = ((double) c_endQ - c_startQ) / CLOCKS_PER_SEC;

  std::clock_t c_startD = std::clock();
  // Inserting into HashTable for doublehashing
  for(int i = 0; i < input; i++)
  {
    m_hash2.insert_d(m_arr2[i]);
  }
  std::clock_t c_endD = std::clock();
  elapseD = ((double) c_endD - c_startD) / CLOCKS_PER_SEC;



  // Searching in the HashTable
  int searchInput = floor(1000003 * 0.02);
  // quadratic Probing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash2.search_q(random);
  }
  // Doublehashing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash2.search_d(random);
  }

  m_cpuTime[1] = elapseQ;
  m_cpuTime[6] = elapseD;

  m_success[1] = m_hash2.getSuccess_q();
  m_success[6] = m_hash2.getSuccess_d();

  m_notSuccess[1] = m_hash2.getNotSuccess_q();
  m_notSuccess[6] = m_hash2.getNotSuccess_d();

}

void executive::test3()
{
  double elapseQ = 0.0;
  double elapseD = 0.0;

  // Initializing the first array with input size of 0.1m
  int random;
  srand(time(NULL));
  int input = floor(1000003 * 0.3);

  for(int i = 0; i < input; i++)
  {
    random = rand() % 5000000 + 1;
    m_arr3[i] = random;
  }



  std::clock_t c_startQ = std::clock();
  // Inserting into HashTable for quadratic Probing
  for(int i = 0; i < input; i++)
  {
    m_hash3.insert_q(m_arr3[i]);
  }
  std::clock_t c_endQ = std::clock();
  elapseQ = ((double) c_endQ - c_startQ) / CLOCKS_PER_SEC;

  std::clock_t c_startD = std::clock();
  // Inserting into HashTable for doublehashing
  for(int i = 0; i < input; i++)
  {
    m_hash3.insert_d(m_arr3[i]);
  }
  std::clock_t c_endD = std::clock();
  elapseD = ((double) c_endD - c_startD) / CLOCKS_PER_SEC;



  // Searching in the HashTable
  int searchInput = floor(1000003 * 0.03);
  // quadratic Probing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash3.search_q(random);
  }
  // Doublehashing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash3.search_d(random);
  }

  m_cpuTime[2] = elapseQ;
  m_cpuTime[7] = elapseD;

  m_success[2] = m_hash3.getSuccess_q();
  m_success[7] = m_hash3.getSuccess_d();

  m_notSuccess[2] = m_hash3.getNotSuccess_q();
  m_notSuccess[7] = m_hash3.getNotSuccess_d();

}

void executive::test4()
{
  double elapseQ = 0.0;
  double elapseD = 0.0;

  // Initializing the first array with input size of 0.1m
  int random;
  srand(time(NULL));
  int input = floor(1000003 * 0.4);

  for(int i = 0; i < input; i++)
  {
    random = rand() % 5000000 + 1;
    m_arr4[i] = random;
  }



  std::clock_t c_startQ = std::clock();
  // Inserting into HashTable for quadratic Probing
  for(int i = 0; i < input; i++)
  {
    m_hash4.insert_q(m_arr4[i]);
  }
  std::clock_t c_endQ = std::clock();
  elapseQ = ((double) c_endQ - c_startQ) / CLOCKS_PER_SEC;

  std::clock_t c_startD = std::clock();
  // Inserting into HashTable for doublehashing
  for(int i = 0; i < input; i++)
  {
    m_hash4.insert_d(m_arr4[i]);
  }
  std::clock_t c_endD = std::clock();
  elapseD = ((double) c_endD - c_startD) / CLOCKS_PER_SEC;



  // Searching in the HashTable
  int searchInput = floor(1000003 * 0.04);
  // quadratic Probing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash4.search_q(random);
  }
  // Doublehashing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash4.search_d(random);
  }

  m_cpuTime[3] = elapseQ;
  m_cpuTime[8] = elapseD;

  m_success[3] = m_hash4.getSuccess_q();
  m_success[8] = m_hash4.getSuccess_d();

  m_notSuccess[3] = m_hash4.getNotSuccess_q();
  m_notSuccess[8] = m_hash4.getNotSuccess_d();

}

void executive::test5()
{
  double elapseQ = 0.0;
  double elapseD = 0.0;

  // Initializing the first array with input size of 0.1m
  int random;
  srand(time(NULL));
  int input = floor(1000003 * 0.5);

  for(int i = 0; i < input; i++)
  {
    random = rand() % 5000000 + 1;
    m_arr5[i] = random;
  }



  std::clock_t c_startQ = std::clock();
  // Inserting into HashTable for quadratic Probing
  for(int i = 0; i < input; i++)
  {
    m_hash5.insert_q(m_arr5[i]);
  }
  std::clock_t c_endQ = std::clock();
  elapseQ = ((double) c_endQ - c_startQ) / CLOCKS_PER_SEC;

  std::clock_t c_startD = std::clock();
  // Inserting into HashTable for doublehashing
  for(int i = 0; i < input; i++)
  {
    m_hash5.insert_d(m_arr5[i]);
  }
  std::clock_t c_endD = std::clock();
  elapseD = ((double) c_endD - c_startD) / CLOCKS_PER_SEC;



  // Searching in the HashTable
  int searchInput = floor(1000003 * 0.05);
  // quadratic Probing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash5.search_q(random);
  }
  // Doublehashing
  for(int i = 0; i < searchInput; i++)
  {
    random = rand() % 5000000 + 1;
    m_hash5.search_d(random);
  }

  m_cpuTime[4] = elapseQ;
  m_cpuTime[9] = elapseD;

  m_success[4] = m_hash5.getSuccess_q();
  m_success[9] = m_hash5.getSuccess_d();

  m_notSuccess[4] = m_hash5.getNotSuccess_q();
  m_notSuccess[9] = m_hash5.getNotSuccess_d();

}
