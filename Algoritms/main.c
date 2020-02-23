//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 22.02.2020.


#include <stdio.h>
#include <math.h>
#include <string.h>
#include "header.h"


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
    
    //Task - 5
    printf("Task - 5 \n");
    solution5();
    
    //Task - 6
    printf("Task - 6 \n");
    solution6();
    
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
    int max1 = max_number1(a, b, c, d);
    int max2 = max_number2(a, b, c, d);
    printf("Max1 number - %d, max2 number - %d \n\n", max1, max2);
}

int max_number1(int a, int b, int c, int d) {
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

int max_number2(int a, int b, int c, int d) {
    int max1 = a > b ? a : b;
    int max2 = c > d ? c : d;
    
    return max1 > max2 ? max1 : max2;
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
    printf("A = %d, B = %d \n\n", a, b);
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

//MARK: - Task - 5
/* 5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится. */
void solution5() {
    int month;
    printf("Inpu the month number: ");
    scanf("%d", &month);
    
    if (month > 1 && month > 12) {
        printf("There is no such month");
    } else {
        define_time_of_year(month);
    }
}

void define_time_of_year(int month) {
    int result = month / 3;
    switch (result) {
        case 1:
            printf("It is spring");
            break;
        case 2:
            printf("This summer");
            break;
        case 3:
            printf("It is fall");
            break;
        case 0:
        case 4:
            printf("This is winter");
            break;
    }
    printf("\n\n");
}

//MARK: - Task - 6
/*6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет». */
void solution6() {
    int age;
    printf("Input human age (from 1 to 150 years): ");
    scanf("%d", &age);
    char* result = define_ending(age);
    printf("%d %s \n\n", age, result);
    
}

char* define_ending(int age) {
    int result = age % 10;
    int result2 = age % 100;
    if (result == 1 && result2 != 11) {
        return "год";
    } else if (result >= 2 && result <= 4 && result2 != 12 && result2 != 13 && result2 != 14) {
        return "года";
    } else {
        return "лет";
    }
}
