#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct node *node_to_delete = NULL;

void print_list(struct node **head)
{
	struct node *tmp;

	for (tmp = (*head); tmp; tmp = tmp->next)
		printf("%d ", tmp->data);
	printf("\n");
}

void delete_list(struct node **head)
{
	struct node *tmp;

	while (*head) {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void push(struct node **head_ref, int data)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (!new_node) {
		printf("malloc() failed: %s!\n", strerror(errno));
		return;
	}

	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	/* this is a hack to mark a node. */
	if (data == 5)
		node_to_delete = new_node;
}

void delete_middle_node(struct node **node_to_delete)
{
	struct node *next;

	printf("deleting node whose value is 5...\n");
	next = (*node_to_delete)->next; 
	(*node_to_delete)->data = next->data;
	(*node_to_delete)->next = next->next;
	free(next);
}

int main(void)
{
	struct node *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	push(&head, 9);
	print_list(&head);

	delete_middle_node(&node_to_delete);
	print_list(&head);

	delete_list(&head);

	return 0;
}

