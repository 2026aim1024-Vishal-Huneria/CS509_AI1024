#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <set>

using namespace std;

const long long INF = 4000000000000000LL;

// --------------------------------------------------
// Function 1: Generate graph WITHOUT negative cycle
// --------------------------------------------------

void generateWithoutNegativeCycle(int V, int E, string filename)
{
    int maxEdges = V * (V - 1) / 2;

    if(E > maxEdges)
    {
        cout << "Too many edges for a DAG.\n";
        cout << "Maximum edges = " << maxEdges << "\n";
        return;
    }

    vector<vector<long long>> matrix(
        V,
        vector<long long>(V, INF)
    );

    // Distance from vertex to itself = 0
    for(int i = 0; i < V; i++)
    {
        matrix[i][i] = 0;
    }

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> weightDist(-10, 10);

    set<pair<int,int>> usedEdges;

    int edgesCreated = 0;

    /*
        Create a DAG.

        Only create:

            u -> v

        where:

            u < v

        Therefore cycles are impossible.

        Negative edges are allowed, but because
        there is no cycle, a negative cycle cannot exist.
    */

    while(edgesCreated < E)
    {
        int u = gen() % (V - 1);

        int v = u + 1 + (gen() % (V - u - 1));

        if(usedEdges.count({u, v}))
            continue;

        usedEdges.insert({u, v});

        int weight = weightDist(gen);

        matrix[u][v] = weight;

        edgesCreated++;
    }

    ofstream fout(filename);

    if(!fout)
    {
        cout << "Cannot create file.\n";
        return;
    }

    // First line = number of vertices
    fout << V << "\n";

    // Matrix
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(matrix[i][j] == INF)
                fout << "INF";
            else
                fout << matrix[i][j];

            if(j < V - 1)
                fout << " ";
        }

        fout << "\n";
    }

    fout.close();

    cout << "\n----------------------------------\n";
    cout << "NO NEGATIVE CYCLE TEST CREATED\n";
    cout << "----------------------------------\n";
    cout << "File     : " << filename << "\n";
    cout << "Vertices : " << V << "\n";
    cout << "Edges    : " << E << "\n";
    cout << "Negative edges : allowed\n";
    cout << "Negative cycle : impossible\n";
}


// --------------------------------------------------
// Function 2: Generate graph WITH negative cycle
// --------------------------------------------------

void generateWithNegativeCycle(int V, int E, string filename)
{
    if(V < 3)
    {
        cout << "At least 3 vertices are required.\n";
        return;
    }

    if(E < 3)
    {
        cout << "At least 3 edges are required.\n";
        return;
    }

    int maxEdges = V * (V - 1);

    if(E > maxEdges)
    {
        cout << "Too many edges.\n";
        return;
    }

    vector<vector<long long>> matrix(
        V,
        vector<long long>(V, INF)
    );

    for(int i = 0; i < V; i++)
    {
        matrix[i][i] = 0;
    }

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> weightDist(-10, 10);

    set<pair<int,int>> usedEdges;

    /*
        ------------------------------------------
        STEP 1
        Create a guaranteed negative cycle
        ------------------------------------------

        0 -> 1
        1 -> 2
        2 -> 0

        weights:

        0 -> 1 = 1
        1 -> 2 = -5
        2 -> 0 = -5

        Total:

        1 + (-5) + (-5) = -9

        Therefore this is definitely
        a negative cycle.
    */

    matrix[0][1] = 1;
    matrix[1][2] = -5;
    matrix[2][0] = -5;

    usedEdges.insert({0,1});
    usedEdges.insert({1,2});
    usedEdges.insert({2,0});

    int edgesCreated = 3;

    /*
        ------------------------------------------
        STEP 2
        Add remaining random edges
        ------------------------------------------
    */

    while(edgesCreated < E)
    {
        int u = gen() % V;
        int v = gen() % V;

        // No self-loop
        if(u == v)
            continue;

        // No duplicate edge
        if(usedEdges.count({u,v}))
            continue;

        usedEdges.insert({u,v});

        int weight = weightDist(gen);

        matrix[u][v] = weight;

        edgesCreated++;
    }

    ofstream fout(filename);

    if(!fout)
    {
        cout << "Cannot create file.\n";
        return;
    }

    // Number of vertices
    fout << V << "\n";

    // Matrix
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(matrix[i][j] == INF)
                fout << "INF";
            else
                fout << matrix[i][j];

            if(j < V - 1)
                fout << " ";
        }

        fout << "\n";
    }

    fout.close();

    cout << "\n----------------------------------\n";
    cout << "NEGATIVE CYCLE TEST CREATED\n";
    cout << "----------------------------------\n";
    cout << "File     : " << filename << "\n";
    cout << "Vertices : " << V << "\n";
    cout << "Edges    : " << E << "\n";
    cout << "Negative cycle : guaranteed\n";
    cout << "Cycle : 0 -> 1 -> 2 -> 0\n";
    cout << "Cycle weight : 1 + (-5) + (-5) = -9\n";
}


// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main()
{
    int choice;
    int V;
    int E;

    cout << "====================================\n";
    cout << " Floyd-Warshall Test Case Generator\n";
    cout << "====================================\n\n";

    cout << "1. Generate WITHOUT negative cycle\n";
    cout << "2. Generate WITH negative cycle\n\n";

    cout << "Enter choice: ";
    cin >> choice;

    cout << "\nEnter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    if(V <= 0 || E < 0)
    {
        cout << "Invalid input.\n";
        return 1;
    }

    if(choice == 1)
    {
        string filename =
            "tests/fw_test.txt";

        generateWithoutNegativeCycle(
            V,
            E,
            filename
        );
    }
    else if(choice == 2)
    {
        string filename =
            "tests/fw_10.txt.txt";

        generateWithNegativeCycle(
            V,
            E,
            filename
        );
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}