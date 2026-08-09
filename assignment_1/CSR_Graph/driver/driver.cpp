#include <bits/stdc++.h>
#include "../src/csr.h"

using namespace std;

int main()
{
    int choice;
    string fileName;

    cout << "1. Run Test 01\n";
    cout << "2. Run Test 02\n";
    cout << "3. Run Test 03\n";
    cout << "4. Run Test 04\n\n";

    cout << "Enter Choice : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            fileName = "tests/graph_test_01.txt";
            break;

        case 2:
            fileName = "../tests/graph_test_02.txt";
            break;

        case 3:
            fileName = "../tests/graph_test_03.txt";
            break;

        case 4:
            fileName = "../tests/graph_test_04.txt";
            break;

        default:
            cout << "Invalid Choice\n";
            return 0;
    }

    ifstream fin(fileName);

    if(!fin)
    {
        cout << "Cannot open file: " << fileName << endl;
        return 0;
    }

    int vertices, edges;

    fin >> vertices >> edges;

    // Adjacency list
    map<int, vector<pair<int, int>>> graph;

    for(int i = 0; i < vertices; i++)
    {
        int vertex, outDegree;

        fin >> vertex >> outDegree;

        for(int j = 0; j < outDegree; j++)
        {
            int neighbor, weight;

            fin >> neighbor >> weight;

            graph[vertex].push_back({neighbor, weight});
        }
    }

    fin.close();

    // Calculate CSR
    CSR csr = calculateCSR(vertices, graph);

    // Print CSR
    cout << "\nCSR Representation\n\n";

    cout << "Offset : ";
    printArray(csr.offset);

    cout << "Intermediate : ";
    printArray(csr.intermediate);

    cout << "Property : ";
    printArray(csr.property);

    return 0;
}