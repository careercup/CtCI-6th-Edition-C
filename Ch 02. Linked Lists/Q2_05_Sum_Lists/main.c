#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct _Node {
	int				value;
	struct _Node	*next;
} Node;

static void printList(Node *G)
{
	for (Node *n = G; n; n = n->next) {
		if (n != G)
			printf(" ");

		printf("%i", n->value);
	}

	printf("\n");
}

static Node *sumLists(Node *a, Node *b, const int carry)
{
	if (NULL == a && NULL == b && 0 == carry)
		return NULL;

	int s = carry;
	Node *an = NULL;
	Node *bn = NULL;

	if (a) {
		s += a->value;
		an = a->next;
	}

	if (b) {
		s += b->value;
		bn = b->next;
	}

	Node *o = (Node*) malloc(sizeof(struct _Node));
	o->value = (s % 10);
	o->next = sumLists(an, bn, ((s - (s % 10)) / 10));

	return o;
}

int main(const int argc, const char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s [ INT, [ INT, ...] ] + [ INT, [ INT, ... ] ]\n", argv[0]);
		exit(1);
	}

	Node *a = NULL;		// first list
	Node *b = NULL;		// second list
	Node **t = &a;		// list to write to
	Node *p = NULL;		// last node in current list
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '+') {
			t = &b;
		} else {
			Node *n = (Node*) malloc(sizeof(Node));
			n->value = atoi(argv[i]);
			n->next = NULL;

			if (NULL == *t)
				*t = n;
			else
				p->next = n;

			p = n;
		}
	}

	Node *s = sumLists(a, b, 0);
	printList(s);
}
