#include <bits/stdc++.h>

#include "../../../assignment_1/CSR_Graph/src/csr.h"
#include "../src/bellman_ford.h"

// assignment_1\CSR_Graph\src\csr.h


using namespace std;

int main()
{
    // string fileName = "tests/bellman_ford_test_2.txt";

    int choice;

cout << "1. Run bf_10.txt\n";
cout << "2. Run bf_100.txt\n";
cout << "3. Run bf_10000.txt\n";
cout << "4. Run bf_50000.txt\n";
cout << "5. Run bf_100000.txt\n";
cout << "6. Run All Tests\n";

cout << "Enter choice: ";
cin >> choice;

string fileName;

switch(choice)
{
    case 1:
        fileName = "tests/bf_10.txt";
        break;

    case 2:
        fileName = "tests/bf_100.txt";
        break;

    case 3:
        fileName = "tests/bf_10000.txt";
        break;

    case 4:
        fileName = "tests/bf_50000.txt";
        break;

    case 5:
        fileName = "tests/bf_100000.txt";
        break;

    case 6:
        // handle all tests separately
        break;

    default:
        cout << "Invalid choice\n";
        return 0;
}

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
}
