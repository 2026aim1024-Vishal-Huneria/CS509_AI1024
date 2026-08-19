#ifndef PRIM_H
#define PRIM_H

#include "../../../assignment_1/CSR_Graph/src/csr.h"

#include <vector>

using namespace std;

struct PrimEdge
{
    int u;
    int v;
    int weight;
};

struct PrimResult
{
    vector<PrimEdge> edges;
    long long totalWeight;
};

PrimResult prim(
    int vertices,
    const CSR& csr
);

#endif