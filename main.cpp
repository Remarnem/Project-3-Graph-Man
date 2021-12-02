// main.cpp
// Joshua Steege
// Section 2
// Last modified: 12/2/2021

#define INFILE "../graph.txt"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

void loadGraph(Graph *theGraph, const std::string& fileLocation);
void printMenu();

int main() {
    // Creating graph
    Graph theGraph;
    // Loading the file's data to the graph
    loadGraph(&theGraph, INFILE);

    int selection = 0;
    bool exit = false;

    while (!exit) {
        selection = -1;
        std::cout << std::endl;
        printMenu();
        // Ask for selection until valid selection is given
        while (selection > 6 || selection < 0) {
            std::cout << "Enter your selection:" << std::endl;
            std::cin >> selection;
        }
        // Selecting what code to run
        switch (selection) {
            case 0:
                exit = true;
                break;
            case 1:
                // Print adjacency matrix
                theGraph.printAdjacencyMatrix();
                break;
            case 2:
                // Print adjacency list
                theGraph.printAdjacencyList();
                break;
            case 3:
                // Making variables local
                for (int i = 0; i < 1; ++i) {
                    // Path variable for shortestPath()
                    std::vector<Vertex*> path = theGraph.shortestPath(theGraph.getNode(), theGraph.getNode());
                    // Calculate the path cost
                    int cost = 0;
                    for (auto i = 0; i < path.size()-1; i++) {
                        for (Edge *edge : *path[i]->getEdgeList()) {
                            if (edge->getDestination() == path[i+1]) {
                                cost += edge->getWeight();
                            }
                        }
                    }
                    // Print shortest path between two nodes
                    std::cout << "Path: ";
                    for (Vertex *node : path) {
                        std::cout << node->getName() << ", ";
                    }
                    std::cout << "\b\b " << std::endl;
                    std::cout << "Cost: " << cost << std::endl;
                }
                break;
            case 4:
                // Breadth-first search
                std::cout << "Nodes: ";
                theGraph.printNodes();
                std::cout << "Enter a node to search for:" << std::endl;
                for (auto i = 0; i < 1; i++) {
                    std::string input;
                    std::cin >> input;
                    std::cout << "Search result: " << Graph::breadthFirstSearch(input, theGraph.getNode())->getName() << std::endl;
                }
                break;
            case 5:
                // Depth-first search
                std::cout << "Nodes: ";
                theGraph.printNodes();
                std::cout << "Enter a node to search for:" << std::endl;
                for (auto i = 0; i < 1; i++) {
                    std::string input;
                    std::cin >> input;
                    std::cout << "Search result: " << Graph::depthFirstSearch(input, theGraph.getNode())->getName() << std::endl;
                }
                break;
            case 6:
                // Ordered Depth-first search
                std::cout << "Nodes: ";
                theGraph.printNodes();
                std::cout << "Enter a node to search for:" << std::endl;
                for (auto i = 0; i < 1; i++) {
                    std::string input;
                    std::cin >> input;
                    std::cout << "Search result: " << Graph::orderedDepthFirstSearch(input, theGraph.getNode())->getName() << std::endl;
                }
                break;
            default:
                std::cout << "Please enter a valid input." << std::endl;
                break;
        }
        std::cout << std::endl;
    }

    return 0;
}

// Loads the data from the file to the graph
void loadGraph(Graph *theGraph, const std::string& fileLocation) {
    // Opening file
    std::fstream fin;
    fin.open(fileLocation, std::ios::in);
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

// Print the menu
void printMenu() {
    std::cout << "GraphMan main menu:" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Please select from one of the following:" << std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cout << "[1] Print Adjacency Matrix" << std::endl;
    std::cout << "[2] Print Adjacency List" << std::endl;
    std::cout << "[3] Shortest Path Between Nodes" << std::endl;
    std::cout << "[4] Breadth-First Search" << std::endl;
    std::cout << "[5] Depth-First Search" << std::endl;
    std::cout << "[6] Ascending Degree Depth-First Search" << std::endl;
    std::cout << std::endl;
}