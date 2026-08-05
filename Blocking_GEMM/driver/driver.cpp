#include "../src/gemm.h"

int main()
{
    int choice;
    string fileName;

    cout << "1. Run Test 01\n";
    cout << "2. Run Test 02\n";
    cout << "3. Run Test 03\n";
    cout << "4. Run Test 04\n\n";

    cout << "Enter Choice : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            fileName = "tests/gemm_test_01.txt";
            break;

        case 2:
            fileName = "tests/gemm_test_02.txt";
            break;

        case 3:
            fileName = "tests/gemm_test_03.txt";
            break;

        case 4:
            fileName = "tests/gemm_test_04.txt";
            break;

        default:
            cout << "Invalid Choice\n";
            return 0;
    }
cout << "Opening: " << fileName << endl;

ifstream fin(fileName);

cout << "After ifstream\n";

    if(!fin)
    {
        cout << "Cannot open file\n";
        return 0;
    }

    int M, K, N;

    fin >> M >> K >> N;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    memset(C, 0, sizeof(C));

    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            fin >> A[i][j];

    for(int i = 0; i < K; i++)
        for(int j = 0; j < N; j++)
            fin >> B[i][j];

    auto start = chrono::high_resolution_clock::now();

    multiplyMatrix(A, B, C, M, K, N);

    auto end = chrono::high_resolution_clock::now();

    auto time =
        chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nAlgorithm : GEMM Blocking\n\n";

    cout << "Result Matrix\n";
    printMatrix(C, M, N);

    cout << "\nExecution Time : "
         << time.count()
         << " microseconds\n";

    return 0;
}