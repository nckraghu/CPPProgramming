#include <iostream>
using namespace std;


void recurse(int count){

    int x = count;
    // int z = 20;
    // int y = 3;
    // int l[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // int l[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int * p = &x;
    p += 2*16;
    cout << "Address of x : " << &x;
    cout << "\t\tvalue of x: " << x;// << endl;
    cout << "\t\tvalue of ptr p: " << *p << endl;

    // cout << "Address of z : " << &z << endl;
    // cout << "Address of y : " << &y << endl;


    if(count > 10)
        return;
    recurse(count+1);
    
}


int main(){
    recurse(0);
    return 0;
}