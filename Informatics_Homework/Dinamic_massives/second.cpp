#include <iostream>
#include <clocale>
#include <random>
using namespace std;

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, ".UTF8");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];

    for(int i = 0; i < n; i++){
        *(a + i) = rand() % 100 + 1;
    }

    cout << "Полученный массив: ";
    for(int i = 0; i < n; i++){
        cout << *(a + i) << " ";
    }

    cout << endl;

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += *(a + i);
    }

    cout << "Сумма элементов: " << sum << endl;

    delete[] a;

    return 0;
}