#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
} Node;


void push (Node** head_ref, int new_data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->number = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("the given node cannot be NULL\n");
		return;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->number = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *last = *head_ref; 

	new_node->number = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		printf(" %d\n", node->number);
		node = node->next;
	}
}

int main()
{
	Node *root = NULL;

	append(&root, 6);
	push(&root, 7);
	push(&root, 1);
	append(&root, 4);
	insertAfter(root->next, 8);

	printf("Created Linked List is: \n");
	printList(root);

	return 0;
}
