#include <iostream>
#include <vector>
using namespace std;


class Node{
    public:

    int value;
};

class NodeArray{
    public:
    vector<Node> node_array;

    void printValues(){
        for(int i = 0; i < node_array.size() ; i++){
            cout<<node_array.at(i).value<<endl;
        }
    }
};

int main(){
    NodeArray n;
    
    Node n1;
    n1.value = 2;
    n.node_array.push_back(n1);

    n.printValues();
    
    Node& n2 = n.node_array.at(0);
    n2.value = 3;

    n.printValues();

    Node n3; n3.value = 3;
    Node n4 = n3;
    cout << &n3 << endl;
    cout << &n4 << endl;
    /*
    cout << n4.value << endl;
    n4.value = 4;
cout << n3.value << endl;
    cout << n4.value << endl;
    */
    return 0;
}

