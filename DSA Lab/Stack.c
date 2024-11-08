#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int size;
    int *a;
    int top;
};

struct stack *CreateStack(int size)
{
    struct stack *s = NULL;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = size;
    s->a = (int *)calloc(s->size, sizeof(int));
    return s;
}

bool isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        return true;
    return false;
}

bool isEmpty(struct stack *s)
{
    if (s->top == -1)
        return true;
    return false;
}

void push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("stack is full.\n");
        return;
    }
    s->top++;
    s->a[s->top] = data;
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty.\n");
        return;
    }
    int *t = s->a + s->top;
    printf("%d is pop.\n", s->a[s->top--]);
    free(t);
}

void Display(struct stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->a[i]);
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
    printf("Enter your choice:\n\t1.push\n\t2.pop\n\t3.display\n\t4.exit\n->");
    scanf("%d", &n);
    return n;
}

int main()
{
    struct stack *s = CreateStack(5);
   
    while (1)
    {
        int f = 0;
        switch (Menu())
        {
        case 1:
            push(s, data());
            break;
        case 2:
            pop(s);
            break;
        case 3:
            Display(s);
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