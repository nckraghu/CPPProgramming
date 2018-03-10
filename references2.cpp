#include <iostream>
using namespace std;

int fun(const int &x){
    return x;
}

int main(){
    
    cout << fun(3);
    return 0;
}