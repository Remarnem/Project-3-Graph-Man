// Graph.h
// Joshua Steege
// Section 2
// Last modified: 11/30/2021

#ifndef PROJECT_3_GRAPH_MAN_GRAPH_H
#define PROJECT_3_GRAPH_MAN_GRAPH_H

#include <vector>
#include "Vertex.h"
#include "Edge.h"

class Graph {
private:
    std::vector<Vertex*> nodes;
    std::vector<Edge*> edges;
    static bool containsNode(std::vector<Edge*> *edgeList, Vertex *node);
public:
    void addNode(Vertex *newNode);
    void addEdge(Edge *newEdge);
    void addEdge(std::string source, const std::string& destination, int weight);
    void printNodes();
    void printAdjacency();
    Vertex* breadthFirstSearch(std::string &NodeName);
    Vertex* depthFirstSearch(std::string &NodeName);
};


#endif //PROJECT_3_GRAPH_MAN_GRAPH_H
