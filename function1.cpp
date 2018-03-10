#include <iostream>
using namespace std;

int addTwoNums(int x, int y);

int main(){
    int z = addTwoNums(2,3);

    cout << z << endl;
}


int addTwoNums(int x, int y){
    return x + y;
}
