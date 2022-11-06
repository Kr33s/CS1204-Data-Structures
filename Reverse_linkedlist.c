#include <stdio.h> //  Iterative program to reverse a linked list
#include <stdlib.h>

/* Link list node */
struct node {
	int data;
	struct node* link;
};

/* Function to reverse the linked list */
void reverselist(struct node** start)
{
	struct node* previous = NULL;
	struct node* current = *start;
	struct node* next = NULL;

	while (current != NULL) 
    {
		// Store next
		next = current->link;

		// Reverse current node's pointer
		current->link = previous;

		// Move pointers one position ahead.
		previous = current;
		current = next;
	}
	*start = previous;
}

// Function to add nodes
void add_nextnode(struct node** next, int new)
{
	struct node* proxy  = (struct node*)malloc(sizeof(struct node));
	proxy->data = new;
	proxy->link = (*next);
	(*next) = proxy;
}

/* Function to print linked list */
void printArray(struct node* head)
{
	struct node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
}

int main()
{
	struct node* head = NULL;

	add_nextnode(&head, 10);
    add_nextnode(&head, 11);
    add_nextnode(&head, 12);
    add_nextnode(&head, 13);
    add_nextnode(&head, 14);


	printf("Starting linked list\n");
	printArray(head);
	reverselist(&head);
	printf("\nReversed linked list \n");
	printArray(head);
	getchar();
}
