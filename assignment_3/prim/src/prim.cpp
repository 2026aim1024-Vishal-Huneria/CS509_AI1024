#include "prim.h"

#include <queue>
#include <limits>

using namespace std;


PrimResult prim(
    int vertices,
    const CSR& csr
)
{
    PrimResult result;

    result.totalWeight = 0;


    if(vertices == 0)
    {
        return result;
    }


    /*
        Min heap:

        weight, vertex, parent
    */

    using Node =
        tuple<int, int, int>;

    priority_queue<
        Node,
        vector<Node>,
        greater<Node>
    > pq;


    vector<bool> visited(vertices, false);


    /*
        Start Prim from vertex 0.
    */

    pq.push({
        0,
        0,
        -1
    });


    while(!pq.empty())
    {
        auto [weight, u, parent] =
            pq.top();

        pq.pop();


        if(visited[u])
        {
            continue;
        }


        visited[u] = true;


        /*
            The starting vertex has no parent,
            so it is not an MST edge.
        */

        if(parent != -1)
        {
            result.edges.push_back({
                parent,
                u,
                weight
            });

            result.totalWeight += weight;
        }


        /*
            Examine all neighbours of u.
        */

        for(int pos = csr.offset[u];
            pos < csr.offset[u + 1];
            pos++)
        {
            int v =
                csr.intermediate[pos];

            int edgeWeight =
                csr.property[pos];


            if(!visited[v])
            {
                pq.push({
                    edgeWeight,
                    v,
                    u
                });
            }
        }
    }


    return result;
}