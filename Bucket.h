#ifndef BUCKET_H
#define BUCKET_H


//This defines a Bucket. It adds functionality for a 'previously used' flag.
//By design, once the flag has been triggered, it cannot be unset.

template <class T>
class Bucket
{
public:

  //Constructor.
  Bucket(T value=NULL);

  //Trigger the flag.
  void triggerFlag();

  //Check flag state.
  bool checkFlag();

  //Set the value of this Bucket.
  void setValue(T value);

  //Get the value of this Bucket.
  T getValue();

private:

  bool m_flag;        //Flag
  T m_value;          //Value of the Bucket.

};

#include "Bucket.hpp"

#endif
