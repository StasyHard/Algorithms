
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define SIZE 20

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
    sort_array(arr);
    print(SIZE, arr);
    
    printf("Array 2\n");
    print(SIZE, arr2);
    sort_array2(arr2);
    print(SIZE, arr2);
}

void sort_array(int arr[]) {
    int count = 0;
    int i, j;
    for (i = 1; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printf("Count = %d \n", count);
}

void sort_array2(int arr[]) {
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
    int arr[SIZE];//{53, 53, 77, 48, 40, 6, 64, 90, 0, 34, 69, 6, 11, 38, 53, 81, 46, 7, 99, 38};
    
    fill_array(SIZE, arr);
    print(SIZE, arr);
}

//MARK: - TASK 3
/* 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден. */
void solution3() {
    
}


//MARK: - Supporting func

void fill_array(int l, int arr[]) {
    srand(time(NULL));
    for (int i = 0; i<SIZE; i++)
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
