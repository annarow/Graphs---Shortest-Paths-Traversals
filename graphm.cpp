//
// Created by arwal on 2/25/2020.
//Anna Rowena Waldron
//February 29, 2020
//Assignment 3 CSS 343

#include "graphm.h"
#include <sstream>

/*
 * Function that builds a graph by taking a parameter of a file.
 * Sets the size of the graph, and uses a for loop to call another function addNode
 * to create a node object with parameters of node number and a string description.
 */
void GraphM::buildGraph(ifstream &file) {
    string line = "";
    int numOfNodes = 0; //Number of nodes in the graph
        if(!(file>>numOfNodes)){
            return;
        }
        getline(file,line);

        this->size = numOfNodes;  //assign size of graph
        for (int i = 1; i <= numOfNodes; i++){
            getline(file, line);
            this->addNode(i, line); //Assign each string to the corresponding node
        }
        int node;
        int edge;
        int cost;

        while(file>>node>>edge>>cost) {
            getline(file, line);
            if(node==0){
                return;
            }
            this->insertEdge(node, edge, cost);
        }
}

/*
 * Simple function that takes integers as parameters to set the adjacency matrix with proper
 * numbering with the node and edge and setting it equal to the edge distance cost.
 */
void GraphM::insertEdge(int numNode, int numEdge, int numCost){
    this->C[numNode][numEdge] = numCost;
}
/*
 * Simple function that sets the cost distance of an edge to the infinity number.
 * Takes an integer node number and integer edge number for matrix placement of node.
 */
void GraphM::removeEdge(int node, int edge){
    this->C[node][edge] = 10000;
}
/*
 * Simple function that takes integer number for node placement in array, and string
 * description of the node and adds the node to the array.
 */
void GraphM::addNode(int number, string name) {
    this->data[number] = NodeData(name);
}
/*
 * Function to display the graph by using nested for loops to go through the matrix
 * of cost and tableType matrix to print out the node, its edge, cost of distance.
 * Calls another function for the path of shortest distance between nodes, findPath.
 */
void GraphM::displayAll() {
    std::cout << "Description\t\t  From Node  To Node  Dijkstra's  Path"  << "\n";
    for(int i = 1; i < size + 1; i++){
        std::cout << this->data[i] << "\n";
        for(int j = 1; j < size +1; j++){
            if(i != j){ //dist to diff node
                std::cout << "\t\t\t\t" << i << "\t";
                if(T[i][j].dist < 10000){
                    std::cout << j << "\t" << T[i][j].dist <<"\t";
                    std::cout << findPath(i, j) + "\n";
                }else{
                    std::cout << j << "\t" << "---" << "\n";
                }
            }

        }
        std::cout << "\n";
    }
}
/*
 * Function that returns a string and takes parameters of integer reference of the
 * first node, and interger reference of the end node, to find the path recursively.
 */
string GraphM::findPath(const int &start, const int& end) const{
    if(start == end){
        return to_string(start);
    }else{
        return findPath(start, T[start][end].path) + ' ' + to_string(end);
    }
}

/*
 * Function to display the path of a parameter passed node and its destination node.
 * takes as a parameter integer reference start node and end node.
 * Prints out the path and calls the function findPath to get the path.
 */
void GraphM::display(const int &start, const int &end) const {

    std::cout << "Path for: \t\t\t" << start << "\t" << end << "\t";
    if(T[start][end].dist != 10000){
        string route = findPath(start, end);
        stringstream stream(route);
        int current;
        std::cout << T[start][end].dist << "\t" << route << '\n';
        while (stream >> current) {
            std::cout << data[current] << "\n";
        }
    }else{
        std::cout << "---\n";
    }
    std::cout << '\n';
}

/*
 * Function to find the shortest path from each node to each other node, and calls
 * the function findPath to find the least distance between nodes. Uses 3 nested
 * for loops for cycling through matrixs and set the path variable to the closest
 * node to it.
 */
void GraphM::findShortestPath(){
    for(int source = 1; source <= this->size; source++){
        this->T[source][source].dist = 0;
        for(int i = 1; i<= this->size; i++){
            int v = find(source);

            T[source][v].visited = true;
            for(int w = 1; w <= size; w++){
                if(C[v][w] < 10000){
                    if(T[source][v].dist + C[v][w] < T[source][w].dist){
                        T[source][w].dist = T[source][v].dist + C[v][w];
                        T[source][w].path = v;
                    }
                }
            }
        }
    }
}
/*
 * Function that uses a paramter integer source that is the origin of the path to be
 * traveled. Return the node index of the least distance to the source, using two
 * seperate for loops to find the min. Returns the min index.
 */
int GraphM::find(int source){
    int min = -1;
    for(int i = 1; i <= size; i++) {
        if (!T[source][i].visited && T[source][i].dist < 10000) {
            min = i;
        }
    }
    if(min < 0){
        return source;
    }
    for(int j = min + 1; j <= size; j++){
        if(!T[source][j].visited && T[source][j].dist < T[source][min].dist){
            min = j;
        }
    }
    return min;
}


