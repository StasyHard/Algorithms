//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 22.02.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void solution1(void);
double calculate_index(double m, double h);
void solution2(void);
int compare_numbers(int a, int b, int c, int d);
void solution3(void);
void swap1(int *a, int *b);
void swap2(int *a, int *b);


int main(int argc, const char * argv[]) {
    
    //Task - 1
    printf("Task - 1 \n");
    solution1();
    
    //Task - 2
     printf("Task - 2 \n");
    solution2();
    
    //Task - 3
    printf("Task - 3 \n");
    solution3();
    
    return 0;
}


//MARK: - Task - 1
/* 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах. */
void solution1() {
    double weight;
    double height;
    
    printf("Input weight in kg: ");
    scanf("%lf", &weight);
    printf("Input height in meters: ");
    scanf("%lf", &height);
    double i = calculate_index(weight, height);
    printf("Index = %.2lf \n\n", i);
}

double calculate_index(double m, double h) {
    return m / (pow(h, 2));
}

//MARK: - Task - 2
/* 2. Найти максимальное из четырех чисел. Массивы не использовать. */
void solution2() {
    double a, b, c, d;
    printf("Input first number: ");
    scanf("%lf", &a);
    printf("Input second number: ");
    scanf("%lf", &b);
    printf("Input third number: ");
    scanf("%lf", &c);
    printf("Input fourth number: ");
    scanf("%lf", &d);
    int max = compare_numbers(a, b, c, d);
    printf("Max number - %d \n\n", max);
}

int compare_numbers(int a, int b, int c, int d) {
    if (a > b && a > c && a > d) {
        return a;
    } else if (b > a && b > c && b > d) {
        return b;
    } else if (c > a && c > b && c > d) {
        return c;
    } else {
        return d;
    }
}

//MARK: - Task - 3
/* 3. Написать программу обмена значениями двух целочисленных переменных:
 a. с использованием третьей переменной;
 b. *без использования третьей переменной. */
void solution3() {
    int a, b;
    
    printf("Input first number: ");
    scanf("%d", &a);
    printf("Input second number: ");
    scanf("%d", &b);
    
    printf("A = %d, B = %d \n", a, b);
    swap1(&a, &b);
    printf("A = %d, B = %d \n", a, b);
    swap2(&a, &b);
    printf("A = %d, B = %d \n", a, b);
}

void swap1(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

void swap2(int *a, int *b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}
