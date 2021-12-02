// Graph.cpp
// Joshua Steege
// Section 2
// Last modified: 12/2/2021

#include <iostream>
#include "Graph.h"
#include <stack>
#include <queue>

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
void Graph::printAdjacencyMatrix() {
    std::cout << "Adjacency matrix:" << std::endl;
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
// Prints adjacency list
void Graph::printAdjacencyList() {
    // Iterating through each node
    for (Vertex *node : nodes) {
        // Printing node name
        std::cout << node->getName();
        // Iterating through all edges a node has
        for (Edge *edge : *node->getEdgeList()) {
            std::cout << " -> " << edge->getDestination()->getName();
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
    std::cout << "\b\b " << std::endl;
}
// Function to get the address of a node from the command line
Vertex *Graph::getNode() {
    // Variables for selecting starting node
    std::string selection;
    // Loops until a valid input is given
    while (true) {
        // Prompts the user to pick a node to start from
        std::cout << "Pick a starting node: ";
        printNodes();
        std::cin >> selection;
        for (Vertex *node : nodes) {
            if (node->getName() == selection) {
                return node;
            }
        }
    }
}
// Function that converts a node name to it's address
Vertex *Graph::getNode(const std::string& nodeName) {
    for (Vertex *node : nodes) {
        if (node->getName() == nodeName) {
            return node;
        }
    }
    return nullptr;
}
// Prompts user for input if no starting node is given for breadth first search
Vertex *Graph::breadthFirstSearch(std::string &NodeName) {
    return breadthFirstSearch(NodeName, getNode());
}
// Performs a breadth first search for a node with the NodeName starting from StartNode
Vertex *Graph::breadthFirstSearch(std::string &NodeName, Vertex *StartNode) {
    // Checking if StartNode is nullptr
    if (StartNode == nullptr) {
        std::cout << "StartNode cannot be null." << std::endl;
        return nullptr;
    }
    std::queue<Vertex*> queue;
    queue.emplace(StartNode);
    std::vector<Vertex*> visited;
    // Loop until value found
    while (true) {
        // Check if queue is empty
        if (queue.empty()) {
            // Target node couldn't be found.
            std::cout << "Couldn't find " << NodeName << " starting from" << StartNode->getName() << std::endl;
            return nullptr;
        }
        // Get next node to process
        Vertex *node = queue.front();
        queue.pop();
        std::cout << "Visiting: " << node->getName() << std::endl;
        // Check if this is node we're searching for
        if (node->getName() == NodeName) {
            return node;
        }
        // Check if node has been visited before
        for (Vertex *visitedNode : visited) {
            // Skips to the next loop iteration if node has been visited before
            if (node == visitedNode) continue;
        }
        // Count node as visited
        visited.push_back(node);
        // Add all subsequent nodes to queue
        for (Edge *edge : *node->getEdgeList()) {
            // Checks if destination has been visited
            for (Vertex *visitedNode : visited) {
                // Adds destination node if it hasn't been visited yet
                if (edge->getDestination() != visitedNode) {
                    queue.emplace(edge->getDestination());
                }
            }
        }
    }
}
// Prompts user for input if no starting node is given for depth first search
Vertex *Graph::depthFirstSearch(std::string &NodeName) {
    return depthFirstSearch(NodeName, getNode());
}
// Performs a depth first search for a node with the NodeName starting from StartNode
Vertex *Graph::depthFirstSearch(std::string &NodeName, Vertex *StartNode) {
    // Checking if StartNode is nullptr
    if (StartNode == nullptr) {
        std::cout << "StartNode cannot be null." << std::endl;
        return nullptr;
    }
    std::stack<Vertex*> stack;
    stack.push(StartNode);
    std::vector<Vertex*> visited;
    // Loop until value found
    while (true) {
        // Check if stack is empty
        if (stack.empty()) {
            // Target node couldn't be found.
            std::cout << "Couldn't find " << NodeName << " starting from" << StartNode->getName() << std::endl;
            return nullptr;
        }
        // Get next node to process
        Vertex *node = stack.top();
        stack.pop();
        std::cout << "Visiting: " << node->getName() << std::endl;
        // Check if this is node we're searching for
        if (node->getName() == NodeName) {
            return node;
        }
        // Check if node has been visited before
        for (Vertex *visitedNode : visited) {
            // Skips to the next loop iteration if node has been visited before
            if (node == visitedNode) continue;
        }
        // Count node as visited
        visited.push_back(node);
        // Add nodes to stack
        for (Edge *edge : *node->getEdgeList()) {
            // Checks if destination has been visited
            for (Vertex *visitedNode : visited) {
                // Adds destination node if it hasn't been visited yet
                if (edge->getDestination() != visitedNode) {
                    stack.push(edge->getDestination());
                }
            }
        }
    }
}
// Prompts user for input if no starting node is given for ordered depth first search
Vertex *Graph::orderedDepthFirstSearch(std::string &NodeName) {
    return orderedDepthFirstSearch(NodeName, getNode());
}
// Performs a depth first search for a node with the NodeName starting from StartNode
// And prioritizing nodes with a smaller degree first
Vertex *Graph::orderedDepthFirstSearch(std::string &NodeName, Vertex *StartNode) {
    // Checking if StartNode is nullptr
    if (StartNode == nullptr) {
        std::cout << "StartNode cannot be null." << std::endl;
        return nullptr;
    }
    std::stack<Vertex*> stack;
    stack.push(StartNode);
    std::vector<Vertex*> visited;
    // Loop until value found
    while (true) {
        // Check if stack is empty
        if (stack.empty()) {
            // Target node couldn't be found.
            std::cout << "Couldn't find " << NodeName << " starting from" << StartNode->getName() << std::endl;
            return nullptr;
        }
        // Get next node to process
        Vertex *node = stack.top();
        stack.pop();
        std::cout << "Visiting: " << node->getName() << std::endl;
        // Check if this is node we're searching for
        if (node->getName() == NodeName) {
            return node;
        }
        // Check if node has been visited before
        for (Vertex *visitedNode : visited) {
            // Skips to the next loop iteration if node has been visited before
            if (node == visitedNode) continue;
        }
        // Count node as visited
        visited.push_back(node);
        // Add nodes to stack
        std::vector<Vertex*> childNodes;
        // Adding the destinations you can reach from node to the childNodes vector
        for (Edge *edge : *node->getEdgeList()) {
            childNodes.push_back(edge->getDestination());
        }
        // Control variable for while loop
        int largest[2]; // first value is largest degree, 2nd value is index
        while (!childNodes.empty()) {
            // Initializing
            largest[0] = 0;
            largest[1] = 0;
            // Get index of node w/ highest degree
            for (int i = 0; i < childNodes.size(); ++i) {
                // See if node has new highest degree
                if (childNodes[i]->getEdgeList()->size() >= largest[0]) {
                    largest[0] = childNodes[i]->getEdgeList()->size();
                    largest[1] = i;
                }
            }
            // Adds the node with the largest degree to the stack
            stack.push(childNodes[largest[1]]);
            // Removes the node that was just added to the stack from the childNodes vector
            childNodes.erase(childNodes.begin() + largest[1]);
        } // All child nodes have been added to the stack with the smallest degree on top
    }
}
// Finds the shortest path between two nodes
std::vector<Vertex *> Graph::shortestPath(Vertex *source, Vertex *destination) {
    // Checking nodes aren't null
    if (source == nullptr || destination == nullptr) {
        std::cout << "Invalid source or destination nodes." << std::endl;
        return *(new std::vector<Vertex *>);
    }
    // Vector to store visited nodes
    std::vector<Vertex*> visited;
    // Array of vectors to store the paths to each node
    auto *paths = new std::vector<Vertex*>[nodes.size()];
    // Array to store cost of path to a node
    auto *pathWeights = new uint32_t[nodes.size()];
    // Initializing path weights to 'infinity'
    for (auto i = 0; i < nodes.size(); i++) {
        pathWeights[i] = UINT32_MAX;
    }
    // Calculating shortest path
    // Variable to store the node we're currently searching from
    Vertex *currentNode = source;
    // Variable to store the index of the node in the paths and pathWeights arrays as well as the nodes vector
    int pathIndex;
    // Getting the index of the source node
    for (auto i = 0; i < nodes.size(); i++) {
        if (nodes[i] == source) {
            pathIndex = i;
            break;
        }
    }
    uint32_t currentWeight = 0;
    while (true) {
        // Iterate through all nodes in the graph
        for (auto i = 0; i < nodes.size(); i++) {
            // Iterate through all out edges for the current node
            for (Edge *edge: *currentNode->getEdgeList()) {
                // Checking if the current edge leads to a given node
                if (edge->getDestination() == nodes[i]) {
                    // Checking if the new weight would be less than the old one
                    if ( currentWeight + edge->getWeight() < pathWeights[i]) {
                        // Clearing old path to node
                        paths[i].clear();
                        // Updating the path weight
                        pathWeights[i] = edge->getWeight() + currentWeight;
                        // Copying the path to this node
                        paths[i] = paths[pathIndex];
                        // Adding the node itself to the end of its path
                        paths[i].push_back(currentNode);
                    }
                }
            }
        }
        // Adding the current node to the visited list
        visited.push_back(currentNode);
        // Checking if all nodes have been visited
        if (visited.size() == nodes.size()) {
            break;
        }
        // Reusing currentWeight to find the node with the next lowest cost
        currentWeight = UINT32_MAX;
        // Setting currentNode to the unvisited node with the lowest cost
        for (auto i = 0; i < nodes.size(); i++) {
            bool beenVisited = false;
            // Checking if node has been visited already
            for (Vertex *node : visited) {
                if (nodes[i] == node) {
                    // Node has been visited, reusing bool and breaking loop
                    beenVisited = true;
                    break;
                }
            }
            // If node has been visited skips to the next loop iteration
            if (beenVisited) {
                continue;
            }
            // Checking if the node has the lowest remaining cost to reach
            if (pathWeights[i] <= currentWeight) {
                // Updating currentWeight with the lowest cost
                currentWeight = pathWeights[i];
                // Saving the node's index
                pathIndex = i;
            }
        }
        // The index for the node with the next lowest cost is stored in pathIndex
        // Getting address for the new current node
        currentNode = nodes[pathIndex];
        // If the next node to process paths from is the destination, return path;
        if (currentNode == destination) {
            // Adding destination to the end of the path
            paths[pathIndex].push_back(destination);
            std::cout << "Cost: " << currentWeight << std::endl;
            return paths[pathIndex];
        }
    }


}


