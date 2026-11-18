#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main(){

    setlocale(LC_ALL, ".UTF8");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* a = new int[n];

    cout << "Введите элементы массива: ";
    for(int i = 0; i < n; i++){
        cin >> *(a + i);
    }

    for(int i = 0; i < n; i++){
        if((i == 0) && (abs(*(a + i)) % 2 == 0)){
            *(a + i) = 0;
        }
        else if((i == n - 1) && (abs(*(a + i)) % 2 == 0)){
            *(a + i) = 0;
        }
        else if(abs(*(a + i)) % 2 == 0){
            *(a + i) = *(a + i + 1) + *(a + i - 1);
        }
    }

    cout << "Массив после замены: ";
    for(int i = 0; i < n; i++){
        cout << *(a + i) << " ";
    }

    delete[] a;

    return 0;
}