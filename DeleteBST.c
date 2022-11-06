#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node *delnode(node *root, int nod)
{   
    if (root == NULL)
        return root;

    //if node to be deleted is smaller than root, then it lies in left subtree
    if (nod < root->data)
        root->left = delnode(root->left, nod);

    //if node to be deleted is greater than root, then it lies in right subtree
    else if (nod > root->data)
        root->right = delnode(root->right, nod);

    //if node to be deleted is same as root, then this is the node to be deleted
    else
    {   
        //node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        //node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        
        root->data = temp->data;
        root->right = delnode(root->right, temp->data);
    }
    return root;
}

void main()
{
    //user input to take size of array
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    //defining an array of size n
    int array[n];

    //user input for array elements
    for(int i = 0; i<n; i++)
    {
        printf("Enter element %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }

    //printing the array
    printf("These are the elements in the array:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d", array[i]);
    }

    //getting first element of the array
    int f1 = array[0];
    //Creating a pointer by type-casting
    struct Node *N;
    N = (struct Node *) malloc(sizeof(struct Node));
    N->data = f1;
    N->left = NULL;
    N->right = NULL;

    //declaring head and pointers
    node *head, *p;
    head = N;
    p = head;

    //loop assign next nodes from array
    for(int i = 1; i<n; ++i)
    {
        f1 = array[i];

        N = (struct Node *) malloc(sizeof(struct Node));
        N->data = f1;
        N->left = NULL;
        N->right = NULL;

        p = head;
        while (p != NULL)
        {
            if (f1 < p->data)
            {
                if (p->left == NULL)
                {
                    p->left = N;
                    break;
                }
                else
                    p = p->left;
            }
            else
            {
                if (p->right == NULL)
                {
                    p->right = N;
                    break;
                }
                else
                    p = p->right;
            }
        }
    }

    //printing the binary search tree
    printf("\nThese are the elements in the BST:\n");
    p = head;
    while (p != NULL)
    {
        printf("%d \t", p->data);
        p = p->right;
    }

    //user input to take element to delete
    int nod;
    printf("\nEnter the element to deleted:\n");
    scanf("%d", &nod);

    //checking if element to delete exists in the binary search tree
    p = head;
    int flag = 0;
    while (p != NULL)
    {
        if (nod == p->data)
        {
            flag = 1;
            break;
        }
        else if (nod < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if(flag != 1)
    {
        printf("Element to delete does not exist in the BST.\n");
        exit(0);
    }

    //calling delete_node function
    head = delnode(head, nod);

    //printing the updated binary search tree
    printf("These are the elements in the new BST:\n");
    p = head;
    while (p != NULL)
    {
        printf("%d \t", p->data);
        p = p->right;
    }
}