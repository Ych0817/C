#include "03_DLL.h"

#if 0
void init_DLLHT(nodeDLL** head, nodeDLL** tail) {
	*head = (nodeDLL*)calloc(1, sizeof(nodeDLL));
	if (*head == NULL) {
		exit(0);
	}
	*tail = (nodeDLL*)calloc(1, sizeof(nodeDLL));
	if (*tail == NULL) {
		free(*head);
		exit(0);
	}
	(*head)->next = *tail;  //  DLL
	(*tail)->prev = *head;
	return;
}

nodeDLL* Create_nodeDLL(data_t* data) {
	nodeDLL* newnode = NULL;
	newnode = (nodeDLL*)malloc(sizeof(nodeDLL));
	if (newnode != NULL) {
		newnode->data = *data;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	return newnode;
}

void Append_nodeDLL1(nodeDLL* tail, nodeDLL* newnode) {
	newnode->next = tail;
	newnode->prev = tail->prev;
	tail->prev->next = newnode;
	tail->prev = newnode;

	return;
}
void Append_nodeDLL2(nodeDLL* tail, nodeDLL* newnode) {
	nodeDLL* prev = tail->prev;
	newnode->next = tail;
	newnode->prev = prev;
	tail->prev = newnode;
	prev->next = newnode;
}

void InsertAfter_nodeDLL1(nodeDLL* head, nodeDLL* newnode) {
	newnode->prev = head;
	newnode->next = head->next;
	head->next->prev = newnode;
	head->next = newnode;
	return;
}

void InsertAfter_nodeDLL2(nodeDLL* head, nodeDLL* newnode) {
	nodeDLL* next = head->next;
	newnode->prev = head;
	newnode->next = next;
	next->prev = newnode;
	head->next = newnode;
}

// A - newnode - B
void InsertBetweenDLL(nodeDLL* A, nodeDLL* B, nodeDLL* newnode) {
	newnode->prev = A;
	newnode->next = B;
	A->next = newnode;
	B->prev = newnode;
}
void Append_nodeDLL(nodeDLL* tail, nodeDLL* newnode) {
	InsertBetweenDLL(tail->prev, tail, newnode);
}

void Print_nodeDLL(nodeDLL* head, nodeDLL* tail) {
	nodeDLL* curr = head->next;
	for (; curr != tail; curr = curr->next) {
		printf("%d %d\n", curr->data.id, curr->data.score);
	}
	return;
}

void Destroy_DLL(nodeDLL** head, nodeDLL** tail) {
	nodeDLL* curr = (*head)->next;
	while (curr != *tail) {
		nodeDLL* next = curr->next;
		free(curr);
		curr = next;
	}
	free(*head);
	free(*tail);
	*head = *tail = NULL;
}
int main(void) {
	nodeDLL* head = NULL;
	nodeDLL* tail = NULL;
	init_DLLHT(&head, &tail);

	data_t data = { 0 };
	int n;
	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		nodeDLL* newnode = NULL;
		(void)scanf("%d %d", &data.id, &data.score);
		newnode = Create_nodeDLL(&data);
		if (newnode == NULL) {
			Destroy_DLL(&head, &tail);
			head = NULL;
			exit(0);
		}
		InsertBetweenDLL(tail->prev, tail, newnode);
		//Append_nodeDLL(tail, newnode);
	}
	Print_nodeDLL(head, tail);
	Destroy_DLL(&head, &tail);
	return 0;
}
#endif