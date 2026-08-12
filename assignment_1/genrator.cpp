#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    int M, N, K;

    cout << "Enter M N K: ";
    cin >> M >> N >> K;

    ofstream f("gemm_test_150.txt");

    if (!f) {
        cerr << "Error opening file!\n";
        return 1;
    }

    // Random number generator: values from 1 to 9
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 9);

    // First line: M N K
    f << M << " " << N << " " << K << "\n\n";

    // Matrix A (M x K)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            f << dist(gen);

            if (j < K - 1)
                f << " ";
        }
        f << "\n";
    }

    f << "\n";

    // Matrix B (K x N)
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            f << dist(gen);

            if (j < N - 1)
                f << " ";
        }
        f << "\n";
    }

    f.close();

    cout << "gemm_test_150.txt generated successfully!\n";

    return 0;
}