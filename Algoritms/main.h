//
//  main.h
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>

struct stack;
void init(struct stack *stk);
void push(struct stack *stk, int number);
int pop(struct stack *stk);

void solution1(void);
void convert_number(struct stack *stk, int number);

void solution2(void);
void push1(char value);
char pop1(void);
void printStack(void);

void solution3(void);

void solution6(void);
struct queue;
void initQueue(struct queue *q);
void insert(struct queue *q, int x);
void printQueue(struct queue *q);
int removeQueue(struct queue *q);

void menu(void);

#endif /* main_h */
