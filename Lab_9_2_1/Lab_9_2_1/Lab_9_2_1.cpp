// Lab_9_2_1.cpp. Лабораторна робота № 9.2, частина 1. Варіант 5.
//        max((x - y)^2, |y - x|),  z = 1
//   w =
//        min(x + y^2, z + x^2),    z != 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "macros.h"

#define Z 1             // значення z, за яким препроцесор обирає гілку

int main()
{
    double x, y, w;

    printf("x = "); scanf("%lf", &x);
    printf("y = "); scanf("%lf", &y);

#if Z == 1
    w = MAX(SQR(x - y), ABS(y - x));
#else
    w = MIN(x + SQR(y), Z + SQR(x));
#endif

    PRINTR(w);
    return 0;
}