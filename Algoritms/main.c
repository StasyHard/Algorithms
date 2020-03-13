//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include "main.h"
#define MaxN 6
#define infinity 99

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

//MARK: - 1
/* 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран. */
const char* fileName = "/Users/anastasiareyngardt/Documents/Learning/GeekBrains/matrix.txt";
int matrix[MaxN][MaxN];
int count = 6;

void solution1() {
    readFile();
    printf("Graph matrix:\n");
    printMatrix(matrix);
}

void readFile() {
    int i, j;
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Can't open file");
        exit(1);
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
}

void printMatrix(int matrix[MaxN][MaxN]) {
    printf("%s", "      ");
    for (int i = 0; i < count; i++)
        printf("%c(%d) ", 65 + i, i);
    printf("\n");
    for (int i = 0; i < count; i++)
    {
        printf("%c(%d)", 65 + i, i);
        for (int j = 0; j < count; j++)
            printf("%5d", (matrix[i][j] == infinity) ? 0 : matrix[i][j]);
        printf("\n");
    }
}


//MARK: - 2
/* 2. Написать рекурсивную функцию обхода графа в глубину. */

// матрица смежности
int matrix2[MaxN][MaxN] = {
    { 0, 1, 1, 0, 0, 0},
    { 1, 0, 1, 1, 0, 0},
    { 1, 1, 0, 0, 0, 0},
    { 0, 1, 0, 0, 1, 0},
    { 0, 0, 0, 1, 0, 1},
    { 0, 0, 0, 0, 1, 0} };
int visited[MaxN];

void solution2() {
    printMatrix(matrix2);
    visitedIsFalse();
    int start = 3; // стартовая вершина
    graphTraversalInDepth(start);
}

// исходно все вершины равны 0
void visitedIsFalse() {
    for (int i = 0; i < 7; i++) {
           visited[i] = 0;
       }
}

void graphTraversalInDepth(int start) {
    visited[start] = 1;
    printf("%c(%d) ", 65 + start, start);
    for (int i = 0; i < MaxN; i++)
        if ((matrix2[start][i] != 0) && (visited[i] == 0))
            graphTraversalInDepth(i);
}

//MARK: - 3
/* 3. Написать функцию обхода графа в ширину. */

int queue[MaxN];

void solution3() {
    printMatrix(matrix2);
    visitedIsFalse();
    int start = 3; // стартовая вершина
    graphWidthTraversal(start);
}

void graphWidthTraversal(int start) {
    queue[0] = start;
    visited[start] = 1;
    int r = 0, w = 1;
    
    while (r < w) {
        int curr = queue[r++];
        printf("%c(%d) ", 65 + curr, curr);
        for (int i = 0; i < MaxN; i++) {
            if (!visited[i] && matrix2[curr][i]) {
                visited[i] = 1;
                queue[w++] = i;
            }
        }
    }
}

//MARK: - supporting function
void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("0 - exit\n");
}
