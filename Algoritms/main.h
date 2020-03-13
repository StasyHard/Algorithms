//
//  main.h
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//

#ifndef main_h
#define main_h
#define MaxN 6

#include <stdio.h>

void solution1(void);
void readFile(void);
void printMatrix(int matrix[MaxN][MaxN]);

void solution2(void);
void visitedIsFalse(void);
void graphTraversalInDepth(int st);

void solution3(void);
void graphWidthTraversal(int start);

void menu(void);

#endif /* main_h */
