# CS509 - Assignment 2

## Run Commands

### Bellman-Ford

```bash
g++ -std=c++17 -O2 driver/driver.cpp src/bellman_ford.cpp -o bellman_ford
./bellman_ford
Floyd-Warshall
g++ -std=c++17 -O2 driver/driver.cpp src/floyd_warshall.cpp -o floyd_warshall
./floyd_warshall
Bellman-Ford Algorithm
System Configuration
Algorithm: Bellman-Ford
Graph Type: Weighted Directed
Graph Representation: CSR
Language: C++
Compiler: g++
Negative Edges: Allowed
Negative Cycle Detection: Yes
Test Results
Test File	Vertices	Edges	Graph Type	Source	Negative Cycle	Execution Time (ms)	Status
bf_10.txt	10	-	Weighted Directed	0	No	-	-
bf_100.txt	100	-	Weighted Directed	0	No	-	-
bf_10000.txt	10000	-	Weighted Directed	0	No	-	-
bf_50000.txt	50000	-	Weighted Directed	0	No	-	-
bf_100000.txt	100000	-	Weighted Directed	0	No	-	-
Output

For each test case, the program prints:

Shortest distance from the source vertex
Negative cycle status
Execution time

Example:

Algorithm: Bellman-Ford
Source: 0

Vertex Distance
0 0
1 2
2 4
3 7
4 -2

Negative cycle: none
Execution time: 0.123 ms

If a negative cycle is detected:

Algorithm: Bellman-Ford
Source: 0

Negative cycle: true
Execution time: 0.123 ms
Complexity
Operation	Complexity
CSR Construction	O(V + E)
Bellman-Ford	O(V × E)
Memory	O(V + E)
Floyd-Warshall Algorithm
System Configuration
Algorithm: Floyd-Warshall
Graph Type: Weighted Directed
Graph Representation: Adjacency Matrix
Language: C++
Compiler: g++
Negative Edges: Allowed
Negative Cycle Detection: Yes
Test Results
Test File	Vertices	Edges	Graph Type	Source	Negative Cycle	Execution Time (ms)	Status
fw_10.txt	10	-	Weighted Directed	N/A	No	-	-
fw_100.txt	100	-	Weighted Directed	N/A	No	-	-
fw_500.txt	500	-	Weighted Directed	N/A	No	-	-
fw_1000.txt	1000	-	Weighted Directed	N/A	No	-	-
fw_2000.txt	2000	-	Weighted Directed	N/A	No	-	-
Output

For each test case, the program prints:

Shortest distance matrix
Negative cycle status
Execution time

Example:

Algorithm: Floyd-Warshall

Distance matrix:
0 1 -3 2 -4
3 0 -4 1 -1
7 4 0 5 3
2 -1 -5 0 -2
8 5 1 6 0

Negative cycle: none
Execution time: 0.005 ms

If a negative cycle is detected:

Algorithm: Floyd-Warshall

Negative cycle: true
Execution time: 0.002 ms
Complexity
Operation	Complexity
Floyd-Warshall	O(V³)
Memory	O(V²)
Cross-Check

For the 10 and 100 vertex graphs, Bellman-Ford is run from every vertex.

The Bellman-Ford results are compared with the corresponding rows of the Floyd-Warshall distance matrix.

Vertices	Bellman-Ford	Floyd-Warshall	Result
10	All sources tested	Distance matrix compared	-
100	All sources tested	Distance matrix compared	-
Timing

Only the algorithm execution time is measured.

The following are not included:

File reading
Input parsing
Memory allocation during setup
CSR conversion
Matrix construction
Output printing
File writing
Test Files
Bellman-Ford
bf_10.txt
bf_100.txt
bf_10000.txt
bf_50000.txt
bf_100000.txt
Floyd-Warshall
fw_10.txt
fw_100.txt
fw_500.txt
fw_1000.txt
fw_2000.txt
```
