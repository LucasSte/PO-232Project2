#include "Graph.h"

Graph::Graph(int size) {
    gr.resize(size);
    capacity = size;
}

void Graph::addEdge(int a, int b, int cost) {
    gr[a].push_back({a, b, cost});
    gr[b].push_back({b, a, cost});
}

void Graph::buildGraph(list<Edge> & edges) {
    for(auto p : edges)
    {
        addEdge(p.to, p.from, p.cost);
    }
}

shared_ptr<list<Edge>> Graph::getUniqueEdgeList() {
    shared_ptr<list<Edge>> ptr = make_shared<list<Edge>>();
    unordered_set<string> st;
    int a, b;
    string key;

    for(int i=0; i<gr.size(); i++) {
        for(Edge & k : gr[i]) {
            a = min(k.from, k.to);
            b = max(k.to, k.from);
            key = to_string(a) + '|' + to_string(b) + '|' + to_string(k.cost);
            if(st.count(key) == 0) {
                ptr->push_back({a, b, k.cost});
                st.insert(key);
            }
        }
    }

    return ptr;
}