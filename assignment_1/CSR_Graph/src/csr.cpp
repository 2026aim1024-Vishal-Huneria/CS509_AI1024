#include "csr.h"
#include <iostream>

using namespace std;

CSR calculateCSR(
    int vertices,
    const map<int, vector<pair<int, int>>>& graph
)
{
    CSR csr;

    int pos = 0;

    // Offset has vertices + 1 elements
    csr.offset.resize(vertices + 1);

    // Calculate CSR
    for(int i = 0; i < vertices; i++)
    {
        csr.offset[i] = pos;

        auto it = graph.find(i);

        if(it != graph.end())
        {
            for(const auto& edge : it->second)
            {
                csr.intermediate.push_back(edge.first);
                csr.property.push_back(edge.second);

                pos++;
            }
        }
    }

    // Last offset stores total number of edges
    csr.offset[vertices] = pos;

    return csr;
}

void printArray(const vector<int>& arr)
{
    for(int value : arr)
    {
        cout << value << " ";
    }

    cout << endl;
}