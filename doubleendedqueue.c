#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int count = 0;

void enqueueR(int *r, int *f, int a[], int item)
{
    if (((*f) == (*r) + 1) || (((*f) == 0) && ((*r) == SIZE - 1)))
    {
        printf("Queue is Currently Full.");
    }
    else
    {
        if ((*f) == -1)
            (*f) = 0;
        (*r)++;
        (*r) = (*r) % SIZE;
        a[*r] = item;
        count++;
    }
}

int dequeueF(int *r, int *f, int a[])
{
    int del_item;
    if ((*f) == -1)
    {
        printf("Queue is Currently Empty.");
        return 0;
    }
    else
    {
        del_item = a[*f];
        if ((*f) == (*r))
        {
            (*f) = -1;
            (*r) = -1;
        }
        else
        {
            (*f)++;
            (*f) = (*f) % SIZE;
        }
        count--;
        return del_item;
    }
}

void enqueueF(int *r, int *f, int a[], int item)
{
    if (((*f) == (*r) + 1) || (((*f) == 0) && ((*r) == SIZE - 1)))
    {
        printf("Queue is Currently Full.");
    }
    else
    {
        if ((*f) == -1)
            (*f) = 0;
        (*f) = (*f + SIZE - 1) % SIZE;
        a[*f] = item;
        count++;
    }
}

int dequeueR(int *r, int *f, int a[])
{
    int del_item;
    if ((*f) == -1)
    {
        printf("Queue is Currently Empty.");
        return 0;
    }
    else
    {
        del_item = a[*r];
        if ((*f) == (*r))
        {
            (*f) = -1;
            (*r) = -1;
        }
        else
        {
            (*r) = (*r + SIZE - 1) % SIZE;
        }
        count--;
        return del_item;
    }
}

void display(int *r, int *f, int a[])
{
    int i, temp;

    if ((*f) == -1)
    {
        printf("Queue is Currently Empty.");
    }
    else
    {
        temp = *f;
        for (i = 0; i < count; i++)
        {
            printf("%d ", a[temp]);
            temp = (++temp) % SIZE;
        }
    }
}

int main()
{
    int ch, ele, f = -1, r = -1, queue[SIZE], del_item;
    while (1)
    {
        printf("\n1.EnqueueR Operation\n");
        printf("2.DequeueF Operation\n");
        printf("3.Display the Queue\n");
        printf("4.EnqueueF Operation\n");
        printf("5.DequeueR Operation\n");
        printf("6.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &ele);
            enqueueR(&r, &f, queue, ele);
            break;
        case 2:
            del_item = dequeueF(&r, &f, queue);
            printf("Deleted element:%d", del_item);

            break;
        case 3:
            display(&r, &f, queue);
            break;
        case 4:
            printf("Enter the element to be inserted:");
            scanf("%d", &ele);
            enqueueF(&r, &f, queue, ele);
            break;
        case 5:
            del_item = dequeueR(&r, &f, queue);
            printf("Deleted element:%d", del_item);
            break;
        case 6:
            exit(0);
        default:
            printf("Incorrect choice \n");
            break;
        }
    }
    return 0;
}
