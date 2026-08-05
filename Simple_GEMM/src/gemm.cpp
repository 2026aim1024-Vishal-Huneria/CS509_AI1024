#include "gemm.h"

void multiplyMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int M, int K, int N)
{
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
}

void printMatrix(int C[][MAX], int M, int N)
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
            cout << C[i][j] << " ";

        cout << endl;
    }
}