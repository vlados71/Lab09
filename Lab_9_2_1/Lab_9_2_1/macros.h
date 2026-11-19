#pragma once
// macros.h - власний заголовний файл з макросами
#pragma once
#include <stdio.h>

#define SQR(a)    ((a) * (a))                       // піднесення до квадрата
#define ABS(a)    ((a) >= 0 ? (a) : -(a))           // модуль
#define MAX(a, b) ((a) > (b) ? (a) : (b))           // максимум
#define MIN(a, b) ((a) < (b) ? (a) : (b))           // мінімум
#define PRINTR(w) printf(#w " = %f\n", (double)(w)) // виведення результату