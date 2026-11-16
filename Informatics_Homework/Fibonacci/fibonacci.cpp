#include <iostream>
#include <clocale>
using namespace std;

void fib(int n, long long a, long long b){
    if(n <= 0) return;
    
    long long c = a + b;
    cout << c << " ";
    fib(n - 1, b, c);
} 

int main(){
    setlocale(LC_ALL, ".UTF8");

    long long a, b;
    int n;

    cout << "Введите количество чисел, которые будут выведены: ";
    cin >> n;

    while(n <= 0){
        cout << "n должно быть натуральным" << endl;
        cin >> n;
    }

    cout << "Введите первое число: ";
    cin >> a;

    if(n == 1){
        cout << a;
    } else{
        cout << "Введите второе число: ";
        cin >> b;
        cout << a << " " << b << " ";
        fib(n - 2, a, b);
    }
    
    return 0;
}