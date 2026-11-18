//////////////////////////////////////////////////////////////////////////////
// Lab_9_1.cpp
// Лабораторна робота № 9.1. Простори імен. Варіант 5.
// ln((1+x)/(1-x)) = 2 * sum( x^(2n+1) / (2n+1) ),  |x| < 1
// головний файл проекту - функція main

#include <iostream>
#include <iomanip>
#include <math.h>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    // ряд збігається лише при |x| < 1; крок і точність мають бути додатними,
    // інакше цикл або не завершиться, або функція не визначена
    if (!cin || x_p <= -1 || x_k >= 1 || x_p > x_k || dx <= 0 || e <= 0)
    {
        cout << "Error: need -1 < x_p <= x_k < 1, dx > 0, e > 0" << endl;
        return 1;
    }

    // заголовок і шапка таблиці
    cout << "Taylor series for ln((1+x)/(1-x))" << endl;
    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
    cout << setw(10) << "x"
        << setw(16) << "ln((1+x)/(1-x))"
        << setw(16) << "series sum"
        << setw(8) << "terms" << endl;
    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;

    x = x_p;
    while (x <= x_k + 1e-9)             // мала похибка, щоб не втратити останній рядок
    {
        sum();                          // виклик процедури обчислення суми

        cout << fixed
            << setprecision(4) << setw(10) << x
            << setprecision(8) << setw(16) << log((1 + x) / (1 - x))
            << setprecision(8) << setw(16) << s
            << setw(8) << n + 1 << endl;   // n + 1 - кількість доданків

        x += dx;
    }

    return 0;
}