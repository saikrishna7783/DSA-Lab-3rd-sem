#include <stdio.h>
#include <stdlib.h>
#define size 5

void insert(int q[], int *r, int *item)
{
    if ((*r) == (size - 1))
    {
        printf("Queue overflow!\n")
    }
    else
    {
        (*r)++;
        q[r] = *item;
    }
}

void delete_front(int q[], int *f, int *r)
{
    if ((*f) > (*r))
    {
        printf("Queue underflow!\n");
    }
    else
    {
        printf("The item deleted is : %d", q[(*f)++]);
    }
}

void display(int q[], int *r, int *f)
{
    int i;
    if ((*f) > (*r))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        for (i = (*f); i <= (*r); i++)
        {
            printf("%d", q[i]);
        }
    }
}

int main()
{
    int q[size], item, r, f, choice;
    printf("\n\nMain Menu\n");
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Display\n");
    printf("-------------------\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the element you want to insert : ");
        scanf("%d", &item);
        insert(q[], &r, &item);
        break;
    case 2:
        delete_front(q[], &f, &r);
        break;
    case 3:
        display(q[], &r, &f);
        break;
    default:
        exit(0);
    }
    return 0;
}