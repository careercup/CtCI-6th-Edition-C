#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list_array[1000];

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

void remove_dups(struct node **head)
{
	struct node *tmp = *head, *dup, *prev;

	memset(list_array, 0x0, sizeof(list_array));
	while (tmp) {
		if (list_array[tmp->data]) {
			printf("removing dup: %d...\n", tmp->data);
			dup = tmp;
			tmp = tmp->next;
			prev->next = tmp;
			free(dup);
		} else {
			list_array[tmp->data] = 1;
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

void remove_dups2(struct node **head)
{
	struct node *tmp = *head, *tmp2, *dup, *prev;

	while (tmp) {
		tmp2 = tmp->next;
		while (tmp2) {
			if (tmp2->data == tmp->data) {
				printf("removing dup: %d...\n", tmp2->data);
				dup = tmp2;
				tmp2 = tmp2->next;
				prev->next = tmp2;
				free(dup);
			} else {
				prev = tmp2;
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->next;
	}
}

int main(void)
{
	struct node *head = NULL;

	push(&head, 4);
	push(&head, 2);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 8);
	push(&head, 1);
	push(&head, 5);
	push(&head, 1);

	printf("list with dups: ");
	print_list(&head);

	//remove_dups(&head);
	remove_dups2(&head);
	printf("\n\nlist without dups: ");
	print_list(&head);

	delete_list(&head);

	return 0;
}

