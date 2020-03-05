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
void push1(struct stack *stack, char value);

void solution3(void);

void menu(void);

#endif /* main_h */
