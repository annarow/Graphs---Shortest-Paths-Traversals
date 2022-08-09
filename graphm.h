//
// Created by arwal on 2/25/2020.
//Anna Rowena Waldron

#ifndef ASSIGN_3_GRAPHM_H
#define ASSIGN_3_GRAPHM_H
#include "nodedata.h"
#include <fstream>

class GraphM{
public:
    void buildGraph(ifstream &infile1);
    void addNode(int number, string name);
    void display(const int &start, const int &end) const;
    void insertEdge(int node, int edge, int cost);
    void removeEdge(int node, int edge);
    int find(int source);
    string findPath(const int &start, const int& end) const;
    void findShortestPath();
    void displayAll();
    //Default constructor for graph object that sets size of graph to 0 and uses a
    //for loop to set all items to max number 10000 in the adjacency matrix C.
    GraphM(){
        size = 0;
        for(int i = 1; i <= MAXNODES; i++){
            for(int j = 1; j <= MAXNODES; j++){

                    C[i][j] = 10000;


            }

        }
    }
private:
    static const int MAXNODES = 120;
    NodeData data[MAXNODES];   // data for graph nodes
    int C[MAXNODES][MAXNODES];  // Cost array, the adjacency matrix
    int size;

    struct TableType{
        bool visited;
        int dist;
        int path;
        //Helper struct constructor that sets visited variable to false, integer path variable is set to 0 and dist
        //interger variable is set to max number 10000 to show infinity.
        TableType(){
            visited = false;
            path = 0;
            dist = 10000;
        }

    };
    TableType T[MAXNODES][MAXNODES];    // stores visited, distance, path

};

#endif //ASSIGN_3_GRAPHM_H