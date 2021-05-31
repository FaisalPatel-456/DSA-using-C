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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;

        return isBST(root->right);
        
    }
    else
    {
        return 1;
    }
    
}

int main()
{
    int flag;

    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Tree looks like this
    //       5
    //      / \
    //     3   6
    //    / \
    //   1   4

    printf("In Order Traversal\n");
    inorderTraversal(p);
    printf("\n");

    if(isBST(p))
    {
        printf("This is BST\n");
    }
    else
    {
        printf("This is not BST\n");
    }
    

    return 0;
}