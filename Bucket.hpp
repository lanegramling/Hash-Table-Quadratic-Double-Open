
#include "Bucket.h"

template <class T>
Bucket<T>::Bucket(T value)
{
 m_value = value;
 m_flag = false;
}

template <class T> //Trigger the flag.
void Bucket<T>::triggerFlag() { m_flag = true; }

template <class T> //Check the flag.
bool Bucket<T>::checkFlag() { return m_flag; }

template <class T>
void Bucket<T>::setValue(T value)
{
  m_value = value;
  triggerFlag();
}

template <class T>
T Bucket<T>::getValue() { return m_value; }
