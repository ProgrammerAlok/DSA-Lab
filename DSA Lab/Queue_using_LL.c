#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->next = NULL;
    new->data = data;
    return new;
}

bool isEmpty(node **head)
{
    return (*head == NULL);
}

void push(node **front, node **rear, int data)
{
    if (*front == NULL && *rear == NULL)
    {
        node * new = CreateNode(data);
        *front = *rear = new;
    }
    else
    {
        node *new = CreateNode(data);
        (*rear)->next = new;
        *rear = new;
    }
    printf("%d is pushed.\n", data);
}

void pop(node **front)
{
    if (isEmpty(front))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        node *p = *front;
        printf("%d is poped.\n", p->data);
        (*front) = (*front)->next;
        free(p);
    }
}

void Display(node **front)
{
    printf("\n");
    node *p = *front;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n\n");
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
    node *front = NULL, *rear = NULL;

    while (1)
    {
        int f = 0;
        switch (Menu())
        {
        case 1:
            push(&front, &rear, data());
            break;
        case 2:
            pop(&front);
            break;
        case 3:
            Display(&front);
            break;
        case 4:
            f = 1;
            break;

        default:
            printf("!!Enter correct choice!!\n");
            break;
        }
        if (f) break;
    }

    free(front);
    free(rear);
    return 0;
}