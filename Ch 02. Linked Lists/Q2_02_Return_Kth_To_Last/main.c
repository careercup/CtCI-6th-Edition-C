#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

typedef struct _Node {
	const char		*value;
	struct _Node	*next;
} Node;

// iteratively resolve the kth last node in a linked list - O(n)
static Node *kthLast(Node *L, const int k)
{
	if (k < 1)
		return NULL;

	Node *n = L;	// runner node
	for (int i = 0; i < (k - 1); i++)
		if (NULL == (n = n->next))
			return NULL;

	Node *m = L;	// kth last node
	while(n->next) {
		n = n->next;
		m = m->next;
	}

	return m;
}

int main(const int argc, const char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "usage: main K [ TEXT, [ TEXT, [ TEXT, ...] ] ]\n");
		exit(1);
	}

	int k = atoi(argv[1]);

	Node *L = NULL;		// linked list using arg values
	Node *p = NULL;		// last linked list node
	for (int i = 2; i < argc; i++) {
		Node *n = (Node*) malloc(sizeof(Node));
		n->value = argv[i];
		n->next = NULL;

		if (NULL == L)
			L = n;
		else
			p->next = n;

		p = n;
	}

	Node *nk = kthLast(L, k);
	if (NULL == nk) {
		fprintf(stderr, "K is out of range\n");
		exit(1);
	}

	printf("%s\n", nk->value);
}
