# GEMM (General Matrix Multiplication)

# To Execute Simple Matrix Multplication

cd Simple_GEMM
g++ -std=c++17 -O2 driver/driver.cpp src/gemm.cpp -o gemm_simple.exe
gemm_simple.exe

g++ -std=c++17 -O2 driver/driver.cpp src/gemm.cpp -o gemm_blocking.exe

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
| gemm_test_01.txt | ...                     | Result Matrix   | Result Matrix |              ... |                ... |        ... | ✅ Pass |
| gemm_test_02.txt | ...                     | Result Matrix   | Result Matrix |              ... |                ... |        ... | ✅ Pass |
| gemm_test_03.txt | ...                     | Result Matrix   | Result Matrix |              ... |                ... |        ... | ✅ Pass |
| gemm_test_04.txt | ...                     | Result Matrix   | Result Matrix |              ... |                ... |        ... | ✅ Pass |

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
