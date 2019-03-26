
#include <iomanip> //Output formatting convenience
#include "HashQuadraticProbing.h"

//Constructor - contains initialization of structure.
//Default parameter: m_K = 10
template <class T>
HashQuadraticProbing<T>::HashQuadraticProbing(int hashSize, int K)
{
  m_tableSize = hashSize;
  m_K = K;
  m_table = new Bucket<T>[m_tableSize];
}

//Destructor - proper deletion of the structure implemented here.
template <class T>
HashQuadraticProbing<T>::~HashQuadraticProbing()
{
  delete[] m_table;
  std::cout << "\n\n";
}

//Insert a given value to the Hash table. Hash function implemented here.
//This implementation uses a recursive strategy which takes advantage of quadratic probing.
//Default Parameter: i = 0
template <class T>
void HashQuadraticProbing<T>::insert(T value, int i)
{
    //Failed to insert
    if (i > (m_K - 1)) {
      std::cout << "\nError: failed to insert " << value << " with quadratic probing\n";
      return;
    }

    //Convenience for accessing current probe point
    Bucket<T>* probePoint = &m_table[(value + (i * i)) % m_tableSize];

    //Recursive logic
    if (probePoint->getValue()) {
      if (probePoint->getValue() == value) std::cout << "\nError: duplicate of " << value << " found.";
      else insert(value, i + 1);
    } else {
      probePoint->setValue(value);
      std::cout << "\n" << value << " added to table with quadratic probing";
      printLoadFactor();
    }
}

//Erase a given value from the Hash table.
template <class T>
void HashQuadraticProbing<T>::erase(T value, int i)
{
  //Failed to erase
  if (i > (m_K - 1)) {
    std::cout << "\n" << value << " could not be remove from the table with quadratic probing";
    return;
  }

  //Convenience for accessing current probe point
  Bucket<T>* probePoint = &m_table[(value + (i * i)) % m_tableSize];

  //Recursive logic
  if (probePoint->checkFlag()) {
    if (probePoint->getValue()) {
      if (probePoint->getValue() == value) { //Removal action
        probePoint->setValue(NULL);
        std::cout << "\n" << value << " removed from table with quadratic probing.";
        printLoadFactor();
      } else erase(value, i + 1);
    } else erase(value, i + 1);
  } else std::cout << "\n" << value << " was not found.";
}

//Print the Hash table in a readable format.
template <class T>
void HashQuadraticProbing<T>::print()
{
  std::cout << "\n\n------Hash Table with Quadratic Probing------";
  for (int i = 0; i < m_tableSize; i++) if (m_table[i].getValue()) std::cout << "\n" << i << ": " << m_table[i].getValue();
  printLoadFactor();
}

//Find a given value in the Hash table.
template <class T>
bool HashQuadraticProbing<T>::find(T value, int i)
{
  //Failed to find
  if (i > (m_K - 1)) {
    std::cout << "\nFailed to find " << value << " in the table with quadratic probing.";
    return false;
  }

  //Convenience for accessing current probe point
  Bucket<T>* probePoint = &m_table[(value + (i * i)) % m_tableSize];

  //Recursive logic
  if (probePoint->checkFlag()) {
    if (probePoint->getValue()) {
      if (probePoint->getValue() == value) { //Removal action
        std::cout << "\n" << value << " found in table with quadratic probing.";
        return true;
      } else find(value, i + 1);
    } else find(value, i + 1);
  } else std::cout << "\n" << value << " was not found.";
  return false;
}

//Print the current load factor of the Hash table.
template <class T>
void HashQuadraticProbing<T>::printLoadFactor()
{
  float n = 0;
  for (int i = 0; i < m_tableSize; i++) if (m_table[i].getValue() != NULL) n++;
  float loadFactor = n / m_tableSize;
  std::cout << "\nLoad factor with quadratic probing is " << std::setprecision(2) << std::fixed << loadFactor;
}
