#include<iostream>
using namespace std;
 
void swap(char * &str1, char * &str2)
{
  char *temp = str1;
  cout << &temp << endl;
  cout << &str1 << endl;
  str1 = str2;
  str2 = temp;
   cout<<"str1 is "<<str1<<endl;
  cout<<"str2 is "<<str2<<endl;
 
}
 
int main()
{
  char *str1 = "GEEKS";
  char *str2 = "FOR GEEKS";
  char * temp = str1;
  str1 = "lalala";
  //swap(str1, str2);
  cout<<"str1 is "<<str1<<endl;
  cout<<"str2 is "<<str2<<endl;
  cout << "temp is "<<temp<<endl;
  return 0;
}