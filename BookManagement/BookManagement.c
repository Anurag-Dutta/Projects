/*
    AUTHOR: BlueKnight
    CREATED: 2021-09-30 19:20:02
*/
#pragma GCC diagnostic ignored "-Wenum-compare"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <fenv.h>
#include <stdnoreturn.h>
#include <stdalign.h>
#include <iso646.h>
#include <dlfcn.h>
#include <stddef.h>
#include <errno.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void print(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
}
void count(struct node *head)
{
    int cnt = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->link;
    }
    printf("\n%d", cnt);
}
void head_insert(int data)
{
    struct node *NEWNODE = (struct node *)malloc(sizeof(struct node));
    NEWNODE->link = head;
    NEWNODE->data = data;
    head = NEWNODE;
}
void tail_insert(int data)
{
    struct node *NEWNODE = (struct node *)malloc(sizeof(struct node));
    NEWNODE->data = data;
    NEWNODE->link = NULL;
    if (head == NULL)
    {
        head_insert(data);
    }
    else
    {
        struct node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = NEWNODE;
    }
}
void random_insert(int data, int key)
{
    struct node *NEWNODE = (struct node *)malloc(sizeof(struct node));
    NEWNODE->data = data;
    if (key == 0)
    {
        head_insert(data);
    }
    else
    {
        struct node *ptr = head;
        int index = 1;
        while (index != key)
        {
            index++;
            ptr = ptr->link;
        }
        NEWNODE->link = ptr->link;
        ptr->link = NEWNODE;
    }
}
void search(struct node *head, int key)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Found\n");
            return;
        }
        ptr = ptr->link;
    }
    printf("Not found\n");
}
void delete_head()
{
    struct node *ptr = head;
    head = ptr->link;
    free(ptr);
}
void delete_tail()
{
    struct node *ptr1 = head;
    struct node *ptr2;
    while (ptr1->link != NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->link;
    }
    ptr2->link = NULL;
    free(ptr1);
}
void delete_random(int data)
{
    struct node *ptr = head;
    while (ptr->link->data != data)
    {
        ptr = ptr->link;
    }
    struct node *todelete = ptr->link;
    ptr->link = ptr->link->link;
    free(todelete);
}
int main()
{
    system("cls");
    printf("\t\tWELCOME TO BLUE KNIGHT's LIBRARY\t\t");
    int choice = 'Y';
    int ch;
    while (1)
    {
        if (choice == 0)
        {
            break;
        }
        printf("\n-----COMMAND PALLATE-----\n");
        printf("\nTo insert book(s), Press '1': ");
        printf("\nTo remove book(s), Press '2': ");
        printf("\nTo search book(s), Press '3': ");
        printf("\nEnter your Command: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int ins;
            printf("\n\n-----SUB COMMAND PALLATE-----\n");
            printf("\nTo insert book(s) at top(head), Press '1': ");
            printf("\nTo insert book(s) at bottom(tail), Press '2': ");
            printf("\nTo insert book(s) at random(random), Press '3': ");
            printf("\nEnter your Command: ");
            scanf("%d", &ins);
            switch (ins)
            {
            case 1:
            {
                int data;
                printf("\nEnter the Book Code: ");
                scanf("%d", &data);
                printf("\nInserting at Head...");
                head_insert(data);
                break;
            }
            case 2:
            {
                int data;
                printf("\nEnter the Book Code: ");
                scanf("%d", &data);
                printf("\nInserting at Bottom...");
                tail_insert(data);
                break;
            }
            case 3:
            {
                int data, key;
                printf("\nEnter the Book Code: ");
                scanf("%d", &data);
                printf("\nEnter the Category Number: ");
                scanf("%d", &key);
                printf("\nInserting at Category Number %d...", key);
                random_insert(data, key);
                break;
            }
            default:
            {
                printf("\nAre you sure that you have entered the CORRECT choice? ");
                break;
            }
            }
            break;
        }
        case 2:
        {
            int rem;
            printf("\n\n-----SUB COMMAND PALLATE-----\n");
            printf("\nTo remove book(s) from top(head), Press '1': ");
            printf("\nTo remove book(s) from bottom(tail), Press '2': ");
            printf("\nTo remove book(s) from random(random), Press '3': ");
            printf("\nEnter your Command: ");
            scanf("%d", &rem);
            switch (rem)
            {
            case 1:
            {
                printf("\nRemoving from Head...");
                delete_head();
                break;
            }
            case 2:
            {
                printf("\nRemoving from Tail...");
                delete_tail();
                break;
            }
            case 3:
            {
                int key;
                printf("\nEnter the Book Code: ");
                scanf("%d", &key);
                printf("\nRemoving the Book with Book Code %d...", key);
                delete_random(key);
                break;
            }
            default:
            {
                printf("\nAre you sure that you have entered the CORRECT choice? ");
                break;
            }
            }
            break;
        }
        case 3:
        {
            int key;
            printf("\nEnter the Book Code to be Searched: ");
            scanf("%d", &key);
            search(head, key);
            break;
        }
        }
        printf("\n");
        print(head);
        printf("\nWanna spend some more time(1 - YES, 0 - NO) ? ");
        scanf("%d", &choice);
        system("cls");
    }
    return 0;
}