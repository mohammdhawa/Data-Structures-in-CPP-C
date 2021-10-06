#include <iostream>

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void reverse(int A[], int n) {
    int* B;
    B = new int[n];

    for (int i = n - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (int i = 0; i < n; i++)
        A[i] = B[i];


}

void reverse2(int A[], int n) {
    for (int i = 0, j = n - 1; i<j; i++, j--)
        swap(A[i], A[j]);
}

int main() {
    const int n = 5;
    int arr[n] = { 5, 2, 9, 1, 3 };

    reverse2(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;


    return 0;
}
