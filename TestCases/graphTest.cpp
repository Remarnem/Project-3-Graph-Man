// graphTest.cpp
// Joshua Steege
// Section 2
// Last modified: 11/30/2021

#define INFILE "../graph.txt"

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Graph.h"

int main() {
    Graph testGraph;
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
    int numNodes = stoi(line);
    // Creating the nodes
    for (int i = 0; i < numNodes; ++i) {
        getline(fin, line);
        while (line.empty()) { // Skip empty lines
            getline(fin, line);
        }
        testGraph.addNode(new Vertex(line));
    }
    // Creating the edges
    while (getline(fin, line)) {
        if (!line.empty()) { // Skips code if line is empty
            // Strings to store parts of line
            std::string source;
            std::string destination;
            std::string weight;
            // Converting line to an istream for getline
            std::istringstream iss(line);
            // Splitting the line into it's 3 parts
            getline(iss, source, ',');
            getline(iss, destination, ',');
            getline(iss, weight);
            // Calling add edge from graph
            testGraph.addEdge(source, destination, std::stoi(weight));
        }
    }

    testGraph.printAdjacency();

    std::string search = "e";
    //std::cout << "Search result: " << testGraph.breadthFirstSearch(search)->getName() << std::endl;
    //std::cout << "Search result: " << testGraph.depthFirstSearch(search)->getName() << std::endl;
    std::cout << "Search result: " << testGraph.orderedDepthFirstSearch(search)->getName() << std::endl;

    //TODO: Finish graph test case

    return 0;
}