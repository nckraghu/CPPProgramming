#include <iostream>
#include <vector>
using namespace std;

class LinkedListNode{
    public:
    
    int graphNodeIndex;
    int weight;
    LinkedListNode* nextLinkedListNode;
};


class GraphNode{
    
    //Node is identified by its index in the adjacency list array
    public:
    int value;
    LinkedListNode * nextLinkedListNode;
};

class AdjacencyListGraph{
    private:
    
    int num_nodes;
    vector<GraphNode> adjancencyList;
    
    public:
    AdjacencyListGraph(int numNodes){
        num_nodes = numNodes;
        adjancencyList.resize(num_nodes);
    }

    void createNode(int v){
        GraphNode n;
        n.value = v;
        adjancencyList.push_back(n);
    }

    void addEdgeBetweenIAndJ(int i, int j, int w){
        addEdgeFromIToJ(i, j, w);
        addEdgeFromIToJ(j, i, w);
    }

    //add edge from i to j
    void addEdgeFromIToJ(int i, int j, int w){
        if( i > adjancencyList.size() - 1 || j > adjancencyList.size() - 1){
            cout << "error"<<endl;
            return;
        }

        GraphNode& gn_i =  adjancencyList.at(i);
        LinkedListNode* ll_node = gn_i.nextLinkedListNode;

        LinkedListNode* new_node = new LinkedListNode();
        new_node->graphNodeIndex = j;
        new_node->weight = w;


        if(ll_node == NULL){
            gn_i.nextLinkedListNode = new_node;
            //Why do we need to re-assign to the vector?
            //adjancencyList.at(i) = gn_i; 
            //cout<<"Created next ll node for "<<i<<endl;
        }else{
            LinkedListNode* last_node = ll_node;

            while(ll_node != NULL){
                last_node = ll_node;
                ll_node = ll_node->nextLinkedListNode;
            }

            last_node->nextLinkedListNode = new_node;
            //cout<<"added next ll node "<<endl;
        }
        //adjancencyList.at(i) = gn_i;
    }

    void printAllEdges(){
        for(int i = 0 ; i < num_nodes; i++){
            printNodeEdges(i);
        }
    }

    void printNodeEdges(int node_i){
        GraphNode gi = adjancencyList.at(node_i);

        LinkedListNode * nextLinkedListNode = gi.nextLinkedListNode;

        cout << node_i << " -> ";

        while(nextLinkedListNode != NULL){
            //cout<<"looping "<<endl;
            cout << nextLinkedListNode->graphNodeIndex << " , ";
            nextLinkedListNode = nextLinkedListNode->nextLinkedListNode;
        }

        cout << endl;
    }
};

int main(){
    AdjacencyListGraph graph(5);

    graph.createNode(0);
    graph.createNode(1);
    graph.createNode(2);
    graph.createNode(3);
    graph.createNode(4);

    graph.addEdgeBetweenIAndJ(0, 1, 4);
    graph.addEdgeBetweenIAndJ(0, 3, 3);
    graph.addEdgeBetweenIAndJ(1, 2, 3);
    graph.addEdgeBetweenIAndJ(1, 4, 7);
    graph.addEdgeBetweenIAndJ(3, 2, 5);
    graph.addEdgeBetweenIAndJ(2, 4, 2);

    graph.printAllEdges();

    cout << "Hello World" << endl;
    return 0;
}