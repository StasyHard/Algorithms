//
//  main.h
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//

#ifndef main_h
#define main_h
#define L 14

#include <stdio.h>

void solution1(void);
void countingSort(int *arr, int size);

void solution2(void);
void qs(int* arr, int first, int last);
void quickSort(int *arr, int left, int right);
void swap(int *arr, int left, int right);
void fillArray(int *arr);
void printArray(int *arr, int size);

void solution3(void);
void mergeSort(int *arr, int first, int last);
void merge(int *arr, int first, int split, int last);

void menu(void);

#endif /* main_h */
