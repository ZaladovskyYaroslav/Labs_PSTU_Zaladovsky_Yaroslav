#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    // Task 2
    double a, b, c, D, sqrtD, x1, x2;

    cout << "Введите первый коэффициент: ";
    cin >> a;
    cout << "Введите второй коэффициент: ";
    cin >> b;
    cout << "Введите свободный член: ";
    cin >> c;

    if(a == 0) {
        if(b != 0) {
            x1 = -c / b + 0.0;
            cout << "Корень уравнения: " << x1;
        } else {
            if (c == 0) {
                cout << "x - любое";
            } else {
                cout << "Нет корней";
            }
        }
    } else {
        D = pow(b, 2) - 4*a*c;

        if(D < 0) {
            cout << "Нет корней";
        } 
        else if(D == 0) {
            x1 = -b / (2*a) + 
            0.0;
            cout << "Корень уравнения: " << x1;
        }
        else {
            sqrtD = sqrt(D);
            x1 = ((-b + sqrtD) / (2*a)) + 0.0;
            x2 = ((-b - sqrtD) / (2*a)) + 0.0;
            cout << "Первый корень уравнения: " << x1 << '\n';
            cout << "Второй корень уравнения: " << x2 << '\n';
        }
    }


    return 0;
}