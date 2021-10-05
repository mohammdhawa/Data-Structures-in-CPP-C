#include <iostream>

int A[15] = { 4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 41, 43, 45 };

int BinSearch1(int l, int h, int key) { // using iterative
    int mid;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int BinSearch2(int l, int h, int key) {    // using Recursion
    int mid;

    if (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return BinSearch2(l, mid - 1, key);
        else
            return BinSearch2(mid + 1, h, key);
    }
    return -1;
}

int main() {
    

    std::cout << BinSearch1(0, 14, 18) << std::endl;

    std::cout << BinSearch2(0, 14, 33) << std::endl;


    return 0;
}
