// Vertex.h
// Joshua Steege
// Section 2
// Last modified: 11/27/2021

#ifndef PROJECT_3_GRAPH_MAN_VERTEX_H
#define PROJECT_3_GRAPH_MAN_VERTEX_H

#include <vector>
#include "Edge.h"

class Edge; // Forward declaration

class Vertex {
private:
    std::string name;
    std::vector<Edge*> outEdges;
public:
    Vertex();
    Vertex(std::string Name);
    const std::string &getName() const;
    void setName(const std::string &name);
    std::vector<Edge*> *getEdgeList();
};


#endif //PROJECT_3_GRAPH_MAN_VERTEX_H
