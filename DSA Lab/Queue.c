// circular queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int size, *a, f, r;
} que;

que *CreateQueue(int size)
{
    que *new = (que *)calloc(1, sizeof(que));
    new->size = size;
    new->a = (int *)calloc(size, sizeof(int));
    new->f = new->r = -1;
    return new;
}

bool isFull(que *q) { return (((q->r + 1) % q->size) == q->f); }

bool isEmpty(que *q) { return (q->f == -1 && q->r == -1); }

void enQueue(que *q, int data)
{
    if (isEmpty(q))
    {
        q->f = q->r = 0;
        q->a[q->r] = data;
    }
    else if (isFull(q))
    {
        printf("queue is full.\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->a[q->r] = data;
    }
}

void deQueue(que *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty.\n");
    }
    else if (q->f == q->r)
    {
        printf("%d is removed.\n", q->a[q->f]);
        q->f = q->r = -1;
    }
    else
    {
        printf("%d is removed.\n", q->a[q->f]);
        q->f = (q->f + 1) % q->size;
    }
}

void Display(que *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty. nothing to display.\n");
    }
    else
    {
        int i = q->f, j = q->r;
        while (1)
        {
            printf("%d ", q->a[i]);
            if(i == j) break;
            i = (i + 1) % q->size;
        }
    }
    printf("\n");
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
    printf("Enter your choice:\n\t1.Enqueue\n\t2.Dequeue\n\t3.display\n\t4.exit\n->");
    scanf("%d", &n);
    return n;
}

int main()
{
    int n;
    printf("Enter the size of array :: ");
    scanf("%d", &n);

    que *q = CreateQueue(n);

    while (1)
    {
        int f = 0;
        switch (Menu())
        {
        case 1:
            enQueue(q, data());
            break;
        case 2:
            deQueue(q);
            break;
        case 3:
            Display(q);
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