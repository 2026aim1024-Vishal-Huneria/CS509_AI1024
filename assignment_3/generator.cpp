#include <bits/stdc++.h>

using namespace std;

/*
    MST Graph Generator

    Generates weighted undirected connected graphs.

    Files generated:
        tests/mst_10.txt
        tests/mst_100.txt
        tests/mst_10000.txt
        tests/mst_50000.txt
        tests/mst_100000.txt

    Format:

        V E

        vertex degree neighbor weight neighbor weight ...

    Since the graph is undirected, every edge is written
    in the adjacency list of both endpoints.

    E counts each undirected edge only once.
*/

struct Edge
{
    int u;
    int v;
    int weight;
};

uint64_t makeKey(int u, int v)
{
    if(u > v)
        swap(u, v);

    return (static_cast<uint64_t>(u) << 32)
           | static_cast<uint32_t>(v);
}

void generateGraph(int vertices, int edges, const string& fileName)
{
    cout << "Generating " << fileName
         << " : V = " << vertices
         << ", E = " << edges << endl;

    vector<Edge> edgeList;
    edgeList.reserve(edges);

    vector<vector<pair<int, int>>> adjacency(vertices);

    unordered_set<uint64_t> usedEdges;
    usedEdges.reserve(edges * 2);

    random_device rd;
    mt19937 rng(rd());

    uniform_int_distribution<int> weightDist(1, 100);

    /*
        ------------------------------------------------
        Step 1: Create a connected spanning tree
        ------------------------------------------------

        Every vertex i (1 ... V-1) is connected to
        one earlier vertex.

        This guarantees that the graph is connected.
    */

    for(int v = 1; v < vertices; v++)
    {
        uniform_int_distribution<int> parentDist(0, v - 1);

        int u = parentDist(rng);

        int weight = weightDist(rng);

        uint64_t key = makeKey(u, v);

        usedEdges.insert(key);

        edgeList.push_back({u, v, weight});

        adjacency[u].push_back({v, weight});
        adjacency[v].push_back({u, weight});
    }

    /*
        ------------------------------------------------
        Step 2: Add random edges
        ------------------------------------------------

        Continue adding edges until E is reached.
    */

    uniform_int_distribution<int> vertexDist(0, vertices - 1);

    while((int)edgeList.size() < edges)
    {
        int u = vertexDist(rng);
        int v = vertexDist(rng);

        if(u == v)
            continue;

        if(u > v)
            swap(u, v);

        uint64_t key = makeKey(u, v);

        if(usedEdges.find(key) != usedEdges.end())
            continue;

        usedEdges.insert(key);

        int weight = weightDist(rng);

        edgeList.push_back({u, v, weight});

        adjacency[u].push_back({v, weight});
        adjacency[v].push_back({u, weight});
    }

    /*
        ------------------------------------------------
        Step 3: Write file
        ------------------------------------------------
    */

    ofstream fout(fileName);

    if(!fout)
    {
        cerr << "Cannot create file: "
             << fileName << endl;
        return;
    }

    // First line
    fout << vertices << " "
         << edges << "\n";

    /*
        Write adjacency list.

        Example:

        5 7
        0 2 1 2 3 6
        1 4 0 2 2 3 3 8 4 5
        ...
    */

    for(int u = 0; u < vertices; u++)
    {
        fout << u << " "
             << adjacency[u].size();

        for(auto [v, weight] : adjacency[u])
        {
            fout << " "
                 << v
                 << " "
                 << weight;
        }

        fout << "\n";
    }

    fout.close();

    cout << "Created: "
         << fileName << endl;
}

int main()
{
    /*
        Required graph sizes.

        We keep large graphs sparse,
        approximately E = 2V to 4V.
    */

    vector<pair<int, int>> testCases =
    {
        {10, 20},
        {100, 250},
        {10000, 30000},
        {50000, 150000},
        {100000, 300000}
    };

    /*
        Create tests directory.
    */

    filesystem::create_directories("tests");

    for(auto [vertices, edges] : testCases)
    {
        string fileName =
            "tests/mst_" +
            to_string(vertices) +
            ".txt";

        generateGraph(
            vertices,
            edges,
            fileName
        );
    }

    cout << "\nAll MST test files generated successfully.\n";

    return 0;
}