#ifndef HASHDOUBLE_H
#define HASHDOUBLE_H

#include "Bucket.h"

template <class T>
class HashDouble
{

public:

  //Constructor.
  HashDouble(int hashSize, int K=10, int P=13);

  //Destructor.
  ~HashDouble();

  //Insert an entry to the Hash table. Hash function implemented here.
  void insert(T value, int i=0);

  //Remove an entry from the Hash table.
  void erase(T value, int i=0);

  //Find a given value in the Hash table.
  bool find(T value, int i=0);

  //Print out the Hash table in a readable format.
  void print();

  //Print the current load factor of the Hash table.
  void printLoadFactor();


private:

  int m_tableSize;
  int m_K;
  int m_P;


  Bucket<T>* m_table; //Table - Pointer to many LinkedLists

};

#include "HashDouble.hpp"

#endif
