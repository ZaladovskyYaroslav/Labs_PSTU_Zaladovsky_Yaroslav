#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main() {

    setlocale(LC_ALL, ".UTF8");

    double a_n = 1;
    double s = 0; 

    // Вычисление суммы 10 членов ряда с использованием рекуррентного множителя
    for(int n = 1; n <= 10; n++) {
        s += a_n;

        double mnoj = ((n + 1)  * pow(n, sqrt(n))) / pow(n + 1, sqrt(n + 1));

        a_n *= mnoj;
    }

    cout << "Сумма 10 членов ряда равна: " << s;

    return 0;
}




