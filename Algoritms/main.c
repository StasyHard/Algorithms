
#include <stdio.h>
#include <math.h>
#include "main.h"

//Рейнгардт Анастасия

int main(int argc, const char * argv[]) {
    int sel = 0;
    do {
        menu();
        scanf("%d", &sel);
        switch (sel) {
            case 1:
                solution1();
                printf("\n\n");
                break;
            case 2:
                solution2();
                printf("\n\n");
                break;
            default:
                //printf("Wrong selected\n");
                break;
        }
    } while (sel != 0);
    return 0;
}

/* 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию. */
void solution1() {
    int number;
    printf("Input decimal number: ");
    scanf("%d", &number);
    convert_number(number);
}

void convert_number(int number) {
    if (number >= 2) {
        convert_number(number / 2);
    }
    printf("%d", number % 2);
}

/* 2. Реализовать функцию возведения числа a в степень b:
 a. без рекурсии;
 b. рекурсивно;
 c. *рекурсивно, используя свойство четности степени. */
void solution2() {
    int number;
    int extent;
    printf("Input number: ");
    scanf("%d", &number);
    printf("Input  extent: ");
    scanf("%d", &extent);
    in_pow1(number, extent);
    
    double result = in_pow2(number, extent);
    printf("%lf", result);
}

void in_pow1(double number, double extent) {
    double result = 0.0;
    if(extent == 0) {
        result = 1;
    } else if (extent < 0) {
        double s;
        for (s = 1; extent < 0; ++extent) {
            s = s * number;
            result = 1 / s;
        }
    } else {
        for (result = 1; extent > 0; --extent) {
            result = result * number;
        }
    }
    printf("%lf\n", result);
}

double in_pow2(double number, double extent) {
    if(extent == 0) {
        return 1;
    }
    if(extent < 0) {
        return in_pow2 ( 1.0 / number, -extent);
    }
    return number * in_pow2(number, extent - 1);
}


void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("0 - exit\n");
}
