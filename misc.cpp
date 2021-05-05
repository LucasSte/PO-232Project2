#include "misc.h"

bool CompareEdge::operator()(Edge const& e1, Edge const& e2) {
    return e1.cost < e2.cost;
}
