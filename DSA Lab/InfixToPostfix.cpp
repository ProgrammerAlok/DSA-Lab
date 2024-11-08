#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int size;
    char a[20];
    int top;
};

struct stack *CreateStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    return s;
}

int stackTop(struct stack *s){  return s->a[s->top]; }

bool isFull(struct stack *s){ return (s->top == s->size); }

bool isEmpty(struct stack *s){ return (s->top == -1); }

void push(struct stack *s, char key)
{
    if (isFull(s))
    {
        printf("Stack is full.\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = key;
    }
}

char pop(struct stack *s)
{
    char c;
    c = s->a[s->top];
    if (isEmpty(s))
    {
        printf("stack is empty.");
    }
    else
    {
        s->top--;
        return c;
    }
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int Presedense(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
}

char *InfixToPostfix(char *c)
{
    int i = 0, j = 0, k = 0;

    struct stack *s = CreateStack();
    char *postfix = (char *)calloc((strlen(c)+1),  sizeof(char));

    while (c[i] != '\0')
    {
        if (!isOperator(c[i]))
        {
            postfix[j] = c[i];
            i++;
            j++;
        }
        else
        {
            if (Presedense(c[i]) > Presedense(stackTop(s)))
            {
                push(s, c[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }

    return postfix;
}

int main()
{
    char *infix = (char *)calloc(200, sizeof(char));
    printf("Enter a infix equation :: ");
    fgets(infix, 200, stdin);
    *(infix + strlen(infix) - 1)='\0';

    char *postfix = InfixToPostfix(infix);

    printf("The postfix equation :: ");
    printf("%s", postfix);
    printf("\n");

    return 0;
}