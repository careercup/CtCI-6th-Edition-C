#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct _Node {
	const char		*value;
	struct _Node	*next;
} Node;

static void printList(Node *L)
{
	for (Node *n = L; n; n = n->next) {
		if (n != L)
			printf(" ");

		printf("%s", n->value);
	}

	printf("\n");
}

#ifdef MERGE_SORT

// split L half way and return a pointer to the second half
static Node *splitList(Node *L)
{
	if (NULL == L->next)
		return NULL;

	int x = 0;
	Node *n = L;	// current node
	Node *m = L;	// half-way node
	Node *p = L;	// node before half-way node
	for (n = L; n; n = n->next){
		if (x) {
			p = m;
			m = m->next;
		}

		x =~ x;
	}

	p->next = NULL;
	return m;
}

// sort L using merge sort
static Node *mergeSortList(Node *L) {
	if (NULL == L->next)
		return L;

	Node *R = splitList(L);
	
	L = mergeSortList(L);
	R = mergeSortList(R);

	Node *r = NULL;		// root node in output
	Node *p = NULL;		// last node in output
	Node *n = NULL;		// next lowest node in (L, R)

	while(L || R) {
		n = L;
		if (NULL == L)
			n = R;
		else
			if (NULL != R && 0 < strcmp(L->value, R->value))
				n = R;

		if (L == n)
			L = L->next;
		else
			R = R->next;

		if (NULL == r)
			r = n;
		else
			p->next = n;

		p = n;
	}

	return r;
}

// remove duplications with no extra buffer (returns sorted) - O(n*log n)
static Node *dedupList(Node *L)
{
	Node *Ls = mergeSortList(L);
	Node *p = Ls;					// last unique node
	Node *n = p->next;				// current node
	while(n) {
		if (0 != strcmp(p->value, n->value)) {
			p->next = n;
			p = n;
		} else {
			p->next = NULL;
		}

		n = n->next;
	}

	return Ls;
}

#else

// remove duplicates with no extra buffer - O(n^2)
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

#endif

int main(const int argc, const char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: main [ TEXT, [ TEXT, [ TEXT, ...] ] ]\n");
		exit(1);
	}

	Node *L = NULL;		// linked list using arg values
	Node *p = NULL;		// last linked list node
	for (int i = 1; i < argc; i++) {
		Node *n = (Node*) malloc(sizeof(Node));
		n->value = argv[i];
		n->next = NULL;

		if (NULL == L)
			L = n;
		else
			p->next = n;

		p = n;
	}

	L = dedupList(L);
	printList(L);
}
