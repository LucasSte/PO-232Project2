#include "misc.h"

bool operator==(Edge it, Edge that) {
    return (it.from == that.from) && (it.to == that.to) && (it.cost == that.cost);
}

bool Edge::operator<(const Edge &that) {
    if (this->cost != that.cost) return this->cost < that.cost;
    if (this->to != that.to) return this->to < that.to;
    else return this->from < that.from;
}

bool CompareEdge::operator()(Edge const& e1, Edge const& e2) {
    return e1.cost > e2.cost;
}
