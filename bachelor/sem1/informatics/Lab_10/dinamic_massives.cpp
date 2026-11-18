#include <iostream>
#include <clocale>
#include <string>
using namespace std;

// Вывод всех элементов динамического массива на экран
void show(string* a, const int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// Удаление последних элементов из массива в количестве "count"
void pop_back(string*& a, int& size, const int count){
    // Если будут удалены все строки в массиве
    if(count == size){
        delete[] a;
        a = nullptr; // Обнуление указателя, чтобы избежать двойного удаления в функции main
        size = 0; // Обнуление размера массива
        cout << "Все строки в массиве удалены" << endl;
        return;
    }

    size -= count; // Уменьшение размера массива на "count"
    string* new_a = new string[size]; // Новый динамический массив

    for(int i = 0; i < size; i++){
        new_a[i] = a[i];
    }

    delete[] a;
    a = new_a; // Перенаправление основного указателя на новый массив
    cout << "Массив без удалённых строк: ";
    show(a, size);
}

// Удаление повторяющихся строк
void pop_back_repeat(string*& a, int& size){
    string* b = new string[size]; // Временный массив для хранения уникальных строк
    int r = 0; // Счётчик количества найденных уникальных строк
    for(int i = 0; i < size; i++){
        bool isdDuplicate = false; // Флажок, который показывает, встречалась ли строка раньше
        for(int j = 0; j < r; j++){
            if(a[i] == b[j]){
                isdDuplicate = true;
            }
        }
        // Если строка уникальна, добавляем её в массив b
        if(!isdDuplicate){
            b[r] = a[i];
            r++;
        }
    }

    // Если количество уникальных строк совпало с исходной длиной, то повторов не было
    if(r == size){
        delete[] b;
        cout << "В массиве нет повторяющихся строк" << endl;
        return;
    } 

    // Создание итогового массива для уникальных элементов
    string* new_a = new string[r];
    for(int i = 0; i < r; i++){
        new_a[i] = b[i];
    }

    delete[] b;
    delete[] a;
    a = new_a; // Перенаправление основного указателя на новый массив без повторов строк
    size = r; 
    cout << "Массив без повторяющихся строк: ";
    show(a, size);
}


int main(){
    setlocale(LC_ALL, ".UTF8");

    int size; // Исходная длина массива
    int count; // Количество удаляемых строк
    
    cout << "Введите длину массива: ";
    cin >> size;
    
    string* a = new string[size];

    cout << "Введите массив строк: ";
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }

    cout << "Начальный массив строк: ";
    show(a, size);

    pop_back_repeat(a, size);

    cout << "Введите количество строк, которые будут удалены (от 0 до " << size << "): ";
    cin >> count;
    pop_back(a, size, count);

    delete[] a;

    return 0;
}