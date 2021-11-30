// Graph.cpp
// Joshua Steege
// Section 2
// Last modified: 11/30/2021

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
    // Add edge to graph edge list
    edges.push_back(newEdge);
    // Add edge to source node
    newEdge->getSource()->getEdgeList()->push_back(newEdge);
}
// Add edge function for loading from a file
void Graph::addEdge(std::string source, const std::string& destination, int weight) {
    // Variables to store node addresses
    Vertex *sourceNode = nullptr;
    Vertex *destinationNode = nullptr;
    for (Vertex *node : nodes) {
        if (sourceNode != nullptr && destinationNode != nullptr) {
            break;
        } else if (node->getName() == source) {
            sourceNode = node;
        } else if (node->getName() == destination) {
            destinationNode = node;
        }
    }
    // Checking source & destination are actual nodes
    if (sourceNode != nullptr && destinationNode != nullptr) {
        addEdge(new Edge(source.append(destination), sourceNode, destinationNode, weight));
    } else {
        std::cout << "One or more vertices couldn't be found for this edge!" << std::endl;
    }
}
// Prints Adjacency Matrix
void Graph::printAdjacency() {
    std::cout << std::endl << "Adjacency matrix:" << std::endl;
    // Printing first line
    std::cout << "  ";
    for (Vertex *node : nodes) {
        std::cout << node->getName() << " ";
    }
    std::cout << std::endl;
    // Printing node lines
    for (Vertex *node : nodes) {
        std::cout << node->getName() << " ";
        for (Vertex *node2 : nodes) {
            if (node == node2) { // Nodes are the same
                std::cout << "0 ";
            } else if (containsNode(node->getEdgeList(), node2)) {
                // An edge in node leads to an edge in node2
                std::cout << "1 ";
            } else {
                // No edge in node leads to node2
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}
// Checks if a given edge list has any edge that leads to the passed node
bool Graph::containsNode(std::vector<Edge*> *edgeList, Vertex *node) {
    // Check if any edge leads to the given node
    for (Edge *edge : *edgeList) {
        if (edge->getDestination() == node) { // Edge leads to node
            return true;
        }
    }
    // No edge found
    return false;
}
// Prints a list of all the node names
void Graph::printNodes() {
    for (Vertex *node : nodes) {
        std::cout << node->getName() << ", ";
    }
    // Deletes the comma at the end
    std::cout << '\b' << '\b' << " " << std::endl;
}
