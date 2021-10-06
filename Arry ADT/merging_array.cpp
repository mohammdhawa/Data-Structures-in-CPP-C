#include <iostream>

int* merging(int A[], int m, int B[], int n, int C[]) {
    int i, j, k;
    i = j = k = 0;

    while (i < m && j < n) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    for (; i < m; i++)
        C[k++] = A[i];
    for (; j < n; j++)
        C[k++] = B[j];

    return C;
}

int main() {
    const int n = 5;
    
    int ar1[n] = { 3, 8, 16, 20, 25 };
    int ar2[n] = { 4, 10, 12, 22, 23 };

    int* C = new int[n + n];

    merging(ar1, n, ar2, n, C);

    for (int i = 0; i < n + n; i++)
        std::cout << C[i] << ' ';
    std::cout << std::endl;


    return 0;
}
