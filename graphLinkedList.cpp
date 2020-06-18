#include <iostream>
#include <vector>
using namespace std;

class AdjacencyListNode{
    public:
    
    int graphNodeIndex;
    int weight;
    AdjacencyListNode* next;
};


class AdjacencyList{
    
    //Node is identified by its index in the adjacency list array
    public:
    
    AdjacencyListNode * head;
};

class AdjacencyListGraph{
    private:
    
    int num_nodes;
    vector<AdjacencyList*> adjancencyList;
    
    public:
    AdjacencyListGraph(int numNodes){
        num_nodes = numNodes;
       //Resizing initializes adjancencyList to size numNodes but adds new nodes after this position
       //leading to segmentation fault when trying to access node at position 0!
       // adjancencyList.resize(num_nodes);
    }

    //nodes are assumed to be created in sequence indexed by their position in adjacencyList
    void createNode(){
        AdjacencyList * n = new AdjacencyList();
        //cout << n->head << endl;
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

        AdjacencyList* adjList =  adjancencyList.at(i);
        //AdjacencyListNode* ll_node = adjListNode->head;

        
        AdjacencyListNode* new_node = new AdjacencyListNode();
        new_node->graphNodeIndex = j;
        new_node->weight = w;

        //new_node->next;
        //adjList->head;
        
        //cout << new_node->next << endl;// " :: " << adjList->head<<endl;
        //cout << adjList->head << endl;
  //      if(adjList->head == NULL){
  //          adjList->head = new_node;
  //      }else{
            new_node->next = adjList->head;
            adjList->head = new_node;
//        }
        //new_node->next = adjList->head;
        //adjList->head = new_node;

        /*
        if(ll_node == NULL){
            adjListNode->head = new_node;
            //Why do we need to re-assign to the vector?
            //adjancencyList.at(i) = gn_i; 
            //Answer: because when we didn't get reference to AdjacencyList element from the adjacency list,
            //it essentially created a new node and copied values from the list, hence gn_i was a new node
            //when gn_i.nextLinkedListNode is NULL, pointing it to new_node didn't change the original object's
            //pointer value
            //But when it already is initialized (when it goes to the else condition below), both gn_i and the 
            //vector element point to the same AdjacencyListNode through two different pointers hence any updating
            //is reflected in the original AdjacencyList too!
            //cout<<"Created next ll node for "<<i<<endl;
        }else{
            AdjacencyListNode* last_node = ll_node;

            while(ll_node != NULL){
                last_node = ll_node;
                ll_node = ll_node->nextLinkedListNode;
            }

            last_node->nextLinkedListNode = new_node;
            //cout<<"added next ll node "<<endl;
        }
        //adjancencyList.at(i) = gn_i;
        */
    }

    void printAllEdges(){
        for(int i = 0 ; i < num_nodes; i++){
            printNodeEdges(i);
        }
    }

    void printNodeEdges(int node_i){
        AdjacencyList* adjList = adjancencyList.at(node_i);

        AdjacencyListNode * nextLinkedListNode = adjList->head;

        cout << node_i << " -> ";

        while(nextLinkedListNode != NULL){
            //cout<<"looping "<<endl;
            cout << nextLinkedListNode->graphNodeIndex << " , ";
            nextLinkedListNode = nextLinkedListNode->next;
        }

        cout << endl;
    }
};

int main(){
    AdjacencyListGraph graph(5);

    graph.createNode();
    graph.createNode();
    graph.createNode();
    graph.createNode();
    graph.createNode();

    
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