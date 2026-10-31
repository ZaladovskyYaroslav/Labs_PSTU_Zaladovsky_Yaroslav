#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a[3][3] = {56, -40, 678, -346, 566, 23, 1, 8, 57};

    int rows = size(a);
    int columns = size(a[0]);

    int summa = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            summa += a[i][j];
        }
        cout << "Сумма элементов " << i + 1 << " строки: " << summa << '\n';
        summa = 0;
    }

    return 0;
}