/**
 * @file ll1.c
 * @author your name (you@domain.com)
 * @brief Singly linked list
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *ptr;
    int num;
}NODE;

NODE *HEAD = NULL;

void append(int value)
{
    NODE *x = malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Insufficient memory");
        return;
    }
    x->num = value;
    x->ptr = NULL;

    // If list is still empty
    if (HEAD == NULL) {
        HEAD = x;
        return;
    }

    // List is not empty
    NODE *last_ptr = HEAD;
    while(last_ptr->ptr != NULL) {
        last_ptr = last_ptr->ptr;
    }
    last_ptr->ptr = x;
}

void print_all(NODE *print_pos)
{
    for (NODE *i = print_pos; i != NULL; i = i->ptr) {
        printf("%d\n", i->num);
    }
}

void free_all(NODE *head)
{
    NODE *next_ptr = head;
    NODE *current_ptr = head;
    do {
        current_ptr = next_ptr;
        next_ptr = current_ptr->ptr;
        free(current_ptr);
    } while (next_ptr != NULL);
}

int main(void)
{
    append(2);
    append(3);
    append(4);
    append(5);
    append(6);
    append(7);

    print_all(HEAD);
    //free_all(HEAD);
    return 0;
}