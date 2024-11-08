// Binary Search using Linked List.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
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
    }
}

void Swap(struct Node *p, struct Node *q)
{
    int temp;
    temp = p->data;
    p->data = q->data;
    q->data = temp;
}

void BubbleSort(struct Node **head)
{
    struct Node *p, *q;
    while (1)
    {
        int c = 0;
        p = (*head);
        q = (*head)->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                Swap(p, q);
                c++;
            }
            p = p->next;
            q = q->next;
        }
        if (!c)
        {
            break;
        }
    }
}

struct Node *middle(struct Node *start, struct Node *last)
{
    if (start == NULL)
        return NULL;

    struct Node *p = start;
    struct Node *q = start->next;

    while (q != last)
    {
        q = q->next;
        if (q != last)
        {
            p = p->next;
            q = q->next;
        }
    }

    return p;
}

struct Node *BinarySearch(struct Node **head, int value)
{
    BubbleSort((head));
    struct Node *start = *head;
    struct Node *last = NULL;

    do
    {
        struct Node *mid = middle(start, last);

        if (mid == NULL)
            return NULL;

        if (mid->data == value)
            return mid;

        else if (mid->data < value)
            start = mid->next;

        else
            last = mid;

    } while (last == NULL || last != start);

    return NULL;
}

int main()
{
    system("clear");
    int n, i, data, key;
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

    printf("Enter the element you are searching: ");
    scanf("%d", &key);

    if (BinarySearch(&head, key) == NULL)
    {
        printf("Element not found.\n");
    }
    else
    {
        printf("Element found.\n");
    }

    return 0;
}