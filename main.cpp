// main.cpp
// Joshua Steege
// Section 2
// Last modified: 11/23/2021

#define INFILE "../graph.txt"

#include <iostream>
#include <fstream>
#include "Graph.h"

int main() {
    // Creating graph
    Graph theGraph;
    // Opening file
    std::fstream fin;
    fin.open(INFILE, std::ios::in);
    // Creating field to store txt input
    std::string field;
    // Getting the number of nodes
    getline(fin, field);
    std::cout << "Field: " << field << std::endl;
    int numNodes = stoi(field);
    // Creating the nodes
    for (int i = 0; i < numNodes; ++i) {
        getline(fin, field);
        std::cout << field << std::endl;
        theGraph.addNode(new Vertex(field));
    }
    // Creating the edges
    return 0;
}
