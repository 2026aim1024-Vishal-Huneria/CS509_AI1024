#include <bits/stdc++.h>

#include "../../../assignment_1/CSR_Graph/src/csr.h"
#include "../src/bellman_ford.h"

// assignment_1\CSR_Graph\src\csr.h


using namespace std;

int main()
{
    string fileName = "tests/bellman_test_01.txt";

    ifstream fin(fileName);

    if(!fin)
    {
        cout << "Cannot open file\n";
        return 0;
    }

    int vertices, edges;

    fin >> vertices >> edges;

    // Adjacency list
    map<int, vector<pair<int, int>>> graph;

    for(int i = 0; i < vertices; i++)
    {
        int vertex;
        int outDegree;

        fin >> vertex >> outDegree;

        for(int j = 0; j < outDegree; j++)
        {
            int neighbor;
            int weight;

            fin >> neighbor >> weight;

            graph[vertex].push_back({neighbor, weight});
        }
    }

    // Read SOURCE
    string sourceWord;
    int source;

    fin >> sourceWord >> source;

    fin.close();

    // -----------------------------------------
    // Calculate CSR using previous assignment
    // -----------------------------------------

    CSR csr = calculateCSR(vertices, graph);

    // -----------------------------------------
    // Run Bellman-Ford
    // -----------------------------------------

    auto start = chrono::high_resolution_clock::now();

    BellmanFordResult result =
        bellmanFord(vertices, csr, source);

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(end - start).count();

    // -----------------------------------------
    // Output
    // -----------------------------------------

    cout << "Algorithm: Bellman-Ford\n";
    cout << "Source: " << source << "\n";

    // Negative cycle
    if(result.negativeCycle)
    {
        cout << "Negative cycle: true\n";
    }
    else
    {
        cout << "Vertex Distance\n";

        for(int i = 0; i < vertices; i++)
        {
            cout << i << " ";

            if(result.distance[i] == INT_MAX)
                cout << "INF";
            else
                cout << result.distance[i];

            cout << "\n";
        }

        cout << "Negative cycle: none\n";
    }

    cout << "Execution time: "
         << fixed << setprecision(3)
         << executionTime
         << " ms\n";

    return 0;
// }
// #include <iostream>
// #include <fstream>

// using namespace std;

// int main()
// {
//     cerr << "PROGRAM STARTED\n";

//     const char* fileName = "tests\\bellman_test_01.txt";

//     cerr << "Before open\n";
//     cerr << "File: " << fileName << "\n";

//     ifstream fin;

//     cerr << "ifstream created\n";

//     fin.open(fileName, ios::in);

//     cerr << "After open\n";

//     if(fin.is_open())
//     {
//         cerr << "FILE OPENED SUCCESSFULLY\n";

//         int vertices, edges;

//         fin >> vertices >> edges;

//         cerr << "vertices = " << vertices << "\n";
//         cerr << "edges = " << edges << "\n";

//         fin.close();
//     }
//     else
//     {
//         cerr << "FILE OPEN FAILED\n";
//     }

//     cerr << "PROGRAM END\n";

//     return 0;
// }