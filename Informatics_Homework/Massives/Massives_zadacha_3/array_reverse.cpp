#include <iostream>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_ALL, ".UTF8");

    int a[] = {45, 2, 431, 56, 42, 785};

    int i = size(a) - 1;

    for(i; i >= 0; i--){
        cout << a[i] << " ";
    }
    
    return 0;
}