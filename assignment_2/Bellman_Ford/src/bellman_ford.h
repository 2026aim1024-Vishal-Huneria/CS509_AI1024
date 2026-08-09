#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "csr.h"
#include <vector>

using namespace std;

struct BellmanFordResult
{
    vector<int> distance;
    bool negativeCycle;
};

BellmanFordResult bellmanFord(
    int vertices,
    const CSR& csr,
    int source
);

#endif