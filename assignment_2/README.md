# CS509 - Assignment 2

## Bellman-Ford

### System Configuration

- **Algorithm**: Bellman-Ford
- **Graph Type**: Weighted Directed
- **Graph Representation**: CSR
- **Negative Edges**: Allowed
- **Negative Cycle Detection**: Yes
- **Time Complexity**: O(V × E)
- **Space Complexity**: O(V + E)

### Result Table

| Algorithm    | Test File      | Vertices | Edges   | Source | Negative Cycle | Expected Output | Actual Output | Time | Status |
|--------------|----------------|---------:|--------:|-------:|----------------|-----------------|---------------|-----:|--------|
| Bellman-Ford | `bf_10.txt`    | 10       | ...     | 0      | No             | Distances       | ...           | ... ms | Pass/Fail |
| Bellman-Ford | `bf_100.txt`   | 100      | ...     | 0      | No             | Distances       | ...           | ... ms | Pass/Fail |
| Bellman-Ford | `bf_10000.txt` | 10,000   | ...     | 0      | No             | Distances       | ...           | ... ms | Pass/Fail |
| Bellman-Ford | `bf_50000.txt` | 50,000   | ...     | 0      | No             | Distances       | ...           | ... ms | Pass/Fail |
| Bellman-Ford | `bf_100000.txt`| 100,000  | ...     | 0      | No             | Distances       | ...           | ... ms | Pass/Fail |

---

## Floyd-Warshall

- **Algorithm**: Floyd-Warshall
- **Graph Type**: Weighted Directed
- **Graph Representation**: Adjacency Matrix
- **Negative Edges**: Allowed
- **Negative Cycle Detection**: Yes
- **Time Complexity**: O(V³)
- **Space Complexity**: O(V²)

### Result Table

| Algorithm      | Test File       | Vertices | Edges | Source | Negative Cycle | Expected Output | Actual Output | Time | Status |
|----------------|-----------------|---------:|------:|-------:|----------------|-----------------|---------------|-----:|--------|
| Floyd-Warshall | `fw_10.txt`     | 10       | ...   | N/A    | No             | Distance matrix | ...           | ... ms | Pass/Fail |
| Floyd-Warshall | `fw_100.txt`    | 100      | ...   | N/A    | No             | Distance matrix | ...           | ... ms | Pass/Fail |
| Floyd-Warshall | `fw_500.txt`    | 500      | ...   | N/A    | No             | Distance matrix | ...           | ... ms | Pass/Fail |
| Floyd-Warshall | `fw_1000.txt`   | 1,000    | ...   | N/A    | No             | Distance matrix | ...           | ... ms | Pass/Fail |
| Floyd-Warshall | `fw_2000.txt`   | 2,000    | ...   | N/A    | No             | Distance matrix | ...           | ... ms | Pass/Fail |

---

## Input Format

### Bellman-Ford

Bellman-Ford uses a **weighted directed adjacency-list** format.

```text
V E
u degree neighbor weight neighbor weight ...
...
SOURCE s
