import random

# Input dimensions
M, N, K = map(int, input("Enter M N K: ").split())

with open("gemm_test_150.txt", "w") as f:
    # First line
    f.write(f"{M} {N} {K}\n\n")

    # Matrix A (M x K)
    for i in range(M):
        row = []
        for j in range(K):
            row.append(str(random.randint(1, 9)))
            
        f.write(" ".join(row) + "\n")

    f.write("\n")

    # Matrix B (K x N) with random values 1 to 9
    for i in range(K):
        row = []
        for j in range(N):
            row.append(str(random.randint(1, 9)))
        f.write(" ".join(row) + "\n")

print("text.txt generated successfully!")