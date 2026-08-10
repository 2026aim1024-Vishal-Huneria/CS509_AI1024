#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <set>
#include <string>

using namespace std;

struct Edge
{
    int to;
    int weight;
};


// ============================================================
// Generate graph WITHOUT negative cycle
// ============================================================

void generateWithoutNegativeCycle(
    int V,
    int E,
    const string& filename
)
{
    // Maximum number of edges in a DAG:
    //
    // V * (V - 1) / 2
    //
    // Use 1LL to prevent integer overflow.

    long long maxEdges =
        1LL * V * (V - 1) / 2;

    if((long long)E > maxEdges)
    {
        cout << "Too many edges for a DAG.\n";
        cout << "Maximum possible edges = "
             << maxEdges << "\n";

        return;
    }

    vector<vector<Edge>> adj(V);

    random_device rd;
    mt19937 gen(rd());

    // Edge weights from -10 to +10
    uniform_int_distribution<int> weightDist(-10, 10);

    set<pair<int, int>> usedEdges;

    int edgesCreated = 0;

    /*
        --------------------------------------------------------
        Generate a DAG
        --------------------------------------------------------

        Only create:

            u -> v

        where:

            u < v

        Example:

            0 -> 5
            2 -> 7
            10 -> 20

        Never:

            5 -> 0
            7 -> 2
            20 -> 10

        Therefore, a cycle is impossible.

        Since there is no cycle, a negative cycle
        is also impossible.

        Negative edge weights are still allowed.
    */

    while(edgesCreated < E)
    {
        int u = gen() % (V - 1);

        int v =
            u + 1 + (gen() % (V - u - 1));

        // Check duplicate
        if(usedEdges.count({u, v}))
            continue;

        usedEdges.insert({u, v});

        int weight = weightDist(gen);

        adj[u].push_back(
            {v, weight}
        );

        edgesCreated++;

        // Optional progress for very large graphs
        if(E >= 100000 && edgesCreated % 50000 == 0)
        {
            cout << "Edges generated: "
                 << edgesCreated
                 << " / "
                 << E
                 << "\n";
        }
    }


    // --------------------------------------------------------
    // Write file
    // --------------------------------------------------------

    ofstream fout(filename);

    if(!fout)
    {
        cout << "Error creating file: "
             << filename << "\n";

        return;
    }

    // First line:
    //
    // V E

    fout << V << " " << E << "\n";


    // --------------------------------------------------------
    // Write adjacency list
    // --------------------------------------------------------

    for(int u = 0; u < V; u++)
    {
        fout << u
             << " "
             << adj[u].size();

        for(const Edge& edge : adj[u])
        {
            fout << " "
                 << edge.to
                 << " "
                 << edge.weight;
        }

        fout << "\n";
    }


    // Source
    fout << "SOURCE 0\n";

    fout.close();


    // --------------------------------------------------------
    // Display information
    // --------------------------------------------------------

    cout << "\n";
    cout << "====================================\n";
    cout << "GRAPH GENERATED SUCCESSFULLY\n";
    cout << "====================================\n";

    cout << "File: "
         << filename
         << "\n";

    cout << "Vertices: "
         << V
         << "\n";

    cout << "Edges: "
         << E
         << "\n";

    cout << "Source: 0\n";

    cout << "Negative edges: allowed\n";

    cout << "Negative cycle: impossible\n";

    cout << "Graph type: DAG\n";

    cout << "====================================\n";
}


// ============================================================
// Generate graph WITH negative cycle
// ============================================================

void generateWithNegativeCycle(
    int V,
    int E,
    const string& filename
)
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

    // Maximum edges in a directed graph
    long long maxEdges =
        1LL * V * (V - 1);

    if((long long)E > maxEdges)
    {
        cout << "Too many edges.\n";
        cout << "Maximum possible edges = "
             << maxEdges
             << "\n";

        return;
    }


    vector<vector<Edge>> adj(V);

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> weightDist(-10, 10);

    set<pair<int, int>> usedEdges;


    // --------------------------------------------------------
    // Create guaranteed negative cycle
    // --------------------------------------------------------

    /*
        Cycle:

            0 -> 1
            1 -> 2
            2 -> 0

        Weights:

            0 -> 1 = 1
            1 -> 2 = -5
            2 -> 0 = -5

        Total:

            1 + (-5) + (-5)
            = -9

        Therefore:

            0 -> 1 -> 2 -> 0

        is definitely a negative cycle.
    */

    adj[0].push_back({1, 1});
    adj[1].push_back({2, -5});
    adj[2].push_back({0, -5});

    usedEdges.insert({0, 1});
    usedEdges.insert({1, 2});
    usedEdges.insert({2, 0});

    int edgesCreated = 3;


    // --------------------------------------------------------
    // Add remaining random edges
    // --------------------------------------------------------

    while(edgesCreated < E)
    {
        int u = gen() % V;
        int v = gen() % V;

        // No self-loop
        if(u == v)
            continue;

        // No duplicate edge
        if(usedEdges.count({u, v}))
            continue;

        usedEdges.insert({u, v});

        int weight = weightDist(gen);

        adj[u].push_back(
            {v, weight}
        );

        edgesCreated++;

        if(E >= 100000 && edgesCreated % 50000 == 0)
        {
            cout << "Edges generated: "
                 << edgesCreated
                 << " / "
                 << E
                 << "\n";
        }
    }


    // --------------------------------------------------------
    // Write file
    // --------------------------------------------------------

    ofstream fout(filename);

    if(!fout)
    {
        cout << "Error creating file.\n";
        return;
    }


    fout << V
         << " "
         << E
         << "\n";


    for(int u = 0; u < V; u++)
    {
        fout << u
             << " "
             << adj[u].size();

        for(const Edge& edge : adj[u])
        {
            fout << " "
                 << edge.to
                 << " "
                 << edge.weight;
        }

        fout << "\n";
    }


    fout << "SOURCE 0\n";

    fout.close();


    // --------------------------------------------------------
    // Display information
    // --------------------------------------------------------

    cout << "\n";
    cout << "====================================\n";
    cout << "NEGATIVE CYCLE GRAPH GENERATED\n";
    cout << "====================================\n";

    cout << "File: "
         << filename
         << "\n";

    cout << "Vertices: "
         << V
         << "\n";

    cout << "Edges: "
         << E
         << "\n";

    cout << "Source: 0\n";

    cout << "Negative edges: allowed\n";

    cout << "Negative cycle: GUARANTEED\n";

    cout << "\nNegative cycle:\n";

    cout << "0 -> 1 -> 2 -> 0\n";

    cout << "Cycle weight:\n";

    cout << "1 + (-5) + (-5) = -9\n";

    cout << "====================================\n";
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    int choice;
    int V;
    int E;

    cout << "========================================\n";
    cout << " Bellman-Ford Test Case Generator\n";
    cout << "========================================\n\n";

    cout << "1. Generate WITHOUT negative cycle\n";
    cout << "2. Generate WITH negative cycle\n\n";

    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;


    // --------------------------------------------------------
    // Basic validation
    // --------------------------------------------------------

    if(V <= 0)
    {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    if(E < 0)
    {
        cout << "Invalid number of edges.\n";
        return 1;
    }


    // --------------------------------------------------------
    // WITHOUT negative cycle
    // --------------------------------------------------------

    if(choice == 1)
    {
        string filename =
            "tests/bf_100000.txt";

        generateWithoutNegativeCycle(
            V,
            E,
            filename
        );
    }


    // --------------------------------------------------------
    // WITH negative cycle
    // --------------------------------------------------------

    else if(choice == 2)
    {
        string filename =
            "tests/bf_100000.txt";

        generateWithNegativeCycle(
            V,
            E,
            filename
        );
    }


    // --------------------------------------------------------
    // Invalid choice
    // --------------------------------------------------------

    else
    {
        cout << "Invalid choice.\n";
        return 1;
    }


    return 0;
}