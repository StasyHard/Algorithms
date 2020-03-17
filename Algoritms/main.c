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
#define L 14
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
    
    int startArr[SIZE];
    fillArray(startArr);
    printf("\nUnsorted array:\n");
    printArray(startArr, SIZE);
    
    countingSort(startArr, SIZE);
    printf("\nSorted array:\n");
    printArray(startArr, SIZE);
}

void countingSort(int *arr, int size) {
    int tempArr[SIZE];
    //заполняем временный массив нулями
    for(int i = 0; i < SIZE; i++) {
        tempArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        tempArr[num]++;
    }
    //счетчик кол-ва записанных отсортированных элементов
    int length = 0;
    //проходим по всем эелементам временного массива игнорируя нули
    for (int i = 0; i < SIZE; i++) {
        if (tempArr[i] != 0) {
            for (int j = 0; j < tempArr[i]; j++) {
                arr[length] = i;
                length++;
            }
        }
    }
}



//MARK: - 2
/* 2. Реализовать быструю сортировку. */
int counter;

void solution2() {
    counter = 0;
    
    int arr[SIZE];
    fillArray(arr);
    printf("\nUnsorted array:\n");
    printArray(arr, SIZE);
    
    qs(arr, 0, SIZE - 1);
    //quickSort(arr, 0, SIZE - 1);
    printf("\nSorted array:\n");
    printArray(arr, SIZE);
    printf("\nSwap count - %d", counter);
}

void qs(int* arr, int first, int last) {
    int leftBorder = first;
    int rightBorder = last;
    //элемент в центре массива, который берем для сравнения
    int pivot = arr[(first + last) / 2];
    
    do {
        //пока границы меньше pivot перемещаем границы
        while (arr[leftBorder] < pivot) {
            leftBorder++;
        }
        while (arr[rightBorder] > pivot) {
            rightBorder--;
        }
        //меняем местами значения и снова сдвигаем границы
        if(leftBorder <= rightBorder) {
            if (arr[leftBorder] > arr[rightBorder]) {
                swap(arr, leftBorder, rightBorder);
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
        arr[i] = rand() % - 100;
    }
}

//печатаем массив
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int *arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}


//MARK: - 3
/* 3. *Реализовать сортировку слиянием. */
void solution3() {
    counter = 0;
    
    int arr3[SIZE];
    fillArray(arr3);
    printf("\nUnsorted array:\n");
    printArray(arr3, SIZE);
    
    mergeSort(arr3, 0, SIZE - 1);
    printf("\nSorted array:\n");
    printArray(arr3, SIZE);
    printf("\nCount - %d", counter);
}

void mergeSort(int *arr, int first, int last) {
    int split;
    
    //пока границы не сошлись делим массв на 2
    if (first < last) {
        split = (first + last) / 2;
        mergeSort(arr, first, split);
        mergeSort(arr, split+1, last);
        //printf("\n%d - %d - %d", first, last, split);
        merge(arr, first, split, last);
    }
}

void merge(int *arr, int first, int split, int last) {
    int pos1 = first;
    int pos2 = split + 1;
    int posInSortArray = 0;
    
    //временный массив размером как 2 пришедших
    int temp[last - first + 1];
    
    //пока в 2 массивах есть элементы сравниваем и записываем меньшее во временный массив
    while (pos1 <= split && pos2 <= last) {
        if (arr[pos1] < arr[pos2]) {
            temp[posInSortArray++] = arr[pos1++];
        } else {
            temp[posInSortArray++] = arr[pos2++];
        }
    }
    //если в 1 из массивов еще остались числа, записываем их во временный массив
    while (pos1<=split) {
        temp[posInSortArray++] = arr[pos1++];
    }
    while (pos2 <= last) {
        temp[posInSortArray++] = arr[pos2++];
        
    }
    //переносим данные в сортируемый массив
    for (posInSortArray = 0; posInSortArray < (last - first + 1); posInSortArray++) {
        arr[first + posInSortArray] = temp[posInSortArray];
        counter++;
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
