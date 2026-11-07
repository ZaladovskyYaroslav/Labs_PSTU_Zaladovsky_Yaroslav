#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    setlocale(LC_ALL, ".UTF8");

    string line;

    cout << "Введите предложение на английском языке: " << '\n';

    getline(cin, line);

    vector<string> words; // Массив для всех слов из введённой строки
    stringstream ss(line); // Для работы со строкой как с потоком данных (аналог cin и cout)
    string word;

    // Добавляем слова, разделённые '_', в массив до тех пор, пока они есть в строке
    while(getline(ss, word, '_')){
        if(!word.empty()){
            words.push_back(word);
        }
    }

    vector<string> translated_words; // Массив c переведёнными словами

    string el;

    // Проверяем, есть ли у слова эквивалент на русском языке
    for(int i = 0; i < size(words); i++){
        el = words[i];
        // База данных слов
        if(el == "MONDAY"){
            el = "ПОНЕДЕЛЬНИК";
        }
        else if(el == "A" || el == "THE" || el == "IS" || el == "ARE" || el == "AN" || el == "AM"){
            el = ""; // Убираем артикли и формы глагола to be
        }
        else if(el == "THIS"){
            el = "ЭТО";
        }
        else if(el == "DAY"){
            el = "ДЕНЬ";
        }
        else if(el == "I"){
            el = "Я";
        }
        else if(el == "TABLE"){
            el = "СТОЛ";
        }
        else if(el == "TIRED"){
            el = "УСТАВШИЙ";
        }

        // Добавляем слово в список только, если оно не артикль и не форма глагола to be (не пустое)
        if(!el.empty()){
            translated_words.push_back(el);
        }
    }

    cout << "Перевод:" << '\n';
    if(!translated_words.empty()){
        cout << translated_words[0]; // Выводим первое слово
        // Выводим оставшиеся слова, начиная со второго
        for(int i = 1; i < size(translated_words); i++){
            cout << "_" << translated_words[i];
        }
    }

    return 0;
}
