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
    // Creating line to store txt input
    std::string line;
    // Getting the number of nodes
    getline(fin, line);
    while (line.empty()) { // Skip empty lines
        getline(fin, line);
    }
    std::cout << "Field: " << line << std::endl;
    int numNodes = stoi(line);
    // Creating the nodes
    for (int i = 0; i < numNodes; ++i) {
        getline(fin, line);
        while (line.empty()) { // Skip empty lines
            getline(fin, line);
        }
        std::cout << line << std::endl;
        theGraph.addNode(new Vertex(line));
    }
    // Creating the edges
    while (getline(fin, line)) {
        while (line.empty()) { // Skip empty lines
            getline(fin, line);
        }
        // Strings to store
        std::string source;
        std::string destination;
        std::string weight;
        // Variables to store actual values
        Vertex *sourceNode;
        Vertex *destinationNode;
        // TODO: Search nodes for source and destination address
        // TODO: Create and add edge to graph
    }
    return 0;
}
