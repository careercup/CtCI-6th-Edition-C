#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct node *list_head = NULL;
struct node *stack_head = NULL;

void pop(struct node **stack_head, int *data)
{
	struct node *tmp = *stack_head;
	if (!tmp) {
		*data = -1;
		return;
	}

	*data = tmp->data;
	*stack_head = (*stack_head)->next;
	free(tmp);
}

void print_list(struct node **list_head)
{
	struct node *tmp;

	printf("printing the list: ");
	for (tmp = *list_head; tmp; tmp = tmp->next)
		printf("%d ", tmp->data);
	printf("\n");
}

void delete_list(struct node **list_head)
{
	struct node *tmp;

	while (*list_head) {
		tmp = *list_head;
		*list_head = (*list_head)->next;
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

bool is_palindrome(struct node **list_head)
{
	struct node *fast;
	struct node *slow;
	int top;

	for (fast = *list_head, slow = *list_head; fast && fast->next;
			fast = fast->next->next, slow = slow->next) {
		push(&stack_head, slow->data);
	}
	/* skip pushing the element in the middle. */
	if (fast)
		slow = slow->next;

	for (; slow; slow = slow->next) {
		pop(&stack_head, &top);
		if (top != slow->data)
			return false;
	}
	return true;
}

int main(void)
{
	push(&list_head, 1);
	push(&list_head, 2);
	push(&list_head, 3);
	push(&list_head, 4);
	push(&list_head, 3);
	push(&list_head, 2);
	push(&list_head, 1);
	// push(&list_head, 9); // FIXME: enable this line to test non-palindrome case.
	print_list(&list_head);

	printf("is palindrome: %s.\n", is_palindrome(&list_head) ? "yes" : "no");

	delete_list(&stack_head);
	delete_list(&list_head);

	return 0;
}

