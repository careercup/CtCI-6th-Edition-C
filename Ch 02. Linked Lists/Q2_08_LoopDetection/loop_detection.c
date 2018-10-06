#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

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
}

struct node * find_collision(struct node **head)
{
	struct node *slow = (*head)->next;
	struct node *fast = (*head)->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			break;
	}
	if (!fast || !fast->next)
		return NULL;

	slow = *head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

