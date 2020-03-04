//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "main.h"
#define MaxN 100

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
            case 3:
                solution3();
                printf("\n\n");
                break;
            default:
                //printf("Wrong selected\n");
                break;
        }
    } while (sel != 0);
    return 0;
}

/* 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека. */

struct stack {
    int elem[MaxN];
    int top;
};

void init(struct stack *stk) {
  stk->top = 0;
}

void push(struct stack *stk, int number) {
    if (stk->top < MaxN) {
        stk->elem[stk->top] = number;
        stk->top++;
    } else {
        printf("Stack owerflow");
    }
}

int pop(struct stack *stk) {
    if (stk->top > 0 ) {
        stk->top--;
        return stk->elem[stk->top];
    } else {
        printf("Stack is empty \n");
        return -1;
    }
}

void solution1() {
    
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    
    int number;
    printf("Input decimal number: ");
    scanf("%d", &number);
    convert_number(stk, number);
    
    
}

void convert_number(struct stack *stk, int number) {
    if (number >= 2) {
        push(stk, number % 2);
        convert_number(stk, number / 2);
    } else {
        push(stk, number);
    }
    while (stk->top > 0) {
        printf("%d", pop(stk));
    }
}



void solution2() {
    
}

void solution3() {
    
}


void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("0 - exit\n");
}
