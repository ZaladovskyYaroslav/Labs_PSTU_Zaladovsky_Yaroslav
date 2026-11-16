#include <iostream>
#include <vector>
#include <string>
#include <clocale>
using namespace std;

// Массив из 3 векторов для хранения колец на каждом стержне
vector<int> rods[3];
int total_rings = 0;
int step_count = 0;

// Рисование текущего состояния всех стержней
void printTowers() {
    cout << "Ход " << step_count++ << "\n\n";
    
    // Максимальная ширина самого большого кольца
    int max_width = total_rings * 2 - 1;
    
    // Идём сверху вниз по уровням высоты
    for (int level = total_rings - 1; level >= 0; --level) {
        for (int r = 0; r < 3; ++r) {
            // Если на текущем стержне есть кольцо на этой высоте
            if (level < rods[r].size()) {
                int ring_size = rods[r][level];
                int stars = ring_size * 2 - 1;
                int spaces = (max_width - stars) / 2;
                
                cout << string(spaces, ' ') << string(stars, '*') << string(spaces, ' ');
            } else {
                // Если на этой высоте нет колец, печатаем пробелы
                cout << string(max_width, ' ');
            }
            // Отступ между стержнями
            cout << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Перемещения колец по стержням
void han(int n, int start, int end, int temp) {
    if (n <= 0) return;
    
    han(n - 1, start, temp, end);
    
    // Перекладываем верхнее кольцо со стержня start на стержень end
    int ring = rods[start - 1].back();
    rods[start - 1].pop_back();
    rods[end - 1].push_back(ring);
    
    // Обновление рисунка
    printTowers();
    
    han(n - 1, temp, end, start);
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    
    cout << "Введите количество колец: ";
    cin >> total_rings;
    
    if (total_rings <= 0) return 0;
    
    // Заполнение первого стержня кольцами от большего к меньшему
    for (int i = total_rings; i >= 1; --i) {
        rods[0].push_back(i);
    }
    
    // Вывод начального состояния (нулевой шаг)
    printTowers();
    
    han(total_rings, 1, 3, 2);
    
    return 0;
}