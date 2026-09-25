#include <iostream>

int main() {
    // -- пункт 1
    int* a1 = new int(11);
    const int len = 7;
    int* a2 = new int[len];
    // -- пункт 2
    for (int i=0; i<len; ++i){
         a2[i]=(i+1)*2;
        std::cout << a2[i] << ' ';
    }
    // -- пункт 3
    int* v = new int(1);
    std::cout << v << "\n";
    std::cout << *v << "\n";
    delete v;
    std::cout << v << "\n";
    // -- пункт 4
    int* n = new int(999);
    std::cout << n << "\n"; // просто показал что выделилась та же память что и для висячего 
    // -- пункт 5
    const int newlen = len + 1;
    int* a3 = new int[newlen];   
    const int mid = len / 2;
    const int z = 123123;
    for (int i = 0; i < mid; ++i) {
        a3[i] = a2[i];
    }
    a3[mid] = z;
    for (int i = mid; i < len; ++i) {
        a3[i + 1] = a2[i];
    }
    for (int i = 0; i < len; ++i)    std::cout << a2[i] << ' ';
    std::cout << "\n";
    for (int i = 0; i < newlen; ++i) std::cout << a3[i] << ' ';
    std::cout << "\n";
    // -- пункт 6 
    delete a1;
    a1 = nullptr;     
    delete[] a2;      
    a2 = nullptr;
    delete[] a3;  
    a3 = nullptr;
    delete n;
    n = nullptr;
    return 0;

}