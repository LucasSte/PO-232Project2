#include "Parser.h"


void Parser::readEdgesFromFile(int *maxSize, string fileName) {
    *maxSize = 0;
    string line;

    ifstream file;
    file.open(fileName);

    // Read first lines
    getline(file, line);
    getline(file, line);

    // Get
    int from = 0, to = 0, cost;
    int status;
    while (getline(file, line)) {
        status = sscanf(line.data(), "%d -> %d [label = \"%d\"]", &from, &to, &cost);
        if(status == 3) {
            edges.emplace_back(Edge{from, to, cost});
            *maxSize = max(*maxSize, max(from+1, to+1));
        }
    }

    file.close();
}

list<Edge> & Parser::getEdges() {
    return edges;
}

void Parser::printGraph(string fileName, shared_ptr<list<Edge>> ptr, string graphName) {
    ofstream file;
    file.open(fileName);

    file << "digraph " << graphName << " {" << endl;
    file << '\t' << "edge[dir=none]" << endl << endl;

    for(Edge & e : *ptr) {
        file << e.from << " -> " << e.to << " [label = \"" << e.cost << "\"]" << endl;
    }

    file << "}\n";

    file.close();
}
