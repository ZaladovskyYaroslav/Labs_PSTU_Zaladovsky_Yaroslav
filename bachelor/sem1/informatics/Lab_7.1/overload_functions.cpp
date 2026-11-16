#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

// Перегрузка для массива целых чисел (int)
int chetM(int n, int a[]){
    int k = a[0];

    if(k % 2 != 0){
        cout << "Первый элемент массива должен быть чётным" << endl;
        return 1;
    }

    for(int i = 0; i < k; i++){
        int first = a[0];
        for(int j = 0; j < n - 1; j++){
            a[j] = a[j + 1];
        }
        a[n - 1] = first;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива длинных целых чисел (long)
int chetM(int n, long a[]) {
    long k = a[0];

    if (k % 2 != 0) {
        cout << "Первый элемент массива должен быть чётным" << endl;
        return 1;
    }

    for (long i = 0; i < k; i++) {
        long first = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = first;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива действительных чисел двойной точности (double)
int chetM(int n, double a[]) {
    if (fmod(a[0], 1.0) != 0.0 || (long)a[0] % 2 != 0){
        cout << "Первый элемент массива должен быть чётным целым числом" << endl;
        return 1;
    }

    long k = (long)a[0];

    for (long i = 0; i < k; i++) {
        double first = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = first;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива вещественных чисел одинарной точности (float)
int chetM(int n, float a[]) {
    if (fmod(a[0], 1.0f) != 0.0f || (long)a[0] % 2 != 0) {
        cout << "Первый элемент массива должен быть чётным целым числом" << endl;
        return 1;
    }

    long k = (long)a[0];

    for (long i = 0; i < k; i++) {
        float first = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = first;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива целых чисел (int)
int nechetM(int n, int a[]){
    int k = a[n - 1];

    if(a[0] % 2 == 0){
        cout << "Первый элемент массива должен быть нечётным" << endl;
        return 1;
    }

    for(int i = 0; i < k; i++){
        int last = a[n - 1];
        for(int j = n - 1; j > 0; j--){
            a[j] = a[j - 1];
        }
        a[0] = last;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива длинных целых чисел (long)
int nechetM(int n, long a[]){
    long k = a[n - 1];

    if(a[0] % 2 == 0){
        cout << "Первый элемент массива должен быть нечётным" << endl;
        return 1;
    }

    for(long i = 0; i < k; i++){
        long last = a[n - 1];
        for(int j = n - 1; j > 0; j--){
            a[j] = a[j - 1];
        }
        a[0] = last;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива вещественных чисел (double)
int nechetM(int n, double a[]){
    
    if(fmod(a[0], 1.0) != 0.0 || long(a[0]) % 2 == 0){
        cout << "Первый элемент массива должен быть целым нечётным числом" << endl;
        return 1;
    }
    if(fmod(a[n - 1], 1.0) != 0){
        cout << "Последний элемент должен быть целым числом" << endl;
        return 1;
    }
    
    long k = (long)a[n - 1];
    
    for(long i = 0; i < k; i++){
        double last = a[n - 1];
        for(int j = n - 1; j > 0; j--){
            a[j] = a[j - 1];
        }
        a[0] = last;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

// Перегрузка для массива вещественных чисел (float)
int nechetM(int n, float a[]){
    long k = (long)a[n - 1];

    if(fmod(a[0], 1.0f) != 0.0f || long(a[0]) % 2 == 0){
        cout << "Первый элемент массива должен быть целым нечётным числом" << endl;
        return 1;
    }
    if(fmod(a[n - 1], 1.0) != 0){
        cout << "Последний элемент должен быть целым числом" << endl;
        return 1;
    }

    for(long i = 0; i < k; i++){
        float last = a[n - 1];
        for(int j = n - 1; j > 0; j--){
            a[j] = a[j - 1];
        }
        a[0] = last;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

int main(){

    setlocale(LC_ALL, ".UTF8");

    int a[] = {2, 3, 1, 67, 45, 2};
    long b[] = {4L, 45L, 12L, 5L, 7L};
    double c[] = {2.0, 34.6, 12.3, 67.34};
    float d[] = {8.0f, 345.677f, 212.8f, 90.5f, 45.55f};

    cout << "Задание а)" << endl;

    cout << "Результат для массива с типом данных int: ";
    chetM(size(a), a);
    cout << endl;

    cout << "Результат для массива с типом данных long: ";
    chetM(size(b), b);
    cout << endl;

    cout << "Результат для массива с типом данных double: ";
    chetM(size(c), c);
    cout << endl;

    cout << "Результат для массива с типом данных float: ";
    chetM(size(d), d);
    cout << endl;
    cout << endl;

    cout << "Задание б)" << endl;

    int e[] = {3, 2, 1, 12, 4};
    long t[] = {13L, 10L, 5L, 2};
    double w[] = {3.0, 1.2, 5.6, 23.5, 1.0};
    float q[] = {1.0f, 56.8f, 34.0f, 5.5f, 2.0f};

    cout << "Результат для массива с типом данных int: ";
    nechetM(size(e), e);
    cout << endl;

    cout << "Результат для массива с типом данных long: ";
    nechetM(size(t), t);
    cout << endl;

    cout << "Результат для массива с типом данных double: ";
    nechetM(size(w), w);
    cout << endl;

    cout << "Результат для массива с типом данных float: ";
    nechetM(size(q), q);

    return 0;
}