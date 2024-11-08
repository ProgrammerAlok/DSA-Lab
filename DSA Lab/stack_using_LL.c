#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} node;

node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->next = new->prev = NULL;
    new->data = data;
    return new;
}

bool isEmpty(node **head)
{
    return (*head == NULL) ? true : false;
}

void push(node **head, int data)
{
    if (*head == NULL)
    {
        node *new = CreateNode(data);
        *head = new;
    }
    else
    {
        node *new = CreateNode(data);
        node *q = *head;
        new->next = q;
        q->prev = new;
        *head = new;
    }
}

void pop(node **head)
{
    if (isEmpty(head))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        node *p = *head;
        (*head) = (*head)->next;
        free(p);
    }
}

void Display(node **head)
{
    printf("\n");
    node *p = *head;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int data()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    return n;
}

int Menu()
{
    int n;
    printf("Enter your choice:\n\t1.push\n\t2.pop\n\t3.display\n\t4.exit\n->");
    scanf("%d", &n);
    return n;
}

int main()
{
    node *head = NULL;

    while (1)
    {
        int f = 0;
        switch (Menu())
        {
        case 1:
            push(&head, data());
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            Display(&head);
            break;
        case 4:
            f = 1;
            break;

        default:
            printf("!!Enter correct choice!!\n");
            break;
        }
        if (f)
            break;
    }

    return 0;
}