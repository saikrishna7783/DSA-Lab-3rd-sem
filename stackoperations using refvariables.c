#include <stdio.h>
#include <stdlib.h>
#define max 5

void push(int st[], int *top)
{
    if ((*top) == max - 1)
    {
        printf("Stack overflow!");
    }
    else
    {
        int ele;
        printf("Enter the element to be pushed : ");
        scanf("%d", &ele);
        (*top)++;
        st[*top] = ele;
    }
}

void pop(int st[], int *top)
{
    if ((*top) == -1)
    {
        printf("Stack underflow!");
    }
    else
    {
        printf("The element popped is : %d ", st[(*top)]);
        (*top)--;
    }
}

void display(int st[], int *top)
{
    if ((*top) == -1)
    {
        printf("The stack is empty!");
    }
    else
    {
        printf("The elements in the stack are : ");
        int i;
        for (i = 0; i <= (*top); i++)
        {
            printf("%d\t", st[i]);
        }
    }
}

int main()
{
    int st[max], top = -1, ele, choice;
    while (1)
    {
        printf("\n\nOperation to be done -\n");
        printf("--------------------------\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display elements\n");
        printf("--------------------------\n");
        printf("Your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(st, &top);
            break;
        case 2:
            pop(st, &top);
            break;
        case 3:
            printf("The elements in the stack are : ");
            display(st, &top);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
