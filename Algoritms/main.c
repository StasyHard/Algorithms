//
//  main.c
//  Algoritms
//
//  Created by Anastasia Reyngardt on 04.03.2020.
//  Copyright © 2020 GermanyHome. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "main.h"

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

void solution1() {
    
}

void solution2() {
    
}

void solution3() {
    
}


void menu() {
    printf("Input\n");
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("0 - exit\n");
}
