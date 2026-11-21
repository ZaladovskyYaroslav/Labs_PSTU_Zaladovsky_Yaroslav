#include <iostream>
#include <clocale>
using namespace std;

struct Advertising{
    int ad_shows;
    double clicks;
    double click_cost;
};

int main(){
    setlocale(LC_ALL, ".UTF8");

    Advertising Shampoo;

    printf("Введите количество показанных объявлений: ");
    cin >> Shampoo.ad_shows;
    printf("Введите процент пользователей, нажавших на объявление: ");
    cin >> Shampoo.clicks;
    printf("Введите среднюю сумму, полученную за каждое нажатие на объявление: ");
    cin >> Shampoo.click_cost;

    printf("Полученный доход: %.2f рублей", Shampoo.ad_shows * Shampoo.clicks * Shampoo.click_cost / 100.0);

    return 0;
}