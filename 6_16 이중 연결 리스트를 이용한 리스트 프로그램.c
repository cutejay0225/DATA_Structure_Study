#include<stdio.h>
#include<stdlib.h>

//ÇÁ·Î±×·¥ 6.16
typedef int Element;
typedef struct DLinkedNode {
	Element data;
	struct DLinkNode* prev;
	struct DLinkNode* next;
} Node;
Node org;

void init_list() { org.next = NULL; }
Node* get_head() { return org.next; }
int is_empty() { return get_head() == NULL; }

Node* get_entry(int pos)
{
	Node* n = &org;
	int i = -1;
	for (i = -1; i < pos; i++, n = n->next)
		if (n == NULL) break;
	return n;
}

void replace(int pos, Element e) {
	Node* node = get_entry(pos);
	if (node != NULL)
		node->data = e;
}

int size() {
	Node* p;
	int count = 0;
	for (p = get_head(); p != NULL; p = p->next)
		count++;
	return count;

}
Node* find(Element e) {
	Node* p;
	for (p = get_head; p != NULL; p = p->next)
		if (p->data == e) return p;
	return NULL;
}
void print_list(char* msg) {
	Node* p;
	printf("%s[%2d]: ", msg, size());
	for (p = get_head(); p != NULL; p = p->next)
		printf("%2d ", p->data);
	printf("\n");
}

void insert_next(Node* p, Node* n) {
	n->prev = p;
	n->next = p->next;
	if (p->next != NULL) 
		p->next->prev = n;
	p->next = n;
}
void insert(int pos, Element e)
{
	Node* new_node, * prev;
	prev = get_entry(pos - 1);
}
