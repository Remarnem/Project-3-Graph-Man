// edgeTest.cpp
// Joshua Steege
// Section 2
// Last modified: 11/27/2021

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Edge.h"
#include "../Vertex.h"

int main() {
    // Creating the edge
    std::cout << "Creating an edge" << std::endl;
    Edge testEdge("A Test Edge");
    // Testing getName
    std::cout << "Testing getName()" << std::endl;
    std::cout << "The edge's name is: \"" << testEdge.getName() << "\"" << std::endl;
    // Testing setName
    std::cout << "Testing setName()" << std::endl;
    testEdge.setName("New Name");
    std::cout << "After setName: \"" << testEdge.getName() << "\"" << std::endl;
    // Testing setSource
    std::cout << "Testing setSource()" << std::endl;
    Vertex a;
    testEdge.setSource(&a);
    // Testing getSource
    std::cout << "Testing getSource()" << std::endl;
    std::cout << "Source node's name: " << testEdge.getSource()->getName() << std::endl;
    // Testing setDestination
    std::cout << "Testing setDestination()" << std::endl;
    Vertex b("Node b");
    testEdge.setDestination(&b);
    // Testing getDestination
    std::cout << "Testing getDestination()" << std::endl;
    std::cout << "Destination node's name: " << testEdge.getDestination()->getName() << std::endl;
    // Testing setWeight
    std::cout << "Testing setWeight()" << std::endl;
    testEdge.setWeight(15);
    // Testing getWeight
    std::cout << "Testing getWeight()" << std::endl;
    std::cout << "Edge weight: " << testEdge.getWeight() << std::endl;

    return 0;
}