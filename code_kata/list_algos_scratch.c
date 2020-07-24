#include <stdio.h>

# define NUM_VALUES 5

char *values[] = { 'XXXX', '1234' };

struct ListNode;

typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List {
	int count;
	ListNode *first;
	ListNode *last;
} List;

List *List_create() {
	
	return calloc(1, sizeof(List));
}

void List_push(List * list, void * value) {

	ListNode *node = calloc(1, sizeof(ListNode));
	node->value = value;

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->count++;
}

List *create_words() {
	
	int i = 0;
	List *words = List_create();

	for (i=0; i<NUM_VALUES; i++) {
		List_push(words, values[i]);
	}

	return words;
}

int main() {
	
	List *words = create_words();
}





