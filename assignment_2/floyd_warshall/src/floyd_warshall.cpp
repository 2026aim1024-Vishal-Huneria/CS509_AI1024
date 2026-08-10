#include "floyd_warshall.h"

using namespace std;

const long long INF = 4000000000000000LL;

FloydWarshallResult floydWarshall(
    int vertices,
    const vector<vector<long long>>& matrix
)
{
    FloydWarshallResult result;

    result.distance = matrix;
    result.negativeCycle = false;

    // Floyd-Warshall algorithm
    for(int k = 0; k < vertices; k++)
    {
        for(int i = 0; i < vertices; i++)
        {
            if(result.distance[i][k] == INF)
                continue;

            for(int j = 0; j < vertices; j++)
            {
                if(result.distance[k][j] == INF)
                    continue;

                long long newDistance =
                    result.distance[i][k] +
                    result.distance[k][j];

                if(newDistance < result.distance[i][j])
                {
                    result.distance[i][j] = newDistance;
                }
            }
        }
    }

    // Negative cycle detection
    for(int i = 0; i < vertices; i++)
    {
        if(result.distance[i][i] < 0)
        {
            result.negativeCycle = true;
            break;
        }
    }

    return result;
}