#include<stdlib.h>
#include<stdio.h>
#include<math.h>
struct node
{
    int data;
    struct node* linkNext;
};  
    
typedef struct node Node; //To type less.

void printLinkedlist(Node* head)
{
    Node* temp = head; 
    while(temp != NULL)
    { 
        printf((temp==head)?"%d":"->%d", temp->data); 
        temp = temp->linkNext; 
    }
    printf("  NULL"); 
}

void addLast(Node **headAddress, int input)
{
    Node *newNode = malloc(sizeof(Node)); 
    newNode->data = input; 
    newNode->linkNext = NULL;
    if(*headAddress == NULL)
        {
            *headAddress= newNode; //if the head is null, the new node is the head.
        }
    else 
        {
            Node *lastNode = *headAddress; 
            while(lastNode -> linkNext != NULL)
            { 
                lastNode = lastNode -> linkNext;
            }
            lastNode -> linkNext = newNode; 
        }
}

void insertionsortlinklist(Node **headAddress) 
{
    Node *currentNode= malloc(sizeof(Node)); 
    Node *next;
    Node *temp; 
    while((*headAddress)==NULL) 
    {
        next=(*headAddress)->linkNext; 
        while(temp->linkNext->data<(*headAddress)->data && temp->linkNext)
        {
            temp=temp->linkNext;
        }  
        // swap the data of the current node and the min node
        (*headAddress)->linkNext=temp->linkNext;
    }
}
    
int main()
{
    Node *head= NULL;         
    int lengthList;
    int point = 0;
    do
    {
        printf("Length of list: ");
        scanf("%d", &lengthList);
        if(lengthList<=0)
        {
            printf("Please input a +ve integer \n");
            point=1; 
        }
        else
        {
            point=0;
        }
    }
    while(point == 1);
    int i = 0;
    while(i<lengthList)
    {
        int value;
        printf("Enter the value of the node %d:", i+1);
        scanf("%d", &value);
        addLast(&head, value); //adds the value to the end of the list
        i++;
    }
        printLinkedlist(head); 
        printf("\n");
        insertionsortlinklist(&head); 
        printLinkedlist(head); 
        return 0;
}