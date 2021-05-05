#include <bits/stdc++.h>
#include "misc.h"

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
using namespace std;
class Graph {

public:
    explicit Graph(int size);
    void addEdge(int a, int b, int cost);
    void buildGraph(list<Edge> & edges);
    // getUniqueEdgeList does the opposite of build Graph
    shared_ptr<list<Edge>> getUniqueEdgeList(); //Get unique edge list to print in a file
    vector<Graph> primAlgorithm();

private:
    int capacity;
    vector<list<Edge>> gr;
};

#endif //UNTITLED_GRAPH_H
