#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *right;
    struct node *left;
    int height;
};

int maximum(int a, int b)
{   
    if(a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int height(struct node *N)
{
    if (N != NULL)
    {
        return N->height;
    }
    else
    {
        return 0;
    }
}

struct node *makeNode(int data)
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->data = data;
    Node->right = NULL;
    Node->left = NULL;
    Node->height = 1;
    return (Node);
}

//right rotation
struct node *Right(struct node *a)
{
    struct node *b = a->left;
    struct node *tmp = b->right;

    b->right = a;
    a->left = tmp;

    a->height = maximum(height(a->right), height(a->left)) + 1;
    b->height = maximum(height(b->right), height(b->left)) + 1;

    return b;
}

//left rotation
struct node *Left(struct node *a)
{
    struct node *b = a->right;
    struct node *tmp = b->left;

    b->left = a;
    a->right = tmp;

    a->height = maximum(height(a->right), height(a->left)) + 1;
    b->height = maximum(height(b->right), height(b->left)) + 1;

    return b;
}

//check if the tree is balanced or not
int Balance_check(struct node *N)
{
    if (N != NULL)
    {
        return height(N->left) - height(N->right);
    }
    else
    {
        return 0;
    }
}

struct node *insert(struct node *Node, int data)
{
    if (Node == NULL)
    {
        return (makeNode(data));
    }

    if (data > Node->data)
    {
        Node->right = insert(Node->right, data);
    }
    else if (data < Node->data)
    {
        Node->left = insert(Node->left, data);
    }
    else
    {
        return Node;
    }

    Node->height = 1 + maximum(height(Node->left), height(Node->right));

    int bal = Balance_check(Node);

    //left left case
    if (bal > 1 && data < Node->left->data)
    {
        return Right(Node);
    }

    //right right case
    if (bal < -1 && data > Node->right->data)
    {
        return Left(Node);
    }

    //left right case
    if (bal > 1 && data > Node->left->data)
    {
        Node->left = Left(Node->left);
        return Right(Node);
    }

    //right left case
    if (bal < -1 && data < Node->right->data)
    {
        Node->right = Right(Node->right);
        return Left(Node);
    }

    return Node;
}

//find the minimum value in the tree

struct node *min(struct node *Node)
{
    struct node *current = Node;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

//delete a node from the tree
struct node *delete(struct node *Node, int data)
{
    if (Node == NULL)
    {
        return Node;
    }

    if (data > Node->data)
    {
        Node->right = delete(Node->right, data);
    }
    else if (data < Node->data)
    {
        Node->left = delete(Node->left, data);
    }
    else
    {
        if ((Node->left == NULL) || (Node->right == NULL))
        {   
            struct node *tmp = Node->left ? Node->left : Node->right;

            if (tmp == NULL)
            {
                tmp = Node;
                Node = NULL;
            }
            else
            {
                *Node = *tmp;
            }
            free(tmp);
        }
        else
        {
            struct node *tmp = min(Node->right);

            Node->data = tmp->data;

            Node->right = delete(Node->right, tmp->data);
        }
    }

    if (Node == NULL)
    {
        return Node;
    }

    Node->height = 1 + maximum(height(Node->left), height(Node->right));

    int bal = Balance_check(Node);

    //left left case
    if (bal > 1 && Balance_check(Node->left) >= 0)
    {
        return Right(Node);
    }

    //left right case
    if (bal > 1 && Balance_check(Node->left) < 0)
    {
        Node->left = Left(Node->left);
        return Right(Node);
    }

    //right right case
    if (bal < -1 && Balance_check(Node->right) <= 0)
    {
        return Left(Node);
    }

    //right left case
    if (bal < -1 && Balance_check(Node->right) > 0)
    {
        Node->right = Right(Node->right);
        return Left(Node);
    }

    return Node;
}

//print the tree in inorder
void restructure(struct node *Node)
{
    if (Node != NULL)
    {
        restructure(Node->left);
        printf("%d\t", Node->data);
        restructure(Node->right);
    }
}

void main()
{
    struct node *root = NULL;

    //user input to take size of array
    int n;
    printf("Size of array: ");
    scanf("%d", &n);

    //defining the array
    int arr[n];

    //user input for array elements
    for(int i = 0; i<n; i++)
    {
        printf("Element %d of the array: ", i+1);
        scanf("%d", &arr[i]);
    }

    //printing the arrays
    printf("\nElements in the array:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }

    //inserting the elements of the array into the tree
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]);
    }

    //printing the tree in inorder
    printf("Elements in the tree:\n");
    restructure(root);

    //user input to take the element to be deleted
    int del;
    printf("Enter the element to be deleted: ");
    scanf("%d", &del);

    //deleting the element from the tree
    root = delete(root, del);

    //printing the tree in inorder
    printf("\nElements in the tree after deletion:\n");
    restructure(root);
    
}