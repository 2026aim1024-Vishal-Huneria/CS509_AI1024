#include "gemm.h"

vector<vector<int>> multiplyMatrices(
    const vector<vector<int>> &A,
    const vector<vector<int>> &B,
    int M,
    int K,
    int N)
{
    vector<vector<int>> C(M, vector<int>(N, 0));

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < K; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>> &C)
{
    for(int i = 0; i < C.size(); i++)
    {
        for(int j = 0; j < C[i].size(); j++)
            cout << C[i][j] << " ";

        cout << endl;
    }
}