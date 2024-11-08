#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 8

// Node
typedef struct Node
{
    int a[4];
    struct Node *left, *right; //left denotes zero_edge, right denotes one_edge;   
    
}node;


// function prototype....
// take decimal input and return binary output.
int dToBi(int);
int* dToB(int);
void Print(int *, int);
int* decode(int);
node* CreateNodeForZero(int*, int*, int);
node* CreateNodeForOne(int*, int*, int);
node* buildTree(node *head, int *arr);




int main(int length, char *arg[])
{
    int i, n=length-1;

    int *number = (int *)calloc(n, sizeof(int));

    for(i=0; i<n; i++) {
        sscanf(arg[i+1], "%d", (number + i));
    }

    int **arr = (int **)calloc(n, sizeof(int*));

    for(i=0; i<n; i++) {
        arr[i] = dToB(number[i]);
    }

    for(i=0; i<n; i++) {
        Print(arr[i], SIZE);
    }

    int num[] = {0, 1, 2, 3};

    node *head = (node *)calloc(1, sizeof(node));
    for(i=0; i<4; i++) {
        head->a[i] = num[i];
    }
    head->left = head->right = NULL;
    
    head = buildTree(head, arr);

    node *l = CreateNodeForZero(arr[1], num, 4);
    node *r = CreateNodeForOne(arr[1], num, 4);

    Print(l->a, 4);
    Print(r->a, 4);




    return 0;
    
}








// function defination....
node* buildTree(node *head, int *arr)
{

    head->left = CreateNodeForZero(arr, head->a, 4);
    head->right = CreateNodeForOne(arr, head->a, 4);
}
node* CreateNodeForOne(int *arr, int *num, int n)
{
    int i, j=0, c=0;

    node *t = (node *)calloc(1, sizeof(node));

    for(i=0; i<n; i++) {

        if(arr[num[i]] == 1) {

            int *temp = decode(num[i]);

            for(;c<2 && j<4 ; j++, c++) {

                t->a[j] = temp[c];

            }            

            c=0;
        }
    }
    return t;
}

node* CreateNodeForZero(int *arr, int *num, int n)
{
    int i, j=0, c=0;
    node *t = (node *)calloc(1, sizeof(node));
    for(i=0; i<n; i++) {

        if(arr[num[i]] == 0) {

            int *temp = decode(num[i]);

            for(;c<2 && j<4 ; j++, c++) {

                t->a[j] = temp[c];

            }     
            c=0;
        }
    }    
    return t;
}

int* decode(int n)
{
    int *a = (int *)calloc(2, sizeof(int));
    if(n==0 || n==4) {
        a[0] = 0;
        a[1] = 1;
    }
    else if(n==1 || n==5) {
        a[0] = 2;
        a[1] = 3;
    }
    else if(n==2 || n==6) {
        a[0] = 4;
        a[1] = 5;
    }
    else if(n==3 || n==7) {
        a[0] = 6;
        a[1] = 7;
    }
    return a;
}

void Print(int *a, int size)
{
    int i;
    printf("\n");
    for(i=0; i<size; i++)
        printf(" %d", a[i]);
    printf("\n");
}

int dToBi(int decimal)
{
    return decimal?10*dToBi(decimal/2)+(decimal%2):0;
}

int* dToB(int decimal) 
{
    int i;
    int temp = dToBi(decimal);
    int *t = (int *)calloc(SIZE, sizeof(int));
    for(i=0; temp; i++, temp/=10) {
        t[i] = temp%10;
    }
    return t;
}
