#include "kruskal.h"

#include <algorithm>

using namespace std;


// --------------------------------------------------
// Disjoint Set Union
// --------------------------------------------------

class DSU
{
private:

    vector<int> parent;
    vector<int> rankValue;

public:

    DSU(int n)
    {
        parent.resize(n);
        rankValue.resize(n, 0);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }


    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }


    bool unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB)
        {
            return false;
        }

        if(rankValue[rootA] < rankValue[rootB])
        {
            parent[rootA] = rootB;
        }
        else if(rankValue[rootA] > rankValue[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }

        return true;
    }
};


// --------------------------------------------------
// Kruskal's Algorithm
// --------------------------------------------------

KruskalResult kruskal(
    int vertices,
    const CSR& csr
)
{
    KruskalResult result;

    result.totalWeight = 0;

    vector<MSTEdge> edges;

    /*
        CSR contains both directions because the graph
        is undirected.

        Therefore:

            u -> v
            v -> u

        represent the same undirected edge.

        Only keep u < v so that every edge is included
        exactly once.
    */

    for(int u = 0; u < vertices; u++)
    {
        for(int pos = csr.offset[u];
            pos < csr.offset[u + 1];
            pos++)
        {
            int v = csr.intermediate[pos];

            int weight = csr.property[pos];

            if(u < v)
            {
                edges.push_back({
                    u,
                    v,
                    weight
                });
            }
        }
    }


    // Sort edges according to weight

    sort(
        edges.begin(),
        edges.end(),
        [](const MSTEdge& a, const MSTEdge& b)
        {
            if(a.weight != b.weight)
                return a.weight < b.weight;

            if(a.u != b.u)
                return a.u < b.u;

            return a.v < b.v;
        }
    );


    DSU dsu(vertices);


    /*
        Select edges that do not create a cycle.
    */

    for(const MSTEdge& edge : edges)
    {
        if(dsu.unite(edge.u, edge.v))
        {
            result.edges.push_back(edge);

            result.totalWeight += edge.weight;

            if((int)result.edges.size() == vertices - 1)
            {
                break;
            }
        }
    }


    return result;
}