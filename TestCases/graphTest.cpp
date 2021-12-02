// graphTest.cpp
// Joshua Steege
// Section 2
// Last modified: 12/2/2021

#define INFILE "../graph.txt"

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Graph.h"

int main() {
    Graph testGraph;
    // Creating the nodes
    std::cout << "Testing addNode()" << std::endl;
    testGraph.addNode(new Vertex("a"));
    testGraph.addNode(new Vertex("b"));
    testGraph.addNode(new Vertex("c"));
    testGraph.addNode(new Vertex("d"));
    testGraph.addNode(new Vertex("e"));
    // Creating the edges
    std::cout << "Testing addEdge()" << std::endl;
    testGraph.addEdge("a", "e", 9);
    testGraph.addEdge("a", "c", 7);
    testGraph.addEdge("b", "a", 3);
    testGraph.addEdge("b", "d", 2);
    testGraph.addEdge("c", "d", 1);
    testGraph.addEdge("d", "e", 6);

    // Testing printNodes()
    std::cout << "Testing printNodes()" << std::endl;
    testGraph.printNodes();

    // Testing printAdjacencyMatrix()
    std::cout << "Testing printAdjacencyMatrix():" << std::endl;
    testGraph.printAdjacencyMatrix();

    // Testing printAdjacencyList()
    std::cout << "Testing printAdjacencyList():" << std::endl;
    testGraph.printAdjacencyList();

    // Searching for node e
    std::string search = "e";

    std::cout << "Testing shortest path from b to e and getNode()" << std::endl;
    for (Vertex *node : testGraph.shortestPath(testGraph.getNode("b"), testGraph.getNode("e"))) {
        std::cout << node->getName() << ", ";
    }
    // Deletes the comma at the end
    std::cout << "\b\b " << std::endl;

    // Searches
    std::cout << std::endl << "Searches:" << std::endl << std::endl;
    std::cout << "Breadth first search for e from b: " << std::endl;
    std::cout << "Search result: " << Graph::breadthFirstSearch(search, testGraph.getNode("b"))->getName() << std::endl << std::endl;
    std::cout << "Depth first search for e from b: " << std::endl;
    std::cout << "Search result: " << Graph::depthFirstSearch(search, testGraph.getNode("b"))->getName() << std::endl << std::endl;
    std::cout << "Ordered Depth first search for e from b: " << std::endl;
    std::cout << "Search result: " << Graph::orderedDepthFirstSearch(search, testGraph.getNode("b"))->getName() << std::endl << std::endl;

    return 0;
}