
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

struct Node *CreateNode()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a element: ");
    scanf("%d", &node->data);
    node->next = NULL;
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
        struct Node *q = (*head)->next;
        node -= 2;
        while (node--)
        {
            p = p->next;
            q = q->next;
        }
        new->next = q;
        p->next = new;
    }
}

// find greatest element in a Linked List.
int Max(struct Node **head)
{
    struct Node *ptr = *head;
    int max = ptr->data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (max < ptr->data)
        {
            max = ptr->data;
        }
    }
    return max;
}

// find smallest element in a Linked List.
int Min(struct Node **head)
{
    struct Node *ptr = *head;
    int min = ptr->data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (min > ptr->data)
        {
            min = ptr->data;
        }
    }
    return min;
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

void LinearSearch(struct Node **head, int key)
{
    struct Node *ptr = *head;

    if (ptr == NULL)
    {
        printf("\n!!Invalid Linked List !!\n");
        return;
    }

    int node = 0;
    while (ptr != NULL)
    {
        node++;
        if (ptr->data == key)
        {
            printf("Element found at position: %d\n", node);
            return;
        }
        ptr = ptr->next;
    }
    printf("Element does not exist.\n");
    return;
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

void InsertAtMiddle(struct Node **head)
{
    struct Node *new = CreateNode();
    struct Node *p = middle((*head), NULL);
    new->next = p->next;
    p->next = new;
}

char Menu()
{
    int c;
    printf("\nPress 1 for insert at first.\nPress 2 for insert at any position.\nPress 3 for insert after middle.\nPress 4 for find greatest number.\nPress 5 for find smallest number.\nPress 6 for find middle position number.\nPress 7 for for element using Linear search.\nPress 8 for find element using Binary search.\nPress 9 for reverse linked list.\nPress 10 for showlinked list.\n\n->");
    fflush(stdin);
    scanf("%d", &c);
    return c;
}

struct Node * reverse(struct Node ** head)
{
    struct Node *prevptr = NULL, *currptr = *head, *nextptr = NULL;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

struct Node * reverseRecursion(struct Node ** head)
{
    if ((*head)==NULL || (*head)->next==NULL)    
    {
        return (*head);
    }
    
    struct Node *newHead = reverseRecursion(&((*head)->next));
    (*head)->next->next=(*head);
    (*head)->next=NULL;
    
    return newHead;
}

int main()
{
    // system("clear||cls");
    int n, i, j, k, position, key, input;
    struct Node *head = NULL;
    struct Node *newhead = NULL;
    printf("Enter how many node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        InsertAtEnd(&head);
    LinkedListTraversal(&head);

    fflush(stdin);
    while (1)
    {
        input = Menu();
        switch (input)
        {
        case 0:
             break;
        case 1:
            InsertAtFirst(&head);
            LinkedListTraversal(&head);
            break;
        case 2:
            printf("Enter the position you want to insert:");
            scanf("%d", &position);
            InsertAtAnyPosition(&head, position);
            LinkedListTraversal(&head);
            break;
        case 3:
            InsertAtMiddle(&head);
            LinkedListTraversal(&head);
            break;
        case 4:
            printf("Maximum = %d\n", Max(&head));
            break;
        case 5:
            printf("Minimum = %d\n", Min(&head));
            break;
        case 6:
            printf("Middle element = %d\n", middle(head, NULL)->data);
            break;
        case 7:
            printf("Enter the element you are searching:");
            scanf("%d", &key);
            LinearSearch(&head, key);
            break;
        case 8:
            InsertAtFirst(&head);
            LinkedListTraversal(&head);
            break;
        case 9:
            newhead = reverse(&head);
            LinkedListTraversal(&newhead);
            break;
        case 10:    
            LinkedListTraversal(&head);
            break;
        case 11:
            newhead = reverseRecursion(&head);
            LinkedListTraversal(&newhead);
            break;
        default:
            printf("Enter a valid number");
            break;
        }
        if (!input)
        {
            break;
        }
        
    }

    // InsertAtAnyPosition(&head, 1);
    // InsertAtMiddle(&head);
    // LinkedListTraversal(&head);

    // (BinarySearch(&head, 9) != NULL) ? printf("Element found.\n") : printf("Element is not found.\n");
    // LinkedListTraversal(&head);

    return 0;
}
