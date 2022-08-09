//
// Created by arwal on 2/29/2020.
//Anna Rowena Waldron

#ifndef ASSIGN_3_GRAPHL_H
#define ASSIGN_3_GRAPHL_H
#include "nodedata.h"

class GraphL{
public:
    void buildGraph(ifstream &infile2);
    //Default constructor for GraphL object that sets the size of the graph to 0.
    GraphL() {
        size = 0;
    }
    //Deconstructor for GraphL object that uses a for loop to delete all objects
    //in the array of GraphNodes. Calls both GraphNode and EdgeNode deconstructors.
    ~GraphL() {
        for (int i = 1; i <= size; i++) {
            delete G[i].edgeHead;
            delete G[i].data;
        }
    };
    void addNode(int number, string name);
    void insertEdge(int node, int edge);
    void displayGraph();
    void depthFirstSearch();
    void depthFirstHelp(int nodeNumber);
private:
    static const int MAXNODES = 120;
    struct EdgeNode;
    struct GraphNode{
        EdgeNode* edgeHead;
        NodeData* data;
        bool visited;
        //Default constructor of GraphNode object that sets both pointers edgeHead and
        //data to nullptr and sets visited to false.
        GraphNode(){
            edgeHead = nullptr;
            data = nullptr;
            visited = false;
        }
    };
    struct EdgeNode{
        int adjGraphNode;
        EdgeNode* nextEdge;
        //Default constructor for EdgeNode that sets adjacent node variable to 0 and next
        //edge pointer to nullptr.
        EdgeNode(){
            adjGraphNode = 0;
            nextEdge = nullptr;
        }
        //EdgeNode deconstructor that deletes the pointer nextedge.
        ~EdgeNode(){
            delete nextEdge;
        }
    };
    GraphNode G[MAXNODES];
    int size;   //size of graphs or number of nodes in graph.
};



#endif //ASSIGN_3_GRAPHL_H
