#include "Parser.h"
#include "Graph.h"


int main() {
    Parser p;
    int maxSize = 0;
    p.readEdgesFromFile(&maxSize, "../g1.dat");
    auto ret = p.getEdges();

    Graph g(maxSize);
    g.buildGraph(ret);
    auto ret2 = g.getUniqueEdgeList();
    p.printGraph("../out1.dat", ret2, "GL");

    return 0;
}
