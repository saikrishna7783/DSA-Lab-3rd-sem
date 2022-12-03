#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

int stack[STACK_SIZE], top=-1, item;

void push()
{
    if(top==STACK_SIZE)
        printf("Stack overflow condition\n");
    else
    {
        stack[top]=item;
        top++;
    }
}

void pop()
{
    if(top==-1)
        printf("Stack underflow condition\n");
    else
        top--;
}

void display()
{
    if(top==-1)
        printf("The stack is empty\n");
    else
    {
        int i;
        for(i=top-1;i>=(-1);i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter your choice :\n");
        printf("---------------------\n");
        printf("1) Insert element\n");
        printf("2) Delete element\n");
        printf("3) Display elements\n");
        printf("4) Exit loop\n");
        printf("Your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : printf("Enter the element to be added : ");
            scanf("%d",&item);
            push();
            break;
            case 2 : pop();
            break;
            case 3 : display();
            break;
            case 4 : exit(0);
        }
    }
    return 0;
}
