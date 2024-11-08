#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right, *left;
}node;

node * CreateNode(int data)
{
    node * new = (node *)calloc(1, sizeof(node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

int flag=0;
node * temp;

node * Inorder_Successor(node * root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

void Inorder_Traversal(node * root)
{
    node *p = root;
    if (p != NULL)
    {
        Inorder_Traversal(p->left);
        printf("%d->", p->data);
        Inorder_Traversal(p->right);
    }
    
}

node * BST_Insertion(node * root, int data)
{
    if(root==NULL)
    {
        return CreateNode(data);
    }

    if(root->data<data)
    {
        root->right=BST_Insertion(root->right, data);
    }
    else if (root->data>data)
    {
        root->left=BST_Insertion(root->left, data);
    }
    else
    {
        printf("Insertion %d not possible in BST as it already exist.\n", root->data);
    }
    
    return root;
}

node * BST_Delete(node * root, int data)
{
    if(root==NULL)
    {
        flag=1;
        return root;
    }

    if (root->data>data)
    {
        root->left = BST_Delete(root->left, data);
    }
    else if (root->data<data)
    {
        root->right = BST_Delete(root->right, data);
    }
    else
    {
        if(root->left==NULL && root->right==NULL) return NULL;
        else if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        else
        {
            temp = Inorder_Successor(root->right);
            root->data = temp->data;
            root->right = BST_Delete(root->right, temp->data);
        }
    }
    return root;    
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
    printf("Enter your choice:\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\n->");
    scanf("%d", &n);
    return n;
}

int main()
{
    system("cls||clear");
    node * root=NULL;
    // int a[]={20, 15, 27, 10, 17, 24, 30};
    // int n=7, i;

    // printf("Enter how many node :: ");
    // scanf("%d", &n);
            int x;

    while (1)
    {
        int f = 0;
        switch (Menu())
        {
        case 1:
            root = BST_Insertion(root, x=data());
            printf("%d is Inserted.\n", x);
            break;
        case 2:
            root = BST_Delete(root, x=data());
            if(flag) {printf("Element not found.\n"); break;}
            printf("%d is Deleted.\n", x);
            break;
        case 3:
            Inorder_Traversal(root);
            printf("NULL\n");
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
