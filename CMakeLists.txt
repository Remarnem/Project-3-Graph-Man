cmake_minimum_required(VERSION 3.20)
project(Project_3_Graph_Man)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_3_Graph_Man main.cpp Graph.h Graph.cpp Vertex.h Vertex.cpp Edge.h Edge.cpp)
add_executable(Edge_Test_Case TestCases/edgeTest.cpp Vertex.h Vertex.cpp Edge.h Edge.cpp)
add_executable(Vertex_Test_Case TestCases/vertexTest.cpp Vertex.h Vertex.cpp Edge.h Edge.cpp)
add_executable(Graph_Test_Case TestCases/graphTest.cpp Graph.h Graph.cpp Vertex.h Vertex.cpp Edge.h Edge.cpp)