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
        printf("Cannot delete, the Linked List is empty");
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

node sort(node first)
{
    int temp;
    node curr = first;
    if (first == NULL)
    {
        printf("Linked list is empty!");
        return NULL;
    }
    else
    {
        while (curr->next != NULL)
        {
            node check = curr->next;
            while (check != NULL)
            {
                if (curr->value > check->value)
                {
                    temp = curr->value;
                    curr->value = check->value;
                    check->value = temp;
                }
                check = check->next;
            }
            curr = curr->next;
        }
        return first;
    }
}

node concatenate(node f1, node f2)
{
    if (f1 == NULL && f2 == NULL)
    {
        printf("The linked lists are empty!");
        return NULL;
    }
    else if (f1 != NULL && f2 == NULL)
        return f1;
    else if (f1 == NULL && f2 != NULL)
        return f2;
    else
    {
        node last = f1;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = f2;
        return f1;
    }
}

node reverse(node first)
{
    if (first == NULL)
    {
        printf("The linked lists are empty!");
        return NULL;
    }
    else
    {
        node rev = NULL;
        while (first != NULL)
        {
            node Next = first->next;
            first->next = rev;
            rev = first;
            first = Next;
        }
        return rev;
    }
}

void display(node first)
{
    node temp;
    temp = first;
    if (temp == NULL)
    {
        printf("The Linked list is empty!");
    }
    else
    {
        printf("The elements in the node are :  ");
        while (temp != NULL)
        {
            printf("%d  ", (temp->value));
            temp = (temp->next);
        }
    }
}

int main()
{
    int choice, n, i, val, x;
    node first = NULL, f1 = NULL, f2 = NULL;
    while (1)
    {
        printf("\n\nEnter the operations to be performed :\n1) Push\n2) Pop\n3) Sort\n4) Concatenate\n5) Reverse\n6) Display\nEnter your choice : ");
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
            first = sort(first);
            break;
        case 4:

            printf("Enter the number of fields for linked list 1 : ");
            scanf("%d", &n);
            printf("Enter %d entries : ", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &val);
                f1 = insert_at_beginning(val, f1);
            }
            printf("Enter the number of fields for linked list 2 : ");
            scanf("%d", &n);
            printf("Enter %d entries : ", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &val);
                f2 = insert_at_beginning(val, f2);
            }
            printf("The concatenated linked list is : ");
            f1 = concatenate(f1, f2);
            display(f1);
            break;
        case 5:
            first = reverse(first);
            break;
        case 6:
            display(first);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
