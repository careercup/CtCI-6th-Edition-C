#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *intersection_node = NULL;

void print_list(struct node **head)
{
	struct node *tmp;

	for (tmp = *head; tmp; tmp = tmp->next)
		printf("%p: %d.\n", tmp, tmp->data);
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
	new_node->next = *head_ref;
	*head_ref = new_node;
	/* hack for creating an intersection node. */
	if (data == 4)
		intersection_node = new_node;
	else if (data == 6)
		(*head_ref)->next = intersection_node;
}

bool is_intersect(struct node **head1, struct node **head2)
{
	struct node *first  = *head1;
	struct node *second = *head2;
	unsigned int size1;
	unsigned int size2;
	unsigned int diff;

	/*
	 * we can keep the previous nodes and compare them.
	 * if they are different, then we can immediately return false here.
	 */
	for (size1 = 0; first;  size1++, first = first->next);
	for (size2 = 0; second; size2++, second = second->next);

	/* this part can be modularized. */
	if (size1 > size2) {
		diff = size1 - size2;
		first = *head1;
		while (diff > 0) {
			first = first->next;
			diff--;
		}

		second = *head2;
	} else {
		diff = size2 - size1;
		second = *head2;
		while (diff > 0) {
			second = second->next;
			diff--;
		}

		first = *head1;
	}

	while (first != second) {
		first  = first->next;
		second = second->next;
	}
	if (first && (first == second))
		return true;
	return false;
}

int main(void)
{
	push(&head1, 1);
	push(&head1, 2);
	push(&head1, 3);
	push(&head1, 4);
	push(&head1, 5);
	print_list(&head1);

	push(&head2, 6);
	print_list(&head2);

	printf("is intersect: %s.\n", is_intersect(&head1, &head2) ? "yes" : "no");

	delete_list(&head1);

	return 0;
}

