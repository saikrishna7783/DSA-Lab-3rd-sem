#include <stdio.h>
#include <stdlib.h>
#define size 5

void insert(int *q, int *r, int *item)
{
    if ((*r) == (size - 1))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        (*r)++;
        q[(*r)] = (*item);
    }
}

void delete_front(int *q, int *r, int *f)
{
    if ((*r) < (*f))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("The element deleted is : %d", q[(*f)++]);
    }
}

void display(int *q, int *r, int *f)
{
    if ((*r) < (*f))
    {
        printf("The Queue is empty\n");
    }
    else
    {
        printf("The elements in the queue are : ");
        int i;
        for (i = (*f); i <= (*r); i++)
        {
            printf("%d\t", q[i]);
        }
    }
}

int main()
{
    int q[size], item, i, r = -1, f = 0, choice;
    while (1)
    {
        printf("\n\nMain Menu\n----------\n1) Insert\n2) Delete\n3) Display\n----------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            insert(q, &r, &item);
            break;
        case 2:
            delete_front(q, &r, &f);
            break;
        case 3:
            display(q, &r, &f);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
