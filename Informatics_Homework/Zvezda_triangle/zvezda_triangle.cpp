#include <iostream>
#include <clocale>
using namespace std;

int main() {

    setlocale(LC_ALL, ".UTF8");

    int n;
    cout << "Введите n: ";
    cin >> n;

    int p = n - 1;
    int z = 1;

    for(int i = 0; i < n; i++) {
        
        for(int j = 0; j < p; j++) {
            cout << " ";
        }
        for(int k = 0; k < z; k++) {
            cout << "*";
        }
        cout << endl;
        p -= 1;
        z += 1;
    }

    return 0;
}

