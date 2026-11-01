#include <iostream>
#include <clocale>
using namespace std;

int main() {
    int a[] = {79, 4567, 223, 64, 8, 3888};

    for (int i = 1; i < size(a); i++) {
        int el = a[i];
        int j = i - 1; 

        while (j >= 0 && a[j] > el) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = el;
    }

    for (int i = 0; i < size(a); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
