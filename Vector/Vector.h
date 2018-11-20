#pragma once 

#include <assert.h>
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

  const iterator cbegin()const 
  {
    return _start;
  }
  
  const iterator cend()const 
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

  Vector(const Vector<T>& v):_start(NULL)
                             ,_finish(NULL)
                             ,_endofstorage(NULL)
  {
    Reserve(v.Capacity());
    iterator it = begin();
    const iterator vit = cbegin();
    while(vit != cend())
    {
      *it++ = *vit++;
    }
    _finish = _start + v.Size();
    _endofstorage = _start + v.Capacity();
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
  void Reserve(size_t n)
  {
    if(n > Capacity())
    {
      size_t size = Size();
      T* tmp = new T[n];
      if(_start)
      {
        for(size_t i=0; i<size; i++)
        {
          tmp[i] = _start[i];
        }
      }
      _start = tmp;
      _finish = _start + size;
      _endofstorage = _start + n;
    }
  }

  void Resize(size_t n,const T& value = T())
  {
    if(n<Capacity())
    {
      _finish = _start + n;
      return;
    }
    if(n>Capacity())
    {
      Reserve(n);
    }
    iterator it = _finish;
    iterator _finish = _start + n;
    while(it != _finish)
    {
      *it = value;
      it++; 
    }
  }

  void PushBack(const T& x)
  {
    Insert(end(),x);
  }

  void Pop()
  {
    Earse(end()-1);
  }

  iterator Insert(iterator pos,const T& x)
  {
    assert(pos<=_finish);

    if(_endofstorage == _finish)
    {
      size_t size = Size();
      size_t newcapacity;
      if(Capacity() == 0)
      {
        newcapacity = 1;
      }
      else
      {
        newcapacity = 2*Capacity();
      }
      Reserve(newcapacity);
      pos = _start + size;
    }
    iterator end = _finish -1;
    while(end >= pos)
    {
      *(end+1) = *end;
      end--;
    }
    *pos = x;
    ++_finish;
    return pos;
  }

  iterator Earse(iterator pos)
  {
    iterator begin = pos + 1;
    while(begin != _finish)
    {
      *(begin-1) = *begin;
      begin++;
    }
    _finish--;
    return pos;
  }

  void print()
  {
    iterator it = begin();
    while(it != end())
    {
      cout<<*it<<"-";
      it++;
    }
    cout<<endl;
  }
  
private:
  T* _start;
  T* _finish;
  T* _endofstorage;
};
}


