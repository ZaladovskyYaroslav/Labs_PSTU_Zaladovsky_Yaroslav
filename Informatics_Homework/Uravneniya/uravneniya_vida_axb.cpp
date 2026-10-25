#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");


    // Task 1
    float a, b, x;
   
    cout << "Введите число a: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;
   
    if(a == 0) {
        if(b == 0) {
            cout << "x - любое число";
        } else {
            cout << "Нет решений";
        }
    } else {
        x = b / a;
        cout << "Корень уравнения: " << x;
    }

    return 0;
}