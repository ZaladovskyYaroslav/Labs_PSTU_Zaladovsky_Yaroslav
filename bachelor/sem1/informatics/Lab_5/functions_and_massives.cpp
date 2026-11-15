#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>
using namespace std;

void matrix(int n, int a[]){
    
    vector<vector<int>> b(n, vector<int>(n)); // Двумерный массив размером n на n

    // Заполнение всего массива единицами
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = 1;
        } 
    }

    for(int i = 0; i < n; i++){
        int s = 0; // Сумма элементов столбца без учёта последнего
        for(int j = 0; j < n - 1; j++){
            s += b[j][i];
        }
        b[n - 1][i] = a[i] - s; // Вычисляем последний элемент столбца так, чтобы сумма столбца равнялась a[i]
        // Избавляемся от нуля с сохранением общей суммы столбца (1 + 0 == 2 - 1)
        if(b[n - 1][i] == 0 && n > 1){
            b[0][i] = 2;
            b[n - 1][i] = -1;
        }
    }

    // Вывод элементов двумерного массива
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(4) << right << b[i][j];
        } cout << endl;
    }
}

int main(){
    setlocale(LC_ALL, ".UTF8");

    int a[] = {45, 2, -12, 3, 101};

    cout << "Исходный одномерный массив a: ";
    for(int i = 0; i < size(a); i++){
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Двумерный массив N * N: " << endl;
    matrix(size(a), a);

    return 0;
}