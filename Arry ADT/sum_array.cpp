#include <iostream>

int sum1(int A[], int n) {
    if (n < 0)
        return 0;
    else
        return sum1(A, n - 1) + A[n];
}

int sum2(int A[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += A[i];
    return total;
}

int main() {
    const int n = 5;
    int arr[n] = { 5, 2, 9, 1, 3 };


    std::cout << sum1(arr, n-1) << std::endl;

    std::cout << sum2(arr, n) << std::endl;


    return 0;
}
