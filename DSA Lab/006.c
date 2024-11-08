#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node * next;
};


void PrintLL(struct Node *head)
{
    if (head != NULL)
    {
        printf("%c->", head->data);
        PrintLL(head->next);
    }
}


struct Node *InsertElement(struct Node *ptr, char data, int i)
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


int main()
{
    int i, n;
    char data;
    struct Node *head;

    printf("Enter how many elements:\n");
    scanf("%d", &n);
        fflush(stdin);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%c", &data);
        head = InsertElement(head, data, i); //-> 'i' must start with zero.
        fflush(stdin);
    }

    // Print Linked List.
    PrintLL(head);
    printf("NULL");
    printf("\n");

    return 0;
}