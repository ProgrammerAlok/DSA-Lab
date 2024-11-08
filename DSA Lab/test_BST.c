#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;
node *is=NULL;
int flag=0;
node* build_node(int);
node* build_tree(int,node*);
int search(int,node*);
node* delete_node(int,node*);
node *inorder_successor(node*);
void print_in_range(int,int,node*);
void inorder(node*);
int main(void)
{
    system("clear||cls");
    printf("BINARY SEARCH TREE:\n\n");
    node *root=NULL;
    int val,end,index=1;
    while(1)
    {
        printf("Enter The Data for the %d Node(-1 to exit):",index++);
        scanf("%d",&val); 
        if(val==-1 && index==2)
        {
            index--;
            printf("Should have atleast one value!\n");
        }
        else if(val==-1) break;
        root=build_tree(val,root);
    }
    printf("The Tree After inorder traversal: ");
    inorder(root);printf("END\n");
    printf("The the element to search:");
    scanf("%d",&val);
    if(search(val,root)==1) printf("Found!\n");
    else printf("Not Found!\n");
    printf("The the element to delete:");
    scanf("%d",&val);
    root=delete_node(val,root);
    if(flag!=1)
    {
        printf("The Tree After deletion and inorder traversal: ");
        inorder(root);printf("END\n");
    }
    printf("\nPrinting in range..\n");
    printf("Enter The start index:");
    scanf("%d",&val);
    printf("Enter The end index:");
    scanf("%d",&end);
    print_in_range(val,end,root);
    printf("END\n");
}
node* build_node(int val)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}
node* build_tree(int val,node* root)
{
    if(root==NULL)
    {
        root=build_node(val);
        return root;
    }
    if (root->data>val)  root->left=build_tree(val,root->left);
    else root->right=build_tree(val,root->right);
    return root;
}
int search(int key,node* root)
{
    if(root==NULL)  return 0;
    if(root->data>key)  return search(key,root->left);
    else if(root->data<key)  return search(key,root->right);
    else return 1;
}
node* delete_node(int val,node* root)
{
    if(root==NULL)
    {
        flag=1;
        printf("NOT FOUND!\n");
        return root;
    }
    if(root->data>val)
    {
        root->left=delete_node(val,root->left);
    }
    else if(root->data<val)
    {
        root->right=delete_node(val,root->right);
    }
    else
    {
        if(root->left==NULL && root->right==NULL) return NULL;
        else if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        else
        {
            is=inorder_successor(root->right);
            root->data=is->data;
            root->right=delete_node(is->data,root->right);
        }
    }
    return root;
}
node *inorder_successor(node* root) 
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
void print_in_range(int x,int y,node*root)
{
    if(root==NULL) return;
    if(x<=root->data && y>=root->data)
    {
        print_in_range(x,y,root->left);
        printf("%d->",root->data);
        print_in_range(x,y,root->right);
    }
    else if(y<root->data)
    {
        print_in_range(x,y,root->left);
    }
    else
    {
        print_in_range(x,y,root->right);
    }
}
void inorder(node*root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}