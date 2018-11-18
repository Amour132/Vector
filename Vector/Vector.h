#pragma once 

#include <iostream>
#include <string.h>
using namespace std;

namespace djh
{
template<class T>
class Vector
{
public:
  typedef T* iterator;

  iterator begin()
  {
    return _start;
  }

  iterator end()
  {
    return _finish;
  }
  
  size_t Size() const
  {
    return _finish - _start;
  }

  size_t Capacity() const 
  {
    return _endofstorage - _start;
  }

  T& operator[](size_t pos)
  {
    assert(pos<Size());
    return _start[pos];
  }

  const T& operator[](size_t pos) const
  {
    assert(pos<Size());
    return _start[pos];
  }

  Vector():_start(NULL)
           ,_finish(NULL)
           ,_endofstorage(NULL)
  {}

  Vector(const Vector& v)
  {
    v._start = (T*)memcpy(&v._start,&_start,sizeof(T)*Capacity());
    v._finish = v._start + Size();
    v._endofstorage = v._start + Capacity();
  }

  ~Vector()
  {
    if(_start)
    {
      delete[] _start;
      _start = _finish = _endofstorage = NULL;
    }
  }
  
  void Swap(Vector &v)
  {
    swap(v._start,_start);
    swap(v._finish,_finish);
    swap(v._endofstorage,_endofstorage);
  }

  Vector& operator==(Vector v)
  {
    *this->Swap(v);
    return *this;
  }

  //成员函数
  void Reserve(size_t n);
  void Resize(size_t n,const T& val = T());
  void PushBack(const T& x);
  void Pop();
  void Insert(iterator pos,const T& x);
  iterator Earse(iterator pos);
  
private:
  T* _start;
  T* _finish;
  T* _endofstorage;
};
}


