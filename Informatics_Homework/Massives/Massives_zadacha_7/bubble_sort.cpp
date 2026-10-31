#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a[] = {45, 23, 567, 12, 895, 245, 56};

    for(int i = 0; i < size(a) - 1; i++){
        for(int j = 0; j < size(a) - 1 - i; j++){
            if(a[j + 1] < a[j]){
                swap(a[j], a[j+1]);
            }
        }
    }

    for(int i = 0; i < size(a); i++){
        cout << a[i] << " ";
    }

    return 0;
}