#include <iostream>

void insert(int H[], int n) {
    int i = n, temp;
    temp = H[i];

    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int Delete(int A[], int n) {
    int val = A[1];
    int i, j, x, temp;
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2 * i;

    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    return val;
}

int main() {

    int H[] = { 0, 10, 20, 30, 25, 5, 40, 35 };
    // 40, 25, 35, 10, 5, 20, 30

    for (int i = 2; i <= sizeof(H) / sizeof(H[0]) - 1; i++)
        insert(H, i);

    for (int i = 1; i <= 7; i++)
        std::cout << H[i] << ' ';
    std::cout << std::endl;

    for (int i = 7; i > 1; i--)
        Delete(H, i);

    for (int i = 1; i <= 7; i++)
        std::cout << H[i] << ' ';
    std::cout << std::endl;


    return 0;
}
