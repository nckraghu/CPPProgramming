#include <iostream>
using namespace std;

int main(){

    char char1 = 23;

    cout << char1 << endl;

    char1 *= 2;

    cout << char1 << endl;
    
    int int1 = char1;

    cout << int1 << endl;

    bool flag1 = true;

    int1 = flag1;

    cout << int1 << endl;
    
    return 0;
}