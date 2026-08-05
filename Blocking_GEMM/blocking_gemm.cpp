#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define BLOCK_SIZE 2

void printMatrix(int C[][MAX], int M, int N)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            cout<<C[i][j]<<" ";

        cout<<endl;
    }
}

int main()
{
    ifstream fin("gemm_test_02.txt");

    if(!fin)
    {
        cout<<"File not found\n";
        return 0;
    }

    int M,K,N;

    fin>>M>>K>>N;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    memset(C,0,sizeof(C));

    for(int i=0;i<M;i++)
        for(int j=0;j<K;j++)
            fin>>A[i][j];

    for(int i=0;i<K;i++)
        for(int j=0;j<N;j++)
            fin>>B[i][j];

    auto start=chrono::high_resolution_clock::now();

    for(int ii=0;ii<M;ii+=BLOCK_SIZE)
    {
        for(int jj=0;jj<N;jj+=BLOCK_SIZE)
        {
            for(int kk=0;kk<K;kk+=BLOCK_SIZE)
            {
                for(int i=ii;i<min(ii+BLOCK_SIZE,M);i++)
                {
                    for(int j=jj;j<min(jj+BLOCK_SIZE,N);j++)
                    {
                        for(int k=kk;k<min(kk+BLOCK_SIZE,K);k++)
                        {
                            C[i][j]+=A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }
    }

    auto end=chrono::high_resolution_clock::now();

    auto time=chrono::duration_cast<chrono::microseconds>(end-start);

    cout<<"Algorithm : GEMM Blocking\n\n";

    cout<<"Result Matrix\n";

    printMatrix(C,M,N);

    cout<<"\nExecution Time : "<<time.count()<<" microseconds"<<endl;

    return 0;
}