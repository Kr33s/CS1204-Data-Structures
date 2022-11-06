#include <stdio.h>;
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link
};

void main()
{   
    //Getting size of linked list
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //Getting first element of the liked list
    int head;
    printf("Enter the first element in the linked list: ");
    scanf("%d", &head);

    struct Node *N;
    N = (struct Node *) malloc(sizeof(struct Node));
    N->data = head;
    N->link = NULL;

    //Head and pointers
    struct Node *h1, *p;
    h1 = N;
    p = h1;

    //loop to input next nodes from user
    for(int i = 1; i<n; ++i)
    {
        printf("Enter the next element in the linked list: ");
        scanf("%d", &head);

        N = (struct Node *) malloc(sizeof(struct Node));
        N->data = head;
        N->link = NULL;

        //linking the notes
        p->link = N;

        //jumping to the current node
        p = p->link;
    }

    //displaying to the linked list
    p = h1;
    printf("These are the elements in the linked list:\n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }

    //printing first half of the linked list using Floyd's cycle detection algorithm
    p = h1;
    struct Node *q = h1;
    while(q != NULL && q->link != NULL)
    {
        p = p->link;
        q = (q->link) ? q->link->link : NULL;
    }
    printf("\nElements in the first half of the linked list:\n");
    while(h1 != p)
    {
        printf("%d \t", h1->data);
        h1 = h1->link;
    }
}