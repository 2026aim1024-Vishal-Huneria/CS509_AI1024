#ifndef GEMM_BLOCKING_H
#define GEMM_BLOCKING_H

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define BLOCK_SIZE 2

void multiplyMatricesBlocking(
    int A[][MAX],
    int B[][MAX],
    int C[][MAX],
    int M,
    int K,
    int N);

void printMatrix(int C[][MAX], int M, int N);

#endif