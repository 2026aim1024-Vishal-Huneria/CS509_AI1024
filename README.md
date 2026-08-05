# GEMM (General Matrix Multiplication)

## To Execute Simple Matrix Multplication

- cd Simple_GEMM
- g++ -std=c++17 -O2 driver/driver.cpp src/gemm.cpp -o gemm_simple.exe
- gemm_simple.exe

## To Execute blocking Matrix Multplication

- cd Blocking_GEMM
- g++ -std=c++17 -O2 driver/driver.cpp src/gemm.cpp -o gemm_blocking.exe
- gemm_blocking.exe

## To Execute CSR

- cd CSR_graph
- g++ -std=c++17 -O2 csr_graph.cpp -o csr_graph.exe
- csr_graph.exe

## Overview

This project implements General Matrix Multiplication (GEMM).

Given:

- Matrix **A** of size **M × K**
- Matrix **B** of size **K × N**

The output matrix **C** is computed as:

```
C = A × B
```

where

```
C[i][j] = Σ (A[i][k] × B[k][j])
```

Two implementations are provided:

- **Simple GEMM** – Standard triple nested-loop implementation.
- **Blocking GEMM** – Matrix multiplication using cache-friendly blocking (tiling).

Both implementations produce the same output matrix for identical input.

---

## Project Structure

```
GEMM/
│
├── driver/
│   └── driver.cpp
│
├── src/
│   ├── gemm.cpp
│   └── gemm.h
│
└── tests/
    ├── gemm_test_01.txt
    ├── gemm_test_02.txt
    ├── gemm_test_03.txt
    └── gemm_test_04.txt
```

---

## Compilation

```bash
g++ -std=c++17 -O2 driver/driver.cpp src/gemm.cpp -o gemm.exe
```

---

## Running

```bash
./gemm.exe
```

The program displays a menu to select a test case.

---

# Results

| Test File        | Matrix Size (M×K × K×N) | Expected Output | Actual Output | Simple Time (µs) | Blocking Time (µs) | Block Size | Status  |
| ---------------- | ----------------------- | --------------- | ------------- | ---------------: | -----------------: | ---------: | :-----: |
| gemm_test_01.txt | 10x10 10x10                     | Result Matrix   | Result Matrix |              4 |                5 |        16 | ✅ Pass |
| gemm_test_02.txt | 100x100 100x100                     | Result Matrix   | Result Matrix |              2600 |                4881 |        16 | ✅ Pass |
| gemm_test_03.txt | 500x500 500x500                     | Result Matrix   | Result Matrix |              ... |                ... |        16 | ✅ Pass |
| gemm_test_04.txt | 1000x1000 1000x100                     | Result Matrix   | Result Matrix |              ... |                ... |        16 | ✅ Pass |

---

## Notes

- Both implementations generate identical result matrices.
- Blocking GEMM improves cache utilization by processing matrices in tiles.
- Execution time is measured using `std::chrono`.

---

## Complexity

| Implementation | Time Complexity | Space Complexity |
| -------------- | --------------- | ---------------- |
| Simple GEMM    | O(M × K × N)    | O(M × N)         |
| Blocking GEMM  | O(M × K × N)    | O(M × N)         |
