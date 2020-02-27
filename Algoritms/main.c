
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define SIZE 50

//Рейнгардт Анастасия

int main(int argc, const char * argv[]) {
    int sel = 0;
    do {
        menu();
        scanf("%d", &sel);
        switch (sel) {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
            default:
                break;
        }
        printf("\n\n");
    } while (sel != 0);
    return 0;
}

//MARK: - TASK 1
/* 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций. */
void solution1() {
    int arr[SIZE];//{53, 53, 77, 48, 40, 6, 64, 90, 0, 34, 69, 6, 11, 38, 53, 81, 46, 7, 99, 38};
    
    fill_array(SIZE, arr);
    int arr2[SIZE];
    int i;
    for(i = 0; i < SIZE; i++) {
        arr2[i] = arr[i];
    }
    
    printf("Array 1\n");
    print(SIZE, arr);
    buble_sort(arr);
    print(SIZE, arr);
    printf("______________\n");
    printf("Array 2\n");
    print(SIZE, arr2);
    buble_sort2(arr2);
    print(SIZE, arr2);
}

void buble_sort(int arr[]) {
    int count = 0;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printf("Count = %d \n", count);
}

void buble_sort2(int arr[]) {
    int count = 0;
    int i, j;
    for (i = 1; i <= SIZE; i++) {
        int count_swap = 0;
        for (j = 0; j < SIZE - i; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                count_swap++;
            }
        }
        if (count_swap == 0) break;
    }
    printf("Count = %d \n", count);
}


//MARK: - TASK 2
/* 2. *Реализовать шейкерную сортировку. */
void solution2() {
    int arr[SIZE];
    fill_array(SIZE, arr);
    int arr2[SIZE];
    int i;
    for(i = 0; i < SIZE; i++) {
        arr2[i] = arr[i];
    }
    
    printf("Array 1\n");
    print(SIZE, arr);
    shaker_sort(arr);
    print(SIZE, arr);
    printf("______________\n");
    printf("Array 2\n");
    print(SIZE, arr2);
    shaker_sort2(arr2);
    print(SIZE, arr2);
}

void shaker_sort(int arr[]) {
    int count = 0;
    int i, j;
    int first = 0;
    int last = SIZE - 1;
    for (i = 1; i <= SIZE; i++) {
        int count_swap = 0;
        if (i % 2 == 1) {
            last = last - 1;
            for (j = first; j <= last; j++) {
                count++;
                if (arr[j] > arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                    count_swap++;
                }
            }
        } else {
            first = first + 1;
            for (j = last + 1; j >= first; j--) {
                count++;
                if (arr[j - 1] > arr[j]) {
                    swap(&arr[j - 1], &arr[j]);
                    count_swap++;
                }
            }
        }
        if (count_swap == 0) break;
    }
    printf("Count = %d \n", count);
}

//еще один вариант решения
void shaker_sort2(int arr[]) {
    int elemIndex = 0;
    int nextIndex = 1;
    int left = 0;
    int right = SIZE - 1;
    int count = 0;
    
    while (left != right && right - left > 1) {
        count++;
        if(nextIndex == right){
            if(arr[elemIndex] > arr[nextIndex]){
                swap(&arr[elemIndex], &arr[nextIndex]);
            }
            right = elemIndex;
            nextIndex = elemIndex - 1;
        } else if(nextIndex == left){
            if(arr[nextIndex] > arr[elemIndex]){
                swap(&arr[elemIndex], &arr[nextIndex]);
            }
            left = elemIndex;
            nextIndex = elemIndex + 1;
        }
        if(elemIndex < nextIndex){
            if(arr[elemIndex] > arr[nextIndex]){
                swap(&arr[elemIndex], &arr[nextIndex]);
            }
            elemIndex++;
            nextIndex++;
        } else {
            if(arr[nextIndex] > arr[elemIndex]){
                swap(&arr[elemIndex], &arr[nextIndex]);
            }
            elemIndex--;
            nextIndex--;
        }
    }
    printf("Count = %d \n", count);
}


//MARK: - TASK 3
/* 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден. */
void solution3() {
    int arr[SIZE];
    int num;
    fill(SIZE, arr);
    print(SIZE, arr);
    printf("Input number from 1 to 100: ");
    scanf("%d", &num);
    printf("Index %d", binary_search(arr, num));
}

int binary_search(int arr[], int num) {
    int count = 0;
    int left = 0;
    int right = SIZE - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        count++;
        if (arr[mid] == num) {
            printf("Count - %d\n", count);
            return mid;
        }
        if (arr[mid] < num) {
            left = mid + 1;
        }
        if (arr[mid] > num) {
            right = mid - 1;
        }
    }
    printf("Count - %d\n", count);
    return -1;
}

void fill(int l, int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
}

//MARK: - Supporting func

void fill_array(int l, int arr[]) {
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("0 - exit\n");
}
