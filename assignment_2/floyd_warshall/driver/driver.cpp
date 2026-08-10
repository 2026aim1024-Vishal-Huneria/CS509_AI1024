#include <bits/stdc++.h>
#include "../src/floyd_warshall.h"

using namespace std;

const long long INF = 4000000000000000LL;

int main()
{
    // string fileName = "tests/floyd_warshall_test_1.txt";

    int choice;

cout << "1. Run fw_10.txt.txt\n";
cout << "2. Run fw_100.txt.txt\n";
cout << "3. Run fw_500.txt.txt\n";
cout << "4. Run fw_1000.txt.txt\n";
cout << "5. Run fw_2000.txt.txt\n";

cout << "Enter choice: ";
cin >> choice;

string fileName;

switch(choice)
{
    case 1:
        fileName = "tests/fw_10.txt.txt";
        break;

    case 2:
        fileName = "tests/fw_100.txt.txt";
        break;

    case 3:
        fileName = "tests/fw_500.txt.txt";
        break;

    case 4:
        fileName = "tests/fw_1000.txt.txt";
        break;

    case 5:
        fileName = "tests/fw_2000.txt.txt";
        break;

    default:
        cout << "Invalid choice\n";
        return 0;
}

    ifstream fin(fileName);

    if(!fin)
    {
        cout << "Cannot open file: "
             << fileName << "\n";

        return 1;
    }

    int vertices;

    fin >> vertices;

    vector<vector<long long>> matrix(
        vertices,
        vector<long long>(vertices, INF)
    );

    // Read matrix
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            string value;

            fin >> value;

            if(value == "INF")
            {
                matrix[i][j] = INF;
            }
            else
            {
                matrix[i][j] = stoll(value);
            }
        }
    }

    fin.close();

    // Run Floyd-Warshall
    auto start = chrono::high_resolution_clock::now();

    FloydWarshallResult result =
        floydWarshall(vertices, matrix);

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();

    cout << "Algorithm: Floyd-Warshall\n";

    if(result.negativeCycle)
    {
        cout << "Negative cycle: true\n";
    }
    else
    {
        cout << "Distance matrix:\n";

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                if(result.distance[i][j] == INF)
                    cout << "INF";
                else
                    cout << result.distance[i][j];

                if(j < vertices - 1)
                    cout << " ";
            }

            cout << "\n";
        }

        cout << "Negative cycle: none\n";
    }

    cout << fixed << setprecision(3);

    cout << "Execution time: "
         << executionTime
         << " ms\n";

    return 0;
}