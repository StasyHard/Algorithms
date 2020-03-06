//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            case 6:
                solution6();
                printf("\n\n");
                break;
            default:
                //printf("Wrong selected\n");
                break;
        }
    } while (sel != 0);
    return 0;
}

//MARK: - 2
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
    printf("In binary system - ");
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

//MARK: - 2
/* 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение. Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных). */
struct TNode {
    char value;
    struct TNode *next;
};

typedef struct TNode Node;

struct Stack {
    
    Node *head;
    int size;
    int maxSize;
};

struct Stack Stack;

void push1(char value) {
    if (Stack.size >= Stack.maxSize) {
        printf("Stack owerflow");
    }
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}

char pop1() {
    if (Stack.size == 0) {
        printf("Stack is empty \n");
    }
    Node *next = NULL;
    char value;
    value = Stack.head->value;
    next = Stack.head;
    Stack.head = Stack.head->next;
    free(next);
    Stack.size--;
    return value;
}

void printStack() {
    Node *current = Stack.head;
    while (current != NULL) {
        printf("%c", current->value);
        current = current->next;
    }
}

void solution2() {
    Stack.maxSize = 100;
    Stack.head = NULL;
    push1('a');
    push1('b');
    push1('c');
    push1('d');
    push1('e');
    printStack();
}

//MARK: - 3
/* 3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{. */
struct stackChar {
    char elem[MaxN];
    int top;
};

void initStackChar(struct stackChar *stk) {
    stk->top = 0;
}

void pushInStackChar(struct stackChar *stk, char character) {
    if (stk->top < MaxN) {
        stk->elem[stk->top] = character;
        stk->top++;
    } else {
        printf("Stack owerflow");
    }
}

char popFromStackChar(struct stackChar *stk) {
    if (stk->top > 0 ) {
        stk->top--;
        return stk->elem[stk->top];
    } else {
        printf("Stack is empty\n");
        return '0';
    }
}

char stackCharTop(struct stackChar *stk) {
  if((stk->top) > 0) {
    return stk->elem[stk->top-1];
  } else {
    printf("Stack is empty \n");
    return '0';
  }
}

int stackCharIsEmpty(struct stackChar *stk) {
    if(stk->top == 0) {
        return 1;
    } else return 0;
}

void solution3() {
    
    struct stackChar *stk;
    stk = (struct stackChar*)malloc(sizeof(struct stackChar));
    initStackChar(stk);
    
    
    char str[MaxN] = "(), ([])(), {}(), ([{}])";
    long strLen = strlen(str);
    for (int i = 0; i < strLen; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            pushInStackChar(stk, str[i]);
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            char elem = str[i];
            char stackTop = stackCharTop(stk);
            if (((stackTop == '(' && elem == ')') || (stackTop == '{' && elem == '}') || (stackTop == '[' && elem == ']')) && stackCharIsEmpty(stk) != 1) {
                popFromStackChar(stk);
            } else {
                printf("%s - sequence is wrong\n", str);
                return;
            }
        }
    }
    if (stackCharIsEmpty(stk) == 0) {
        printf("%s - sequence is wrong\n", str);
    } else {
        printf("%s - sequence is correct", str);
    }
}

//MARK: - 6
/* 6. *Реализовать очередь. */

struct queue {
    int qu[MaxN];
    int rear, frnt;
};

void initQueue(struct queue *q) {
    q->frnt = 1;
    q->rear = 0;
    return;
}

void insert(struct queue *q, int x) {
    if(q->rear < MaxN) {
        q->rear++;
        q->qu[q->rear]=x;
    }
    else
        printf("The queue is full!\n");
    return;
}

void printQueue(struct queue *q) {
    int h;
    if(q->rear < q->frnt) {
        printf("Queue is empty!\n");
        return;
    }
    for(h = q->frnt; h<= q->rear; h++)
        printf("%d ",q->qu[h]);
    return;
}

int removeQueue(struct queue *q) {
    int x, h;
    if(q->rear < q->frnt) {
        printf("Queue is empty!\n");
        return 0;
    }
    x = q->qu[q->frnt];
    for(h = q->frnt; h < q->rear; h++) {
        q->qu[h] = q->qu[h+1];
    }
    q->rear--;
    return x;
}

void solution6() {
    struct queue *q;
    q = (struct queue*)malloc(sizeof(struct queue));
    initQueue(q);
    
    int a;
    //вводим 8 чисел
    for(int i = 0; i < 8; i++) {
        printf("Enter queue item: ");
        scanf("%d", &a);
        //добавляем каждое в очередь
        insert(q, a);
    }
    //печатаем очередь
    printf("\n");
    printQueue(q);
    
    //удаляем по порядку элементы из очереди и каждый раз печатаем ее
    while(q->frnt <= q->rear) {
        a = removeQueue(q);
        printf("\nItem removed %d\n", a);
        printQueue(q);
    }
}


//MARK: - supporting function
void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("6 - task6\n");
    printf("0 - exit\n");
}
