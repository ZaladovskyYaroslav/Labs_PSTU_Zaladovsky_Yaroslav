#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a = 2;
    int b = 5;
    int c = 8;

    int* p = &a;
    int& r = a;
    int copy = *p; // copy = 2

    *p = b; // *p = 5
    p = &c; // c зависит от p, *p = 8
    r = *p; // r = 8 = a
    *p = b + copy; // *p = 5 + 2 = 7, c = 7
    p = &b; // b зависит от p, *p = 5
    *p = r - copy; // *p = 8 - 2 = 6, b = 6
    r++; // r = 9 = a
    
    cout << a << " " << b << " " << copy;
  

    return 0;
}







