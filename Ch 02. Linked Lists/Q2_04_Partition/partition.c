#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

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
}

void partition(struct node **head, const int x)
{
	struct node *tmp, *left, *right;

	for (tmp = *head; tmp; tmp = tmp->next) {
		if (tmp->data < x) {
			tmp->next = left;
			left = tmp;
		} else {
			tmp->next = right;
			right = tmp;
		}
	}
}

int main(void)
{
	struct node *head = NULL;

	push(&head, 3);
	push(&head, 5);
	push(&head, 8);
	push(&head, 5);
	push(&head, 10);
	push(&head, 2);
	push(&head, 1);
	print_list(&head);

	partition(&head, 5);
	print_list(&head);

	delete_list(&head);

	return 0;
}

