#pragma once 


template <class T>
class Vector
{
public:
  Vector()
    : _start(nullptr)
    , _finish(nullptr)
    , _end_of_storage(nullptr)
  {}

  Vector(int n, const T& val = T())
    : _start(nullptr)
    , _finish(nullptr)
    , _end_of_storage(nullptr)
  {
    reserve(n);
    while (n--)
    {
      pushBack(val);
    }
  }

public:
  typedef T* Iterator;
  typedef const T* ConstIterator;

private:
  Iterator _start;
  Iterator _finish;
  Iterator _end_of_storage;
};
