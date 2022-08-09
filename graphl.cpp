//
// Created by arwal on 2/29/2020.
//Anna Rowena Waldron

#include "graphl.h"

/*
 * Function to build a graph of nodes using as a parameter a file. Sets the size of the
 * graph with number ofnodes, and uses a for loop to call another function addNode
 * to create an object with parameters of the node index and a string descritpiton.
 * Calls another fucntion insertEdge using integer variables for the node and edge.
 */
void GraphL::buildGraph(ifstream &file) {
    string line = "";
    int numOfNodes = 0; //Number of nodes in the graph

    if(!(file>>numOfNodes)){
        return;
    }
    getline(file,line);
    this->size = numOfNodes; //just added

    for (int i = 1; i <= numOfNodes; i++){
        getline(file, line);
        this->addNode(i, line);
    }
    int node;
    int edge;
    while(file>>node>>edge) {
        if(node==0){
            return;
        }
        this->insertEdge(node, edge);
    }
}
/*
 * Simple function that creates a new node object for the graph by taking as parameter
 * an integer number for the node index, and string description and sets that index in
 * the array of graph nodes to it.
 */
void GraphL::addNode(int number, string name){
    G[number].data =  new NodeData(name);
}
/*
 * Function that inserts an edge of a node into the graph by taking as a parameter integer
 * node index and integer edge index, and creates a new Edgenode object and sets the
 * next edge variable and the adjacent node to the edge node index.
 */
void GraphL::insertEdge(int node, int edge){
    EdgeNode *temp;
    temp = G[node].edgeHead;
    G[node].edgeHead = new EdgeNode;
    G[node].edgeHead->nextEdge = temp;
    G[node].edgeHead->adjGraphNode = edge;
}
/*
 * Function to display the graph by rinting out that graphs nodes and edges. Uses a for
 * loop to get the node and then uses a while loop to get all edges for each node and
 * prints all this information.
 */
void GraphL::displayGraph(){
    std::cout << "Graph:\n";
    for(int i = 1; i <= size; i++){
        std::cout << "Node" << i << "\t\t" << *G[i].data << '\n';
        EdgeNode *head = G[i].edgeHead;
        while(head != nullptr){
            std::cout << "  " << "edge  " << i << "  " << head->adjGraphNode <<'\n';
            head = head->nextEdge;
        }
        std::cout << '\n';
    }
}
/*
 * Function that does a depth first traversal of the graph. Uses if statement to
 * make sure the graph is not empty then calls another recursive function depthfirsthelp
 * to print out the ordering.
 */
void GraphL::depthFirstSearch(){
    if(size > 0){
        std::cout << "Depth-first ordering:";
        depthFirstHelp(1);
        std::cout << "\n\n";
    }

}
/*
 * Recursive function that takes as a parameter the number of the node's index to the check
 * if that node was visited and if not to print out the number before entering a while loop
 * to get all the other nodes in the correct order by calling itself.
 */
void GraphL::depthFirstHelp(int nodeNumber){
    if(!G[nodeNumber].visited){
        G[nodeNumber].visited = true;
        std::cout << " "<< nodeNumber ;
        EdgeNode *currentEdge = G[nodeNumber].edgeHead;
        while(currentEdge != nullptr){
            depthFirstHelp(currentEdge->adjGraphNode);
            currentEdge = currentEdge->nextEdge;
        }
    }
}