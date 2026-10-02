#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int main() {
    // Укажи здесь настоящие имена своих файлов
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

    // Большой вектор называем first, маленький second
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

    // 2. Количество чисел в каждом векторе
    cout << "First size: " << first.size() << endl;
    cout << "Second size: " << second.size() << endl;


    // 3a. Подсчёт количества каждого числа с помощью циклов

    cout << "\nFirst - count using for:\n";

    for (int i = 0; i < first.size(); i++) {
        bool already = false;

        // Проверяем, не считали ли это число раньше
        for (int j = 0; j < i; j++) {
            if (first[i] == first[j]) {
                already = true;
                break;
            }
        }

        if (!already) {
            int count = 0;

            for (int j = 0; j < first.size(); j++) {
                if (first[i] == first[j]) {
                    count++;
                }
            }

            cout << first[i] << " -> " << count << endl;
        }
    }


    cout << "\nSecond - count using for:\n";

    for (int i = 0; i < second.size(); i++) {
        bool already = false;

        for (int j = 0; j < i; j++) {
            if (second[i] == second[j]) {
                already = true;
                break;
            }
        }

        if (!already) {
            int count = 0;

            for (int j = 0; j < second.size(); j++) {
                if (second[i] == second[j]) {
                    count++;
                }
            }

            cout << second[i] << " -> " << count << endl;
        }
    }


    // 3b. Подсчёт с помощью std::count

    cout << "\nFirst - count using algorithm:\n";

    set<int> uniqueFirst(first.begin(), first.end());

    for (int number : uniqueFirst) {
        cout << number << " -> "
             << count(first.begin(), first.end(), number)
             << endl;
    }


    cout << "\nSecond - count using algorithm:\n";

    set<int> uniqueSecond(second.begin(), second.end());

    for (int number : uniqueSecond) {
        cout << number << " -> "
             << count(second.begin(), second.end(), number)
             << endl;
    }


    /// 4. Сумма всех элементов каждого вектора

    // Вариант 1: accumulate
    int sumFirst1 = accumulate(first.begin(), first.end(), 0);
    int sumSecond1 = accumulate(second.begin(), second.end(), 0);

    cout << "\nSum using accumulate:" << endl;
    cout << "First: " << sumFirst1 << endl;
    cout << "Second: " << sumSecond1 << endl;


    // Вариант 2: for_each
    int sumFirst2 = 0;
    int sumSecond2 = 0;

    for_each(first.begin(), first.end(), [&sumFirst2](int x) {
        sumFirst2 += x;
    });

    for_each(second.begin(), second.end(), [&sumSecond2](int x) {
        sumSecond2 += x;
    });

    cout << "\nSum using for_each:" << endl;
    cout << "First: " << sumFirst2 << endl;
    cout << "Second: " << sumSecond2 << endl;


    // 5. Сумма первых 10 элементов без циклов

    if (first.size() >= 10) {
        int first10 = accumulate(first.begin(), first.begin() + 10, 0);
        cout << "\nFirst 10 elements sum: " << first10 << endl;
    }

    if (second.size() >= 10) {
        int second10 = accumulate(second.begin(), second.begin() + 10, 0);
        cout << "Second 10 elements sum: " << second10 << endl;
    }

    return 0;
}