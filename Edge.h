// Edge.h
// Joshua Steege
// Section 2
// Last modified: 11/22/2021

#ifndef PROJECT_3_GRAPH_MAN_EDGE_H
#define PROJECT_3_GRAPH_MAN_EDGE_H

#include <string>
#include "Vertex.h"

class Vertex; // Forward Declaration

class Edge {
private:
    std::string name;
    Vertex *source;
    Vertex *destination;
    int weight;
public:
    Edge(std::string Name, Vertex* Source = nullptr, Vertex* Destination = nullptr, int Weight = 1);
    const std::string &getName() const;
    void setName(const std::string &name);
    Vertex *getSource() const;
    void setSource(Vertex *source);
    Vertex *getDestination() const;
    void setDestination(Vertex *destination);
    int getWeight() const;
    void setWeight(int weight);
};


#endif //PROJECT_3_GRAPH_MAN_EDGE_H
