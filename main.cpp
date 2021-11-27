// main.cpp
// Joshua Steege
// Section 2
// Last modified: 11/27/2021

#define INFILE "../graph.txt"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

void loadGraph(Graph *theGraph, const std::string& fileLocation);

int main() {
    // Creating graph
    Graph theGraph;
    // Loading the file's data to the graph
    loadGraph(&theGraph, INFILE);

    theGraph.printAdjacency();

    return 0;
}

// Loads the data from the file to the graph
void loadGraph(Graph *theGraph, const std::string& fileLocation) {
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
    //std::cout << "Line: " << line << std::endl;
    int numNodes = stoi(line);
    // Creating the nodes
    for (int i = 0; i < numNodes; ++i) {
        getline(fin, line);
        while (line.empty()) { // Skip empty lines
            getline(fin, line);
        }
        //std::cout << line << std::endl;
        theGraph->addNode(new Vertex(line));
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
            theGraph->addEdge(source, destination, std::stoi(weight));
        }
    }
}