#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int main() {
    // Читаем два файла
    ifstream f1("file1.txt");
    ifstream f2("file2.txt");

    vector<int> v1;
    vector<int> v2;

    int x;

    while (f1 >> x) {
        v1.push_back(x);
    }

    while (f2 >> x) {
        v2.push_back(x);
    }

    // Большой вектор - first
    // Маленький вектор - second
    vector<int> first;
    vector<int> second;

    if (v1.size() >= v2.size()) {
        first = v1;
        second = v2;
    }
    else {
        first = v2;
        second = v1;
    }

    // --------------------------------------------------
    // 1. Бинарная операция с accumulate
    // --------------------------------------------------

    int resultFirst = accumulate(
        first.begin(),
        first.end(),
        0,
        [](int a, int b) {
            return a + b;
        }
    );

    int resultSecond = accumulate(
        second.begin(),
        second.end(),
        0,
        [](int a, int b) {
            return a + b;
        }
    );

    cout << "1. Binary operation:" << endl;
    cout << "First: " << resultFirst << endl;
    cout << "Second: " << resultSecond << endl;


    // --------------------------------------------------
    // 2. Какие числа повторяются
    // --------------------------------------------------

    set<int> secondRepeated;
    set<int> firstRepeated;

    // Числа из второго вектора, которые встречаются 2 раза и больше
    for (int number : second) {
        if (count(second.begin(), second.end(), number) >= 2) {
            secondRepeated.insert(number);
        }
    }

    // Числа из первого вектора, которые встречаются больше 3 раз
    for (int number : first) {
        if (count(first.begin(), first.end(), number) > 3) {
            firstRepeated.insert(number);
        }
    }

    cout << "\n2. Repeated numbers:" << endl;

    cout << "Second vector (2 or more times): ";
    for (int number : secondRepeated) {
        cout << number << " ";
    }
    cout << endl;

    cout << "First vector (more than 3 times): ";
    for (int number : firstRepeated) {
        cout << number << " ";
    }
    cout << endl;


    // --------------------------------------------------
    // 3a. Цикл for
    // --------------------------------------------------

    cout << "\n3a. Using for:" << endl;

    for (int number : firstRepeated) {
        int countFirst = count(first.begin(), first.end(), number);
        int countSecond = count(second.begin(), second.end(), number);

        cout << number
             << " -> first: " << countFirst
             << ", second: " << countSecond
             << endl;
    }


    // --------------------------------------------------
    // Оставляем в отдельном векторе только числа,
    // которые встречаются в first больше 3 раз
    // --------------------------------------------------

    vector<int> filteredFirst;

    for (int number : first) {
        if (firstRepeated.count(number) > 0) {
            filteredFirst.push_back(number);
        }
    }

    cout << "\nFiltered first vector: ";

    for (int number : filteredFirst) {
        cout << number << " ";
    }

    cout << endl;


    // --------------------------------------------------
    // 3b. С использованием функций algorithm и lambda
    // --------------------------------------------------

    cout << "\n3b. Using algorithm and lambda:" << endl;

    for_each(
        firstRepeated.begin(),
        firstRepeated.end(),
        [&](int number) {
            int countFirst = count(first.begin(), first.end(), number);
            int countSecond = count(second.begin(), second.end(), number);

            cout << number
                 << " -> first: " << countFirst
                 << ", second: " << countSecond
                 << endl;
        }
    );


    return 0;
}