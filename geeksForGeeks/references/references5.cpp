#include<iostream>
using namespace std;
 
int main()
{
   int x = 10;
   int *ptr = &x;
   //https://stackoverflow.com/questions/17097632/is-it-possible-to-define-a-pointer-to-a-reference
   //int &*ptr1 = ptr; cannot create a pointer to a reference since reference is not an object
   cout << ptr << endl;
   cout << &x <<endl;
    cout << typeid(ptr).name() << endl;
    cout << typeid(x).name() << endl;
   int*&ptr2 = ptr;
   cout << typeid(ptr2).name() << endl;
   int *ptr3 = ptr;
   cout << typeid(ptr3).name() << endl;

   int & z = x;
   int * ptr4 = &z;
   cout << *ptr4 << endl;
   cout << &z << endl;
   cout << &x << endl;
   
}