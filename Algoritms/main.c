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
#define MaxN 10

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
/* 1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов. */

void solution1() {
    
}



//MARK: - 2
/* 2. Переписать программу, реализующую двоичное дерево поиска.
 а) Добавить в него обход дерева различными способами;
 б) Реализовать поиск в двоичном дереве поиска;
 в) *Добавить в программу обработку командной строки, с помощью которой можно указывать, из какого файла считывать данные, каким образом обходить дерево. */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void printTree(Node* root) {
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            
            if (root->left) {
                printTree(root->left);
            } else {
                printf("NULL");
            }
            printf(",");
            
            if (root->right) {
                printTree(root->right);
            } else {
                printf("NULL");
            }
            printf(")");
        }
    }
}

Node* getTreeNode(int value, Node* parent) {
    Node* tmp = (Node*)malloc(sizeof(Node*));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insertNode(Node** head, int value) {
    Node* tmp = NULL;
    if (*head == NULL) {
        *head = getTreeNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getTreeNode(value, tmp);
                return;
            }
        }  else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getTreeNode(value, tmp);
                return;
            }
        }
    }
}
//Прямой обход бинарного дерева
void preOrder(Node* root) {
    if (root == NULL) {
                return;
    }
    if (root->data) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Симметричный обход бинарного дерева
void inOrder(Node* root) {
    if (root == NULL) {
         return;
    }
    inOrder(root->left);
    if (root->data) {
        printf("%d ", root->data);
    }
    inOrder(root->right);
}

//Обратный обход бинарного дерева
void postOrder(Node* root) {
    if (root == NULL) {
         return;
    }
    postOrder(root->left);
    postOrder(root->right);
    if (root->data) {
        printf("%d ", root->data);
    }
}

//Поиск в двоичном дереве поиска
Node *seachInTree(Node* root, int number) {
    if (root == NULL || root->data == number) {
        return root;
    }
    if (number > root->data) {
        return seachInTree(root->right, number);
    } else {
        return seachInTree(root->left, number);
    }
}

void solution2() {
    int array[MaxN] = {10, 7, 5, 6, 16, 9, 15, 20, 21, 4};
    Node *Tree = NULL;
    int i;
    for (i = 0; i < MaxN; i++) {
        int value = array[i];
        insertNode(&Tree, value);
    }
    printf("Tree");
    printTree(Tree);
    printf("\nПрямой обход бинарного дерева - ");
    preOrder(Tree);
    printf("\nСимметричный обход бинарного дерева - ");
    inOrder(Tree);
    printf("\nОбратный обход бинарного дерева - ");
    postOrder(Tree);
    int number;
    printf("\n Введите одно из чисел - 4, 5, 6, 7, 9, 10, 15, 16, 20, 21: \n");
    scanf("%d", &number);
    Node *elem = seachInTree(Tree, number);
    printf("Parent - %d, data - %d, left element data - %d, right element data - %d", elem->parent->data, elem->data, elem->left->data, elem->right->data);
    
}

//MARK: - 3
/* 3. *Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер», в которой использовать все знания, полученные на уроках.
 Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес). */



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
