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

void print_kth_to_last(struct node **head, unsigned int k)
{
	struct node *p1 = *head;
	struct node *p2 = *head;
	unsigned int i;

	if (!k) {
		printf("0 is not a valid index!\n");
		return;
	}

	for (i = 0; i < k; i++) {
		if (!p1) {
			printf("out of bounds: %d!\n", k);
			return;
		}
		p1 = p1->next;
	}

	while (p1) {
		p1 = p1->next;
		p2 = p2->next;
	}
	printf("%dth to last element: %d.\n", k, p2->data);
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

	print_kth_to_last(&head, 1);
	print_kth_to_last(&head, 5);
	print_kth_to_last(&head, 15);

	delete_list(&head);

	return 0;
}

