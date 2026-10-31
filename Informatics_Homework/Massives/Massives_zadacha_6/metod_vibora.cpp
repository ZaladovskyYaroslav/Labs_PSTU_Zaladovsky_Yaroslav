#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a[] = {79, 4567, 223, 64, 8, 3888};

    for(int i = 0; i < size(a) - 1; i++){
        int min = i;
        for(int j = i + 1; j < size(a); j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }

    for(int i = 0; i < size(a); i++){
        cout << a[i] << " ";
    }

    return 0;
}