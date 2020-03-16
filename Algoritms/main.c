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
#define SIZE 100

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
/* 1. Реализовать сортировку подсчетом. */

void solution1() {
    
}



//MARK: - 2
/* 2. Реализовать быструю сортировку. */
int counter;

void solution2() {
    counter = 0;
    
    int arr[SIZE];
    fillArray(arr);
    printf("\nUnsorted array:\n");
    printArray(arr);
    
    qs(arr, 0, SIZE - 1);
    //quickSort(arr, 0, SIZE - 1);
    printf("\nSorted array:\n");
    printArray(arr);
    printf("\nSwap count - %d", counter);
}

void qs(int* arr, int first, int last) {
    int leftBorder = first;
    int rightBorder = last;
    //элемент в центре массива, который берем для сравнения
    int pivot = arr[(first + last) / 2];
    
    do {
        //пока границы меньше pivot перевещаем границы
        while (arr[leftBorder] < pivot) {
            leftBorder++;
        }
        while (arr[rightBorder] > pivot) {
            rightBorder--;
        }
        //меняем местами значения и снова сдвигаем границы
        if(leftBorder <= rightBorder) {
            if (arr[leftBorder] > arr[rightBorder]) {
                int temp = arr[leftBorder];
                arr[leftBorder] = arr[rightBorder];
                arr[rightBorder] = temp;
                counter++;
            }
            leftBorder++;
            rightBorder--;
        }
    } while (leftBorder <= rightBorder);
    //когда границы сомкнулись, вызываем функцию рекурсивно для левой и правой стороны массива
    if (leftBorder < last)
        qs(arr, leftBorder, last);
    if (first < rightBorder)
        qs(arr, first, rightBorder);
}



void quickSort(int *arr, int left, int right) {
    int leftBorder = left;
    int rightBorder = right;
    int pivot = arr[left];
    
    while (left < right) {
        while (arr[right] >= pivot && left != right) {
            right--;
        }
        if (left != right) {
            arr[left] = arr[right];
            left++;
        }
        
        while (arr[left] <= pivot && left != right) {
            left++;
        }
        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = leftBorder;
    right = rightBorder;
    if (left < pivot)
        quickSort(arr, left, pivot - 1);
    if (right > pivot)
        quickSort(arr, pivot + 1, right);
}

//заполняем массив рандомными числами от -100 до 100
void fillArray(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 201 - 100;
    }
}

//печатаем массив
void printArray(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
}


//MARK: - 3
/* 3. *Реализовать сортировку слиянием. */

void solution3() {
    
}


//MARK: - supporting function
void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("0 - exit\n");
}
