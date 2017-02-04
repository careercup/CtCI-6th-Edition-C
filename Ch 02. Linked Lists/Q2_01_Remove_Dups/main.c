#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct _Node {
	const char		*value;
	struct _Node	*next;
} Node;

static Node *dedupList(Node *L)
{
	for (Node *n = L; n; n = n->next) {
		for (Node *m = n; m; m = m->next) {
			Node *g = m->next;
			while(g && 0 == strcmp(g->value, n->value))
				g = g->next;

			m->next = g;
		}
	}

	return L;
}

static void printList(Node *L)
{
	for (Node *n = L; n; n = n->next) {
		if (n != L)
			printf(" ");
		printf("%s", n->value);
	}

	printf("\n");
}

int main(const int argc, const char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: main [ TEXT, [ TEXT, [ TEXT, ...] ] ]\n");
		exit(1);
	}

	Node *L = NULL;
	Node *p = NULL;
	for (int i = 1; i < argc; i++) {
		Node *n = (Node*) malloc(sizeof(Node));
		n->value = argv[i];
		n->next = NULL;

		if (NULL == L)
			L = n;

		if (NULL != p)
			p->next = n;

		p = n;
	}

	L = dedupList(L);
	printList(L);
}