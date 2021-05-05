
#ifndef UNTITLED_MISC_H
#define UNTITLED_MISC_H

struct Edge {
    int from;
    int to;
    int cost;
};

struct CompareEdge {
    bool operator()(Edge const& e1, Edge const& e2);
};
#endif //UNTITLED_MISC_H
