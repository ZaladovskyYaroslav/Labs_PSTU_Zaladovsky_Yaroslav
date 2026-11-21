#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Salary{
    string FIO;
    int days_worked;
    double day_payment;
    double bonus;
};

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Salary Worker;

    printf("Введите ФИО работника: ");
    getline(cin, Worker.FIO);
    printf("Введите количество отработанных дней: ");
    cin >> Worker.days_worked;
    printf("Введите оплату за день: ");
    cin >> Worker.day_payment;
    printf("Введите размер премии: ");
    cin >> Worker.bonus;

    cout << fixed << setprecision(2) << "Зарплата рабочего " << Worker.FIO << " составляет " << Worker.days_worked * Worker.day_payment + Worker.bonus << endl;

    return 0;
}