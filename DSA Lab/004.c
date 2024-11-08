// Linked List
/*
9. Implement linear search using linked list
10. Find maximum and minimum from a set of numbers using linked list
11. BubbleSort a list of numbers using linked list
12. Insert elements in a linked list
    a. at beginning
    b. at middle
    c. at end

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *InsertElement(struct Node *ptr, int data, int i)
{
    if (!i)
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        struct Node *q = ptr;
        p->data = data;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
        return ptr;
    }
}

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    ptr->next = p;
    p = ptr;
    return p;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *InsertAfterANode(struct Node *head, int data, int node)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q = head->next;

    node--;
    while (node--)
    {
        p = p->next;
        q = q->next;
    }
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int Max(struct Node *head)
{
    struct Node *ptr = head;
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

int Min(struct Node *head)
{
    struct Node *ptr = head;
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

struct Node *BubbleSort(struct Node *head)
{
    struct Node *p;
    struct Node *q;
    while (1)
    {
        int c = 0;
        p = head;
        q = head->next;
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
    return head;
}

void LinearSearch(struct Node *head, int key)
{
    int node = 0;
    struct Node *ptr = head;
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

struct Node *BinarySearch(struct Node *head, int value)
{
    struct Node *start = head;
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

    } while (last == NULL ||
             last != start);

    return NULL;
}

struct Node *InsertAtMiddle(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = middle(head, NULL);
    ptr->data = data;
    ptr->next = q->next;
    q->next = ptr;
    return head;
}

int main()
{
    int i, n, data, key, test;
    struct Node *head;

    printf("Enter how many elements:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &data);
        head = InsertElement(head, data, i); //-> 'i' must start with zero.
    }
    printf("\nPress 1 to insert at begaining.\nPress 2 to insert at middle.\nPress 3 to insert at end.\n");
    scanf("%d", &test);

    printf("Enter the element : ");
    scanf("%d", &key);

    printf("Linked List before insertion:\n");
    LinkedListTraversal(head);

    switch (test)
    {
    case 1:
        head = InsertAtFirst(head, key);
        break;
    case 2:
        head = InsertAtMiddle(head, key);
        break;
    case 3:
        head = InsertAtEnd(head, key);
        break;
    default:
        printf("Enter a valid number.\n");
        break;
    }

    // Print Linked List.
    printf("Linked List after insertion:\n");
    LinkedListTraversal(head);

    // printf("Linked List after sort:\n");
    // head=BubbleSort(head);
    // LinkedListTraversal(head);
    // printf("NULL\n");

    // LinearSearch(head, key);

    // printf("Max = %d\n", Max(head));
    // printf("Min = %d\n", Min(head));

    // InsertAtMiddle(head, 5);
    // LinkedListTraversal(head);
    // printf("NULL\n");

    // head = BubbleSort(head);
    // LinkedListTraversal(head);

    // head = InsertAtFirst(head, 100);
    // LinkedListTraversal(head);
    // head = InsertAtEnd(head, 100);
    // LinkedListTraversal(head);
    // head = InsertAfterANode(head, 100, 3);
    // LinkedListTraversal(head);

    // printf("%d \n", middle(head, NULL)->data);

    // if (BinarySearch(head, 9) != NULL)
    // {
    //     printf("Element found.\n");
    // }
    // else
    // {
    //     printf("Element not found.\n");

    // }

    return 0;
}
