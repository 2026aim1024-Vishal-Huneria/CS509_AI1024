# CS509 - Assignment 2

## Run Commands

### Bellman-Ford

```bash
g++ -std=c++17 -O2 driver/driver.cpp src/bellman_ford.cpp -o bellman_ford

./bellman_ford
```
### result tabel
| Algorithm | Test File | Vertices | Edges | Source | Negative Cycle | Expected Output | Actual Output | Time | Status |
|---|---|---:|---:|---:|---|---|---|---:|---|
| Bellman-Ford | `bf_10.txt` | 10 | ... | 0 | No | Distances | ... | ... ms | Pass/Fail |
| Floyd-Warshall | `fw_10.txt` | 10 | ... | N/A | No | Distance matrix | ... | ... ms | Pass/Fail |
