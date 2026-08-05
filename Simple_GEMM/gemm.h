#ifndef GEMM_H
#define GEMM_H

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplyMatrices(
    const vector<vector<int>> &A,
    const vector<vector<int>> &B,
    int M,
    int K,
    int N);

void printMatrix(const vector<vector<int>> &C);

#endif