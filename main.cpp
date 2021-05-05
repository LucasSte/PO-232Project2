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
    int i = 1;
    for(auto & tree : trees) {
        p.printGraph("../tree" + to_string(i) + ".dat", tree.getUniqueEdgeList(), "Tree" + to_string(i));
        i++;
    }

    return 0;
}
