#include<iostream>
using namespace std;
 
int main()
{
    //int x = 4;
   int *ptr = NULL;
   //https://stackoverflow.com/a/4009070/1412858
   //dereferencing a NULL pointer is undefined behavior
   //here for some reason the below line doesn't throw error
   int &ref = *ptr;
   //but this line throws segmentation fault
   //cout << ref;
   //also this line throws error
   //int z = *ptr;

}