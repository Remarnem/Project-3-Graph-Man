// Edge.cpp
// Joshua Steege
// Section 2
// Last modified: 11/22/2021

#include "Edge.h"

// Constructor with default parameters
Edge::Edge(std::string &Name, Vertex *Source, Vertex *Destination, int Weight) : name(Name), weight(Weight) {
    source = Source;
    destination = Destination;
}
// Getter for edge name
const std::string &Edge::getName() const {
    return name;
}
// Setter for edge name
void Edge::setName(const std::string &name) {
    this->name = name;
}
// Getter for source node
Vertex *Edge::getSource() const {
    return source;
}
// Setter for source node
void Edge::setSource(Vertex *source) {
    this->source = source;
}
// Getter for destination node
Vertex *Edge::getDestination() const {
    return destination;
}
// Setter for destination
void Edge::setDestination(Vertex *destination) {
    this->destination = destination;
}
// Getter for edge weight
int Edge::getWeight() const {
    return weight;
}
// Setter for edge weight
void Edge::setWeight(int weight) {
    this->weight = weight;
}

