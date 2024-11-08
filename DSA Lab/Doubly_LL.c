
#include <stdio.h>
#include <string.h>
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

void LinkedListTraversalRev(struct Node **head)
{
    printf("\n");
    struct Node *p = *head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->prev;
    }
    printf("NULL\n");
}

struct Node *CreateNode()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a element: ");
    scanf("%d", &node->data);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void InsertAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        struct Node *new = CreateNode();
        *head = new;
    }
    else
    {
        struct Node *q = *head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = CreateNode();
        q->next->prev = q;
    }
}

void InsertAtFirst(struct Node **head)
{
    if (*head == NULL)
    {
        struct Node *new = CreateNode();
        *head = new;
    }
    else
    {
        struct Node *new = CreateNode();
        struct Node *q = *head;
        new->next = q;
        q->prev = new;
        *head = new;
    }
}

void InsertAtAnyPosition(struct Node **head, int node)
{
    // check the given many nodes are exist or not.
    int c = 0;
    struct Node *temp = *head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (c < node)
    {
        printf("\nInsertion not possible as lack of node.\nIn this linked list %d nodes are exist.\n", c);
        return;
    }

    // insertion operation.
    if (node == 1)
    {
        InsertAtFirst(head);
    }
    else
    {
        struct Node *new = CreateNode();
        struct Node *p = *head;
        for (int i = 0; i < node - 2; i++)
        {
            p = p->next;
        }
        new->next = p->next;
        p->next->prev = new;
        p->next = new;
        new->prev = p;
    }
}

void DeleteAtFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Process Abroat !! No node found.\n");
    }
    else
    {
        struct Node *p = *head;
        p->next->prev = NULL;
        *head = p->next;
        free(p);
    }
}

void DeleteAtEnd(struct Node **head)
{
    struct Node *p = *head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
}

void DeleteAtAnyPosition(struct Node **head, int node)
{
    // check the given many nodes are exist or not.
    int c = 0;
    struct Node *temp = *head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (c < node)
    {
        printf("\nDeletion not possible as lack of node.\nIn this linked list %d nodes are exist.\n", c);
        return;
    }

    // Delete operation.
    if (node == 1)
    {
        DeleteAtFirst(head);
    }
    else
    {
        struct Node *p = *head;
        for (int i = 0; i < node - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
}

void Swap(struct Node *p, struct Node *q)
{
    int temp;
    temp = p->data;
    p->data = q->data;
    q->data = temp;
}

void MoveNodeAtAnyPosition(struct Node **head, int s, int d)
{
    // check the given many nodes are exist or not.
    int c = 0;
    struct Node *temp = *head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (c < s || c < d)
    {
        printf("\nDeletion not possible as lack of node.\nIn this linked list %d nodes are exist.\n", c);
        return;
    }
    if (s == d || s < 0 || d < 0)
    {
        printf("\nDeletion not possible as invalid input.\n");
        return;
    }

    // moving operation.
    if ((s == 1 || s == 2) && (d == 1 || d == 2))
    {
        struct Node *p = *head;
        struct Node *q = (*head)->next;
        Swap(p, q);
    }

    else
    {
        struct Node *p = *head;
        struct Node *q = *head;
        for (int i = 0; i < s - 1; i++)
        {
            p = p->next;
        }
        for (int i = 0; i < d - 1; i++)
        {
            q = q->next;
        }
        Swap(p, q);
    }
}

int main()
{
    system("clear");
    int n, i, j, k, position, key, input;
    struct Node *head = NULL;
    printf("Enter how many node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        InsertAtEnd(&head);
    LinkedListTraversal(&head);
    LinkedListTraversalRev(&head);

    // InsertAtFirst(&head);
    // InsertAtAnyPosition(&head, 3);
    // DeleteAtFirst(&head);
    // DeleteAtEnd(&head);
    // DeleteAtAnyPosition(&head, 3);
    // MoveNodeAtAnyPosition(&head, 2, 4);

    // LinkedListTraversal(&head);
    // LinkedListTraversalRev(&head);

    return 0;
}
