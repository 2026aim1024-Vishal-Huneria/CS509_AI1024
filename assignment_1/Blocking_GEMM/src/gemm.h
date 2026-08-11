#ifndef GEMM_H
#define GEMM_H

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define BLOCK_SIZE 2

void multiplyMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int M, int K, int N);

void printMatrix(int C[][MAX], int M, int N);

#endif