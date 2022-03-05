#include <iostream>
#include <vector>
using namespace std;


/*
    Calculating Trie data structure pointer sizes
    Ref: https://www.cs.upc.edu/~ps/downloads/tst/tst.html
*/
class TrieNode {
    public:

    const int NUM_ASCII = 26;

    const long LONG_VALUE = 34;

    const long long LONG_LONG_VALUE = 34;

    TrieNode* next;

};

int main() {


    TrieNode* trieNode = new TrieNode();

    printf("Hello World\n");

    printf("%d\n", sizeof(trieNode));

    printf("%d\n", sizeof(trieNode->NUM_ASCII));

    printf("%d\n", sizeof(trieNode->LONG_VALUE));

    printf("%d\n", sizeof(trieNode->LONG_LONG_VALUE));

    printf("%d\n", sizeof(trieNode->next));

    return 0;
}
