#include <iostream>
#include <clocale>
#include <cstdarg>
#include <cmath>
#include <algorithm>
using namespace std;

// Вычисление длины стороны по её координатам
double line(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Вычисление площади треугольника по формуле Герона
double area(double x1, double y1, double x2, double y2, double x3, double y3){

    // Вычисление длин сторон треугольника
    double a = line(x1, y1, x2, y2);
    double b = line(x1, y1, x3, y3);
    double c = line(x2, y2, x3, y3);

    // Вычисление полупериметра
    double p = (a + b + c) / 2.0;

    return sqrt(max(0.0, p * (p - a) * (p - b) * (p - c)));
}

// Проверка принадлежности точки M с координатами (x, y) треугольнику с вершинами (x1, y1), (x2, y2), (x3, y3)
bool belong(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3){

    double s = area(x1, y1, x2, y2, x3, y3); // Площадь исходного треугольника
    double s1 = area(x, y, x1, y1, x2, y2);
    double s2 = area(x, y, x1, y1, x3, y3); // Площади трёх малых треугольников, образованный точкой M и сторонами треугольника
    double s3 = area(x, y, x2, y2, x3, y3);

    // Точка M принадлежит треугольнику, если сумма площадей малых треугольников равна площади исходного
    return (fabs((s1 + s2 + s3) - s) < 1e-6);
}

// Проверка принадлежности точки M выпуклому k-угольнику
bool mnogougolnik(double x, double y, int k, ...){
    // Многоугольник должен иметь минимум 3 стороны
    if(k < 3) return false;
        
    va_list a; // Указатель на очередной аргумент в списке
    va_start(a, k); // Инициализируем чтение аргументов после параметра k

    // Первая опорная вершина, от которой проводятся диагонали
    double x1 = va_arg(a, double);
    double y1 = va_arg(a, double);

    // Вторая опорная вершина для формирования первого треугольника
    double prevX = va_arg(a, double);
    double prevY = va_arg(a, double);

    bool isInside = false;

    int i = 2; // Счётчик
    
    // Разбитие многоугольника на треугольники
    while(i < k && !isInside){
        
        double curX = va_arg(a, double);
        double curY = va_arg(a, double);

        if(belong(x, y, x1, y1, prevX, prevY, curX, curY)){
            isInside = true;
        }

        prevX = curX;
        prevY = curY;

        i++;
    }

    va_end(a); // Освобождаем ресурсы, связанные со списком аргументов

    return isInside;
}

int main(){

    setlocale(LC_ALL, ".UTF8");

    // Проверяемая точка M
    double M[] = {2.0, 3.0};

    // Проверка попадания точки M в треугольник
    if(mnogougolnik(M[0], M[1], 3,  0.0, 0.0, 6.0, 9.0, 6.0, 0.0)){
        cout << "Точка M [" << M[0] << ", " << M[1] << "] принадлежит треугольнику";
    } else{
        cout << "Точка M [" << M[0] << ", " << M[1] << "] не принадлежит треугольнику";
    }

    cout << endl;

    // Проверка попадания точки M в выпуклый пятиугольник
    if(mnogougolnik(M[0], M[1], 5,  0.0, 0.0, 1.0, 2.0, 3.0, 3.0, 4.0, 1.0, 3.0, 1.0)){
        cout << "Точка M [" << M[0] << ", " << M[1] << "] принадлежит пятиугольнику";
    } else{
        cout << "Точка M [" << M[0] << ", " << M[1] << "] не принадлежит пятиугольнику";
    }

    return 0;
}