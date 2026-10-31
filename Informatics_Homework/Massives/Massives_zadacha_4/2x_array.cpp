#include <iostream>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_ALL, ".UTF8");

    int a[3][3] = {{3, 26, 54}, {56, 12, 289}, {234, 12, 809}};

    int rows = size(a);
    int columns = size(a[0]);

    int max = a[0][0];
    int min = a[0][0];
    int max_i, max_j, min_i, min_j;
    max_i = 0; max_j = 0; min_i = 0; min_j = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(a[i][j] > max){
                max = a[i][j];
                max_i = i;
                max_j = j;
            }

            if(a[i][j] < min){
                min = a[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }

    cout << "Max: " << max << " | Index: [" << max_i << "][" << max_j << "]" << '\n';
    cout << "Min: " << min << " | Index: [" << min_i << "][" << min_j << "]";

    return 0;
}