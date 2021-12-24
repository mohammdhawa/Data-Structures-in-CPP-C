#include <iostream>
#include <vector>

void Insert(int A[], int n) {
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

// or using stl
void insert_stl(std::vector<int>& vec, int key) {
    auto i = vec.size();
    vec.emplace_back(key);

    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    vec[i] = key;
}

template <class T>
void print(T& ve, int n) {
    std::cout << "Max heap: [";
    for (int i = 0; i < n; i++) {
        std::cout << ve[i] << ' ';
        if (i < n - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {

    int a[] = { 45, 35, 15, 30, 10, 12, 6, 5, 20, 50 };
    Insert(a, 9);
    print(a, sizeof(a) / sizeof(a[0]));
    std::cout << std::endl;


    return 0;
}
