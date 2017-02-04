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

static Node *partition(Node *G, const int x)
{
	Node *L = NULL;			// left partition
	Node *hL = NULL;		// head of left partition
	Node *R = NULL;			// right partition
	Node *t = G;			// current node
	while(t) {
		Node *n = t->next;	// next node
		if (t->value < x) {
			if (NULL == hL)
				hL = t;

			t->next = L;
			L = t;
		} else {
			t->next = R;
			R = t;
		}

		t = n;
	}

	if (L)
		hL->next = R;
	else
		L = R;

	return L;
}

int main(const int argc, const char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: main X [ INT, [ INT, [ INT, ...] ] ]\n");
		exit(1);
	}

	const int x = atoi(argv[1]);

	Node *L = NULL;		// linked list using arg values
	Node *p = NULL;		// last linked list node
	for (int i = 2; i < argc; i++) {
		Node *n = (Node*) malloc(sizeof(Node));
		n->value = atoi(argv[i]);
		n->next = NULL;

		if (NULL == L)
			L = n;
		else
			p->next = n;

		p = n;
	}

	L = partition(L, x);
	printList(L);
}
