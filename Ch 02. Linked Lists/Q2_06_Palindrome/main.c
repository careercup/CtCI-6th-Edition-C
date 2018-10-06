#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct _Node {
	const char		*value;
	struct _Node	*next;
} Node;

// return a copy of a list in reverse order - O(n)
static Node *reverseCopyList(Node *L)
{
	Node *p = NULL;
	Node *t = NULL;
	Node *t2 = NULL;

	for(t = L; t; t = t->next) {
		t2 = (Node*) malloc(sizeof(struct _Node));
		t2->value = t->value;
		t2->next = p;
		p = t2;
	}

	return t2;
}

// return non-zero if two lists are equal in value and order - O(n)
static int compareLists(Node *a, Node *b)
{
	while(a && b) {
		if(0 != strcmp(a->value, b->value))
			return 0;

		a = a->next;
		b = b->next;
	}

	return !(a || b);
}

// return non-zero if a list is equal when read from left or from right - O(n)
static int isPalindrome(Node *L)
{
	Node *Lr = reverseCopyList(L);
	return compareLists(L, Lr);
}

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

	int res = isPalindrome(L);
	printf("%s\n", res ? "True" : "False");
}
