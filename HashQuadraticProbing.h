#ifndef HASHQUADRATICPROBING_H
#define HASHQUADRATICPROBING_H

#include "Bucket.h"

template <class T>
class HashQuadraticProbing
{

public:

  //Constructor.
  HashQuadraticProbing(int hashSize, int K=10);

  //Destructor.
  ~HashQuadraticProbing();

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

  Bucket<T>* m_table; //Table - Pointer to many LinkedLists

};

#include "HashQuadraticProbing.hpp"

#endif
