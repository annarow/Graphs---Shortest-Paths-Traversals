#include <iostream>
#include <fstream>
#include "graphm.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ifstream myFile("data31.txt");
    GraphM test;
    test.buildGraph(myFile);
    test.findShortestPath();
    test.displayHelp();
    return 0;
}
