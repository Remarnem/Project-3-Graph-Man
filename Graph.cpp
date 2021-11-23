// Graph.cpp
// Joshua Steege
// Section 2
// Last modified: 11/23/2021

#include <iostream>
#include "Graph.h"

// Adds a node to the graph if it doesn't already exist
void Graph::addNode(Vertex *newNode) {
    // Checking if node already exists in graph
    for (Vertex *node : nodes) {
        if (node->getName() == newNode->getName()) {
            std::cout << "Node shares name with existing node!" << std::endl;
            return;
        }
    }
    // Node doesn't already exist in graph
    nodes.push_back(newNode);
}

// Adds an edge if it doesn't already exist
void Graph::addEdge(Edge *newEdge) {
    // Checking if edge already exists
    for (Edge *edge : edges) {
        if (edge == newEdge) {
            std::cout << "You already added this edge to the graph!" << std::endl;
            return;
        }
    }
    // Edge doesn't already exist
    edges.push_back(newEdge);
}
