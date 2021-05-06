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

    vector<Graph> trees = g.primAlgorithm();

    for(int i=0; i<trees.size(); i++) {
        p.printGraph("../tree" + to_string(i) + ".dat", trees[i].getUniqueEdgeList(), "Tree" + to_string(i));
    }

    return 0;
}
