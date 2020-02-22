//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 22.02.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void swap1(int *a, int *b);
void swap2(int *a, int *b);

int main(int argc, const char * argv[]) {

    //3
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

    return 0;
}




/* 3. Написать программу обмена значениями двух целочисленных переменных:
a. с использованием третьей переменной;
b. *без использования третьей переменной. */

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
