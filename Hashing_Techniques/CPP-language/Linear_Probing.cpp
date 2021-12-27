#include <iostream>

#define SIZE 10

template <class T>
void printf(T& vec, int n, std::string s) {
    std::cout << s << ": [";
    for (int i = 0; i < n; i++) {
        std::cout << vec[i];
        if (i < n - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int Hash(int key) {
    return key % SIZE;
}

int LinearProbing(int H[], int key) {
    int idx = Hash(key);
    int i = 0; 
    while (H[(idx + i) % SIZE] != 0)
        i++;
    return (idx + i) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key);

    if (H[idx] != 0)
        idx = LinearProbing(H, key);
    H[idx] = key;
}

int search(int H[], int key) {
    int idx = Hash(key);
    int i = 0; 
    while (H[(idx + i) % SIZE] != key) {
        i++;
        if (H[(idx + i) % SIZE] == 0)
            return -1;
    }
    return (idx + i) % SIZE;
}


int main() {
    
    int A[] = { 26, 30, 45, 23, 25, 43, 74, 19, 29 };
    int n = sizeof(A) / sizeof(A[0]);
    printf(A, n, "A");

    // Hash Table
    int HT[10] = { 0 };
    for (int i = 0; i < n; i++)
        Insert(HT, A[i]);
    
    printf(HT, SIZE, "HT");

    int index = search(HT, 25);
    std::cout << "Key found at: " << index << std::endl;

    index = search(HT, 35);
    std::cout << "Key found at: " << index << std::endl;


    return 0;

}
