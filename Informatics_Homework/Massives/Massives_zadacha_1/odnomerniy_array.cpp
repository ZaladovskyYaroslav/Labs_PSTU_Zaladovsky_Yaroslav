#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    int a[] = {3, 12, 45637, 45637, 12, 45637, 6};
    int max = a[0];
    int min = a[0];
    int num_max, num_min, ind_max, ind_min, count_max, count_min;
    ind_max = ind_min = 0;
    num_max = num_min = count_max = count_min = 1;

    for(int i = 1; i < size(a); i++){
        if(a[i] > max){
            max = a[i];
            ind_max = i;
            num_max = ind_max + 1;
            count_max = 1; // Обнуляем счётчик при нахождении нового максимума
        }
        else if(a[i] == max){
            count_max++;
        }

       if(a[i] < min){
            min = a[i];
            ind_min = i;
            num_min = ind_min + 1;
            count_min = 1; // Обнуляем счётчик при нахождении нового минимума
        }
        else if(a[i] == min){
            count_min++;
        }
    }

    cout << "Max: " << max << " | Index: " << ind_max << " | Number: " << num_max << " | Count: " << count_max << '\n';
    cout << "Min: " << min << " | Index: " << ind_min << " | Number: " << num_min << " | Count: " << count_min;

    return 0;
}




