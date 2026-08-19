#include <bits/stdc++.h>

#include "../../../assignment_1/CSR_Graph/src/csr.h"
#include "../src/kruskal.h"

using namespace std;


int main()
{
    int choice;

    cout << "\n";
    cout << "====================================\n";
    cout << "       KRUSKAL'S MST\n";
    cout << "====================================\n";

    cout << "1. Run mst_10.txt\n";
    cout << "2. Run mst_100.txt\n";
    cout << "3. Run mst_10000.txt\n";
    cout << "4. Run mst_50000.txt\n";
    cout << "5. Run mst_100000.txt\n";
    cout << "6. Exit\n";

    cout << "\nEnter choice: ";
    cin >> choice;


    string fileName;


    switch(choice)
    {
        case 1:
            fileName = "tests/mst_10.txt";
            break;

        case 2:
            fileName = "tests/mst_100.txt";
            break;

        case 3:
            fileName = "tests/mst_10000.txt";
            break;

        case 4:
            fileName = "tests/mst_50000.txt";
            break;

        case 5:
            fileName = "tests/mst_100000.txt";
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice\n";
            return 0;
    }


    ifstream fin(fileName);

    if(!fin)
    {
        cout << "Cannot open file: "
             << fileName
             << "\n";

        return 1;
    }


    int vertices;
    int edges;

    fin >> vertices >> edges;


    /*
        Read adjacency list.
    */

    map<int, vector<pair<int, int>>> graph;


    for(int i = 0; i < vertices; i++)
    {
        int vertex;
        int degree;

        fin >> vertex >> degree;


        for(int j = 0; j < degree; j++)
        {
            int neighbor;
            int weight;

            fin >> neighbor >> weight;

            graph[vertex].push_back({
                neighbor,
                weight
            });
        }
    }


    fin.close();


    /*
        CSR conversion is preprocessing.

        It must NOT be included in algorithm timing.
    */

    CSR csr = calculateCSR(
        vertices,
        graph
    );


    /*
        ------------------------------------------
        START ALGORITHM TIMER
        ------------------------------------------
    */

    auto start =
        chrono::high_resolution_clock::now();


    KruskalResult result =
        kruskal(
            vertices,
            csr
        );


    /*
        ------------------------------------------
        STOP ALGORITHM TIMER
        ------------------------------------------
    */

    auto end =
        chrono::high_resolution_clock::now();


    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();


    /*
        Output
    */

    cout << "\nAlgorithm: Kruskal's MST\n";

    cout << "\nMST edges:\n";

    for(const MSTEdge& edge : result.edges)
    {
        cout << edge.u << " "
             << edge.v << " "
             << edge.weight
             << "\n";
    }


    cout << "\nTotal MST weight: "
         << result.totalWeight
         << "\n";


    cout << "Execution time: "
         << fixed
         << setprecision(3)
         << executionTime
         << " ms\n";


    /*
        A connected graph with V vertices must
        have V-1 MST edges.
    */

    if((int)result.edges.size() != vertices - 1)
    {
        cout << "\nError: Graph is not connected.\n";
    }

    return 0;
}