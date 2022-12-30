#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
};
typedef struct NODE *node;

node insert_at_beginning(int item, node first)
{
    node temp = (node)malloc(sizeof(struct NODE));
    if (temp == NULL)
    {
        printf("\nMemory not allocated!");
    }
    (temp->value) = item;
    (temp->next) = NULL;
    if (first == NULL)
    {
        return temp;
    }
    else
    {
        temp->next = first;
        first = temp;
        return first;
    }
}

node delete_at_the_beginning(node first)
{
    if (first == NULL)
    {
        printf("\nCannot delete, the Linked List is empty");
        return NULL;
    }
    else
    {
        node temp;
        temp = first;
        first = (first->next);
        free(temp);
        return first;
    }
}

node delete_at_the_end(node first)
{
    if (first == NULL)
    {
        printf("\nCannot delete, the Linked List is empty");
        return NULL;
    }
    else
    {
        node prev, curr;
        prev = NULL;
        curr = first;
        while ((curr->next) != NULL)
        {
            prev = curr;
            curr = (curr->next);
        }
        (prev->next) = NULL;
        free(curr);
        return first;
    }
}

void display(node first)
{
    node temp;
    temp = first;
    if (temp == NULL)
    {
        printf("\nThe Linked list is empty!");
    }
    else
    {
        printf("The elements in the node are : ");
        while (temp != NULL)
        {
            printf("%d\t", (temp->value));
            temp = (temp->next);
        }
    }
}

int main()
{
    int choice, pos, item, x;
    node first = NULL;
    printf("Enter the data structure you would want to create :\n1) Stack\n2) Queue\nYour choice : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        while (1)
        {
            printf("\n\nEnter the operations to be performed :\n1) Push\n2) Pop\n3) Display\nEnter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &x);
                first = insert_at_beginning(x, first);
                break;
            case 2:
                first = delete_at_the_beginning(first);
                break;
            case 3:
                display(first);
                break;
            default:
                exit(0);
            }
        }
    }
    else if (choice == 2)
    {
        while (1)
        {
            printf("\n\nEnter the operations to be performed :\n1) Enqueue\n2) Dequeue\n3) Display\nEnter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &x);
                first = insert_at_beginning(x, first);
                break;
            case 2:
                first = delete_at_the_end(first);
                break;
            case 3:
                display(first);
                break;
            default:
                exit(0);
            }
        }
    }
    else
    {
        printf("Enter a valid choice!");
    }
    return 0;
}
