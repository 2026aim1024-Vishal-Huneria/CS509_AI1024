#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../../../assignment_1/CSR_Graph/src/csr.h"

#include <vector>

using namespace std;

struct MSTEdge
{
    int u;
    int v;
    int weight;
};

struct KruskalResult
{
    vector<MSTEdge> edges;
    long long totalWeight;
};

KruskalResult kruskal(
    int vertices,
    const CSR& csr
);

#endif