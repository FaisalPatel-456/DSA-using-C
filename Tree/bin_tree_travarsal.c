#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * createNode(int data)
{
    struct node *n;
    n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t", root->data);
    }
}

void inorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{

    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Tree looks like this
    //       4
    //      /  \
    //     1    6
    //    / \
    //   5   2

    printf("Pre Order Traversal\n");
    preorderTraversal(p);
    printf("\n");

    printf("Post Order Traversal\n");
    postorderTraversal(p);
    printf("\n");

    printf("In Order Traversal\n");
    inorderTraversal(p);
    printf("\n");

    return 0;
}