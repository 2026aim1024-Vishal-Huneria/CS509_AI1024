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
| Bellman-Ford | `bf_10.txt`    | 10       | 40     | 0      | No             | Distances       | ...           | 0.001 ms | Pass |
| Bellman-Ford | `bf_100.txt`   | 100      | 400     | 0      | No             | Distances       | ...           | 0.003 ms | Pass |
| Bellman-Ford | `bf_10000.txt` | 10,000   | 40,000     | 0      | No             | Distances       | ...           | 0.164 ms | Pass |
| Bellman-Ford | `bf_50000.txt` | 50,000   | 1,00,000     | 0      | No             | Distances       | ...           | 0.483 ms | Pass |
| Bellman-Ford | `bf_100000.txt`| 100,000  | 4,00,000     | 0      | No             | Distances       | ...           | 1.126 ms | Pass |

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
| Floyd-Warshall | `fw_10.txt`     | 10       | 10   | N/A    | No             | Distance matrix | Distance matrix            | 0.003 ms | Pass |
| Floyd-Warshall | `fw_100.txt`    | 100      | 100   | N/A    | No             | Distance matrix | Distance matrix           | 0.314 ms | Pass |
| Floyd-Warshall | `fw_500.txt`    | 500      | 500   | N/A    | No             | Distance matrix | Distance matrix            | 14.606 ms | Pass |
| Floyd-Warshall | `fw_1000.txt`   | 1,000    | 1,000   | N/A    | No             | Distance matrix | Distance matrix            | 54.044 ms | Pass |
| Floyd-Warshall | `fw_2000.txt`   | 2,000    | 2,000   | N/A    | No             | Distance matrix | Distance matrix            | 665.139 ms | Pass |

