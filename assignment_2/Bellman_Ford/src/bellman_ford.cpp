#include "bellman_ford.h"
#include <climits>

using namespace std;

BellmanFordResult bellmanFord(
    int vertices,
    const CSR& csr,
    int source
)
{
    const int INF = INT_MAX;

    BellmanFordResult result;

    result.distance.resize(vertices, INF);
    result.negativeCycle = false;

    result.distance[source] = 0;

    // V - 1 relaxation passes
    for(int iteration = 0; iteration < vertices - 1; iteration++)
    {
        bool changed = false;

        for(int u = 0; u < vertices; u++)
        {
            if(result.distance[u] == INF)
                continue;

            for(int pos = csr.offset[u];
                pos < csr.offset[u + 1];
                pos++)
            {
                int v = csr.intermediate[pos];
                int weight = csr.property[pos];

                if(result.distance[u] + weight < result.distance[v])
                {
                    result.distance[v] =
                        result.distance[u] + weight;

                    changed = true;
                }
            }
        }

        if(!changed)
            break;
    }

    // Negative cycle detection
    for(int u = 0; u < vertices; u++)
    {
        if(result.distance[u] == INF)
            continue;

        for(int pos = csr.offset[u];
            pos < csr.offset[u + 1];
            pos++)
        {
            int v = csr.intermediate[pos];
            int weight = csr.property[pos];

            if(result.distance[u] + weight < result.distance[v])
            {
                result.negativeCycle = true;
                return result;
            }
        }
    }

    return result;
}