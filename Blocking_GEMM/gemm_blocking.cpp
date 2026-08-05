#include "gemm_blocking.h"

void multiplyMatricesBlocking(
    int A[][MAX],
    int B[][MAX],
    int C[][MAX],
    int M,
    int K,
    int N)
{
    memset(C, 0, sizeof(int) * MAX * MAX);

    for(int ii = 0; ii < M; ii += BLOCK_SIZE)
    {
        for(int jj = 0; jj < N; jj += BLOCK_SIZE)
        {
            for(int kk = 0; kk < K; kk += BLOCK_SIZE)
            {
                for(int i = ii; i < min(ii + BLOCK_SIZE, M); i++)
                {
                    for(int j = jj; j < min(jj + BLOCK_SIZE, N); j++)
                    {
                        for(int k = kk; k < min(kk + BLOCK_SIZE, K); k++)
                        {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
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