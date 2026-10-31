#include <iostream>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_ALL, ".UTF8");

    // Проверка упорядоченности массива
    int a[] = {489, 242, 283, 888, 345867};
    int i = 0;
    bool f = false;

    while(f == false && i < size(a) - 1){
        if(a[i + 1] < a[i]){
            f = true;
        }
        i++;
    }

    if(f == true){
        cout << "Массив не упорядочен по возрастанию" << '\n';
    } else{
        cout << "Массив упорядочен по возрастанию" << '\n';
    }

    return 0;
}