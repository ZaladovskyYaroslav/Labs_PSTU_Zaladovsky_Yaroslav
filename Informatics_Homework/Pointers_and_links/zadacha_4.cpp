#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a = 5;
    int b = 8;
    int& r = a;
    int& s = a;
    int copy = a;

    r = b; // r = 8 = a = s
    s += 2; // s = 10 = a = r
    b = copy; // b = copy = 5

    cout << a << " " << b << " " << r << " " << s << " " << copy;



    return 0;
}







