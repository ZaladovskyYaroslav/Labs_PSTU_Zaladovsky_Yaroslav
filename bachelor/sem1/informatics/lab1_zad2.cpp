#include <iostream>
#include <windows.h>   // Для работы с кириллицей
using namespace std;
int main() {
    setlocale(LC_ALL, ".UTF8");
    // Задание 2
    int n = 20;
    int m = 5;
    int res1, res2, res3;
    res1 = n---m;    
    res2 = m--<n;    
    res3 =  n++>m;   

    cout << "Значение первого выражения: " << res1 << '\n' << 
    "Значение второго выражения: " << res2 << '\n' << 
    "Значение 3 выражения: " << res3;

    return 0;
}

