#include <iostream>
#include <windows.h>
#include <cstdio>
using namespace std;


// Описание структуры "Стадион"
struct Stadion {
    char name[30];
    int year_of_building;
    int count_of_platforms;
    char types_of_sports[50];
};


// Функция ввода данных с клавиатуры и создания одной структуры Stadion
Stadion init_stadion() {
    Stadion e{}; // Обнуляем все байты структуры, чтобы в файл не попал случайный мусор из памяти

    cout << "Введите название стадиона: ";
    cin >> ws; // Очищаем буфер ввода от оставшегося символа перевода строки '\n'
    cin.getline(e.name, sizeof(e.name));

    cout << "Введите год постройки стадиона: ";
    cin >> e.year_of_building;

    cout << "Введите количество площадок на стадионе: ";
    cin >> e.count_of_platforms;

    cout << "Введите виды спорта, которыми можно заниматься на стадионе: ";
    cin >> ws;
    cin.getline(e.types_of_sports, sizeof(e.types_of_sports));

    return e;
}


// Функция вывода информации об одном стадионе на экран
void print_stadion(const Stadion& s) {
    cout << s.name << " | " << s.year_of_building << " г. | Площадок: " << s.count_of_platforms << " | Виды спорта: " << s.types_of_sports << endl;
}


// Функция первоначального формирования бинарного файла (запись n структур)
void create_file(const char* filename, int n) {
    FILE* f = fopen(filename, "wb"); // Открываем файл для бинарной записи (перезаписывает файл)
    if (!f) {
        cout << "Ошибка при открытии файла для записи!" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << "\nСтадион номер " << i << endl;
        Stadion s = init_stadion();
        fwrite(&s, sizeof(Stadion), 1, f); // Записываем структуру в файл
    }

    fclose(f);
}


// Функция чтения и вывода всех структур из бинарного файла
int print_file(const char* filename) {
    FILE* f = fopen(filename, "rb"); // Открываем файл для бинарного чтения
    if (!f) {
        cout << "Ошибка при открытии файла для чтения!" << endl;
        return 0;
    }

    Stadion temp;
    int count = 0;

    // Считываем по одной структуре из файла, пока не дойдём до конца
    while (fread(&temp, sizeof(Stadion), 1, f) == 1) {
        count++;
        cout << count << ". ";
        print_stadion(temp);
    }

    if (count == 0) {
        cout << "Файл пуст." << endl;
    }

    fclose(f);
    return count;
}


// Функция удаления стадионов, построенных раньше min_year, с помощью вспомогательного файла
void delete_older_than(const char* filename, int min_year) {
    const char* temp_filename = "temp.bin"; // Имя временного файла

    FILE* f_in = fopen(filename, "rb");
    if (!f_in) {
        cout << "Ошибка при открытии исходного файла!" << endl;
        return;
    }

    FILE* f_out = fopen(temp_filename, "wb");
    if (!f_out) {
        cout << "Ошибка при создании вспомогательного файла!" << endl;
        fclose(f_in);
        return;
    }

    Stadion temp;
    // Переписываем во вспомогательный файл только подходящие по году стадионы
    while (fread(&temp, sizeof(Stadion), 1, f_in) == 1) {
        if (temp.year_of_building >= min_year) {
            fwrite(&temp, sizeof(Stadion), 1, f_out);
        }
    }

    fclose(f_in);
    fclose(f_out);

    // Удаляем старый файл и переименовываем вспомогательный на его место
    remove(filename);
    rename(temp_filename, filename);
}


// Функция вставки 2 новых стадионов перед элементом с номером target_pos
void insert_two_before(const char* filename, int target_pos) {
    const char* temp_filename = "temp.bin";

    FILE* f_in = fopen(filename, "rb");
    if (!f_in) {
        cout << "Ошибка при открытии исходного файла!" << endl;
        return;
    }

    FILE* f_out = fopen(temp_filename, "wb");
    if (!f_out) {
        cout << "Ошибка при создании вспомогательного файла!" << endl;
        fclose(f_in);
        return;
    }

    Stadion temp;
    int current_pos = 0;
    bool inserted = false;

    while (fread(&temp, sizeof(Stadion), 1, f_in) == 1) {
        current_pos++;

        // Перед указанным номером сначала записываем 2 новых стадиона
        if (current_pos == target_pos) {
            for (int i = 1; i <= 2; i++) {
                cout << "\nВведите данные для нового стадиона #" << i << endl;
                Stadion new_s = init_stadion();
                fwrite(&new_s, sizeof(Stadion), 1, f_out);
            }
            inserted = true;
        }

        // Записываем текущий элемент из исходного файла
        fwrite(&temp, sizeof(Stadion), 1, f_out);
    }

    // Если исходный файл после удаления оказался пустым, записываем 2 новых стадиона в начало
    if (!inserted && current_pos == 0) {
        for (int i = 1; i <= 2; i++) {
            cout << "\nВведите данные для нового стадиона #" << i << endl;
            Stadion new_s = init_stadion();
            fwrite(&new_s, sizeof(Stadion), 1, f_out);
        }
    }

    fclose(f_in);
    fclose(f_out);

    // Заменяем исходный файл обновлённым
    remove(filename);
    rename(temp_filename, filename);
}


int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const char* filename = "stadions.txt";

    // Ввод начального количества записей
    int n;
    cout << "Введите количество стадионов: ";
    cin >> n;

    while (n < 5) {
        cout << "Количество стадионов должно быть не менее 5. Попробуйте ещё раз: ";
        cin >> n;
    }

    // Создание и вывод исходного файла
    create_file(filename, n);
    cout << "\nСодержимое сформированного файла:\n";
    print_file(filename);

    // Удаление стадионов, построенных раньше заданного года
    int y;
    cout << "\nВведите необходимый год (стадионы, построенные раньше этого года, будут удалены): ";
    cin >> y;

    delete_older_than(filename, y);
    cout << "\nСписок после удаления старых стадионов:\n";
    int remaining = print_file(filename);

    // Вставка 2 новых элементов перед выбранным стадионом
    int pos = 1;
    if (remaining > 0) {
        cout << "\nВведите номер стадиона (от 1 до " << remaining << "), перед которым будут добавлены ещё 2 стадиона: ";
        cin >> pos;

        while (pos < 1 || pos > remaining) {
            cout << "Некорректный номер! Введите число от 1 до " << remaining << ": ";
            cin >> pos;
        }
    } else {
        cout << "\nВсе стадионы были удалены. Новые 2 стадиона будут добавлены в файл.\n";
    }

    insert_two_before(filename, pos);

    // Вывод итогового содержимого файла
    cout << "\nИтоговое содержимое файла:\n";
    print_file(filename);

    return 0;
}