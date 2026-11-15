#include <iostream>
#include <clocale>
using namespace std;

// Рекурсивная функция для перемещения колец по стержням
void han(int n, int start, int end, int temp){
    if (n <= 0) return; // Если колец не осталось, выходим из функции
    han(n - 1, start, temp, end);
    cout << start << " --> " << end << endl;
    han(n - 1, temp, end, start);
}

int main(){
    setlocale(LC_ALL, ".UTF-8");
    int n;
    cout << "Введите количество колец: ";
    cin >> n;
    han(n, 1, 3, 2); // Перемещение колец с первого стержня на третий. Второй стержень - "буфер"
    return 0;
}