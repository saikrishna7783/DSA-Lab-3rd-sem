#include <stdio.h>
#include <alloca.h>
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

node insert_at_end(int item, node first)
{
    node temp = (node)malloc(sizeof(struct NODE));
    if (temp == NULL)
    {
        printf("\nMemory not allocated!");
    }
    (temp->value) = item;
    (temp->next) = NULL;
    if ((first->next) == NULL)
    {
        (first->next) = temp;
        return first;
    }
    else
    {
        node last = first;
        while ((last->next) != NULL)
        {
            last = (last->next);
            (last->next) = temp;
            return first;
        }
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

void delete_at_the_beginning(node first)
{
    if (first == NULL)
    {
        printf("\nCannot delete, the Linked List is empty");
    }
    else
    {
        node temp;
        temp = first;
        temp = (first->next);
    }
}

void delete_at_the_end(node first)
{
    if (first == NULL)
    {
        printf("\nCannot delete, the Linked List is empty");
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
    }
}

int main()
{
    int choice, item, x;
    node first = NULL;
    while (1)
    {
        printf("\n\nMenu\n-----------------------------------------\n1) Insert at beginning\n2) Insert at end\n3) Display\n-----------------------------------------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_at_beginning(x, first);
            break;
        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_at_end(x, first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            delete_at_the_beginning(first);
            break;
        case 5:
            delete_at_the_end(first);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}
