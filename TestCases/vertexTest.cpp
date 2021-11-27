// vertexTest.cpp
// Joshua Steege
// Section 2
// Last modified: 11/27/2021

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Vertex.h"

int main() {
    // Creating the node
    std::cout << "Creating a vertex" << std::endl;
    Vertex node;
    // Testing setName
    std::cout << "Testing setName()" << std::endl;
    node.setName("Test Node");
    // Testing getName
    std::cout << "Testing getName()" << std::endl;
    std::cout << "Node name: " << node.getName() << std::endl;
    // Testing edgeList
    std::cout << "Testing getEdgeList()" << std::endl;
    std::vector<Edge*> *theEdgeList;
    theEdgeList = node.getEdgeList();
    // Testing node manipulation
    std::cout << "Testing edgeList vector" << std::endl;
    std::cout << "Number of edges: " << theEdgeList->size() << std::endl;
    // Testing add edge
    std::cout << "Testing add edge." << std::endl;
    theEdgeList->push_back(new Edge("Edge 1"));
    theEdgeList->push_back(new Edge("Edge 2"));
    // Testing edgeList again
    std::cout << "Testing new edgeList" << std::endl;
    std::cout << "Number of edges: " << theEdgeList->size() << std::endl;
    std::cout << "Vertex's number of edges: " << node.getEdgeList()->size() << std::endl;

    return 0;
}