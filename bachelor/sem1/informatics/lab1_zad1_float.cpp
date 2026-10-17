#include <iostream>
#include <cmath>       // Для возведения в степень
#include <iomanip>    // Для управления количеством знаков после точки в действительных числах
#include <clocale>   // Для работы с кириллицей
using namespace std;
int main() {
    setlocale(LC_ALL, ".UTF8");

    float a = 1000;
    float b = 0.0001;
    float num1, num2, num3, num4, num5;

    num1 = pow((a + b), 3);
    num2 = pow(a, 3) + 3 * pow(a, 2) * b;
    num3 = num1 - num2;
    num4 = 3 * a * pow(b, 2) + pow(b, 3);
    num5 = num3 / num4;

    cout << fixed << setprecision(12) <<     // Для принудительный вывода 12 знаков после запятой
    // для наглядности погрешности
    "Первое действие: " << num1 << '\n' << 
    "Второе действие: " << num2 << '\n' << 
    "Третье действие: " << num3 << '\n' << 
    "Четвёртое действие: " << num4 << '\n' <<
    "Пятое действие: " << num5;

    return 0;
}






