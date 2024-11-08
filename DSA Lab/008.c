// Insertion Sort using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void LinkedListTraversal(struct Node **head)
{
    printf("\n");
    struct Node *p = *head;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct Node *CreateNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void InsertAtEnd(struct Node **head, int data)
{

    if (*head == NULL)
    {
        struct Node *new = CreateNode(data);
        *head = new;
    }
    else
    {
        struct Node *q = *head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = CreateNode(data);
        q->next->prev = q;
    }
}

void InsertionSort(struct Node **head)
{
    struct Node *p, *q;
    p = *head;
    int i, j, node = 0, key, move;
    while (p != NULL)
    {
        p = p->next;
        node++;
    }
    for (i = 1; i <= node - 1; i++)
    {
        p = *head;
        q = (*head)->next;
        j = i - 1;
        while (j)
        {
            p = p->next;
            q = q->next;
            j--;
        }
        key = q->data;
        move = i;
        while (move && p->data > key)
        {
            p->next->data = p->data;
            move--;
            if (move >= 1)
            {
                p = p->prev;
            }
        }
        if (p->data > key)
        {
            p->data = key;
        }
        else
        {
            p->next->data = key;
        }
    }
}

int main()
{
    system("clear");
    int n, i, data;
    struct Node *head = NULL;

    FILE *fp;
    fp = fopen("Input.txt", "r");

    printf("Enter how many node: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &data);
        InsertAtEnd(&head, data);
    }
    LinkedListTraversal(&head);

    InsertionSort(&head);
    LinkedListTraversal(&head);

    return 0;
}