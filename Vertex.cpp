// Vertex.cpp
// Joshua Steege
// Section 2
// Last modified: 11/22/2021

#include "Vertex.h"

// Default Constructor
Vertex::Vertex() {
    name = "Node";

}
// Constructor with node name
Vertex::Vertex(std::string &Name) {
    name = Name;
}
// Getter for node name
const std::string &Vertex::getName() const {
    return name;
}
// Setter for node name
void Vertex::setName(const std::string &name) {
    this->name = name;
}
// Returns address of vector containing out edges
std::vector<Edge *> *Vertex::getEdgeList() {
    return &outEdges;
}

