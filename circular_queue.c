#include <stdio.h>
#include <stdlib.h>
#define size 5

void insert(int *q, int *r, int *item, int *count)
{
    if ((*count) == size)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        (*r) = ((*r)+1) % size;
        q[(*r)] = (*item);
        (*count)++;
    }
}

void delete_front(int *q, int *r, int *f, int *count)
{
    if ((*count) == 0)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("The element deleted is : %d", q[*f]);
        (*f) = ((*f)+1) % size;
        (*count)--;
    }
}

void display(int *q, int *r, int *f, int *count)
{
    if ((*count) == 0)
    {
        printf("The Queue is empty\n");
    }
    else
    {
        printf("\nThe elements in the queue are : ");
        int i, front;
        front=(*f);
        for (i = 0; i < (*count); i++)
        {
            printf("%d\t", q[front]);
            front = (front+1) % size;
        }
    }
}

int main()
{
    int q[size], item, i, r = -1, f = 0, choice, count = 0;
    while (1)
    {
        printf("\n\nMain Menu\n----------\n1) Insert\n2) Delete\n3) Display\n----------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            insert(q, &r, &item, &count);
            break;
        case 2:
            delete_front(q, &r, &f, &count);
            break;
        case 3:
            display(q, &r, &f, &count);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
