#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* start = NULL;                         // (first) 
struct node* last = NULL;                         // (last) 
struct node* proxy;                              // temporary 

struct node* nextNode(int x) // create new node
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->link = NULL;
	return temp;
}

void swap(struct node* a, struct node* b);

void add_nodes(int n) // add node to the end of the list
{
	struct node* temp = nextNode(n); // create new node
    
	if (start == NULL) 
    { // if list is empty
		start = temp;
		last = temp;
	}
	else {
		last->link = temp; // add node to the end of the list
		last = temp;// update last node
	}
}

void print_data(struct node *head) // prints the data
{
    if (head == NULL) // check
    {
        printf("The list provided is empty"); 
    }
    struct node *pointer = NULL;
    pointer = head;
    while (pointer != NULL)
    {
        printf("%d ",pointer->data);
        pointer = pointer->link;
    }
}

void pLink() // print the link
{
    proxy = start;
    while(proxy->link != NULL)
    {
        printf("%d ", proxy->data);
        proxy = proxy->link;
    }
    printf("%d ", proxy->data);
}


void selection()
{
    struct node* i;
    i = start;

    while(i != NULL)
    {
        proxy = i->link; //proxy is the next node
        while(proxy != NULL)
        {
            if(i->data > proxy->data) // if the first node is greater than the second node
            {
                swap(i, proxy); // swap the nodes
            }
            proxy = proxy->link; // move to the next node
        }
        i = i->link;
    }
}

void swap(struct node *x, struct node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

int main()
{

	// Create linked list
	add_nodes(53292);
	add_nodes(85392);
	add_nodes(789);
	add_nodes(546);
	printf("\nBefore Sort \n");
	pLink();

	// Function call
	selection();
	printf("\nAfter Sort \n");
	pLink();
	return 0;
}
