#include "gemm_blocking.h"

void runTest(string fileName)
{
    ifstream fin(fileName);

if (!fin)
{
    cout << "Cannot open file: " << fileName << endl;
    return;
}

cout << "File opened successfully\n";

    int M, K, N;
    fin >> M >> K >> N;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            fin >> A[i][j];

    for(int i = 0; i < K; i++)
        for(int j = 0; j < N; j++)
            fin >> B[i][j];

    auto start = chrono::high_resolution_clock::now();

    multiplyMatricesBlocking(A, B, C, M, K, N);

    auto end = chrono::high_resolution_clock::now();

    auto time =
        chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "=====================================\n";
    cout << "File : " << fileName << endl;
    cout << "Algorithm : GEMM Blocking\n\n";

    cout << "Result Matrix\n";
    printMatrix(C, M, N);

    cout << "\nExecution Time : "
         << time.count()
         << " microseconds\n";

    cout << "=====================================\n\n";
}

int main()
{
    int choice;

    cout << "1. Run Test 01\n";
    cout << "2. Run Test 02\n";
    cout << "3. Run Test 03\n";
    cout << "4. Run Test 04\n";
    cout << "5. Run All Tests\n\n";

    cout << "Enter Choice : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            runTest("gemm_test_01.txt");
            break;

        case 2:
            runTest("gemm_test_02.txt");
            break;

        case 3:
            runTest("gemm_test_03.txt");
            break;

        case 4:
            runTest("gemm_test_04.txt");
            break;

        case 5:
            runTest("gemm_test_01.txt");
            runTest("gemm_test_02.txt");
            runTest("gemm_test_03.txt");
            runTest("gemm_test_04.txt");
            break;

        default:
            cout << "Invalid Choice\n";
    }

    return 0;
}