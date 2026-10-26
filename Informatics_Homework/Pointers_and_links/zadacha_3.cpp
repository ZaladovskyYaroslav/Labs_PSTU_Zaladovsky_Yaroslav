#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a = 4;
    int b = 9;
    int* p = &a;
    int* q = p;
    int& r = *p;
    p = &b; // *p = 9
    *q += *p; // *q = 4 + 9 = 13 = a = r
    *p = r - 3; // *p = 13 - 3 = 10
    q = p; // *p = 10 = *q
    *q += r; // *q = 10 + 13 = 23
    
    cout << a << " " << b << " " << r;
    // 13 23 13

    return 0;
}







