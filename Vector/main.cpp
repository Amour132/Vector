#include "Vector.h"

int main()
{
   djh::Vector<int> v1;
   v1.PushBack(1);
   v1.PushBack(2);
   v1.PushBack(3);
   v1.Pop();
   djh::Vector<string> v2;
   v2.PushBack("hello");
   v2.PushBack(" world");
   v2.Pop();
   v1.print();
   v2.print();
   return 0;
}
