#include "04_CLL.h"

#if 0
void init_CLL(nodeCLL** head) {
	*head = (nodeCLL*)calloc(1, sizeof(nodeCLL));
	if (*head == NULL) {
		exit(0);
	}
	(*head)->next = *head;
	(*head)->prev = *head;
	return;
}
nodeCLL* Create_nodeCLL(data_t* data) {
	nodeCLL* newnode = NULL;
	newnode = (nodeCLL*)malloc(sizeof(nodeCLL));
	if (newnode != NULL) {
		newnode->data = *data;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	return newnode;
}

void Append_nodeCLL1(nodeCLL* head, nodeCLL* newnode) {
	/*
	newnode->prev = head;
	newnode->next = head->prev;
	head->prev->next = newnode;   // 반드시 head->prev 갱신 전에
	head->prev = newnode;
	*/

	newnode->prev = head->prev;
	newnode->next = head;
	head->prev->next = newnode;
	head->prev = newnode;

	return;
}

void Append_nodeCLL2(nodeCLL* tail, nodeCLL* newnode) {
	nodeCLL* prev = tail->prev;

	newnode->next = tail;
	newnode->prev = prev;
	tail->prev = newnode;
	prev->next = newnode;
}

void InsertAfter_nodeCLL1(nodeCLL* head, nodeCLL* newnode) {
	newnode->prev = head;
	newnode->next = head->next;
	head->next->prev = newnode;
	head->next = newnode;
	return;
}

void InsertAfter_nodeCLL2(nodeCLL* head, nodeCLL* newnode) {
	nodeCLL* next = head->next;

	newnode->prev = head;
	newnode->next = next;
	next->prev = newnode;
	head->next = newnode;
}

// A - newnode - B
void InsertBetween(nodeCLL* A, nodeCLL* B, nodeCLL* newnode) {
	newnode->prev = A;
	newnode->next = B;
	A->next = newnode;
	B->prev = newnode;
}
void Append_nodeCLL(nodeCLL* tail, nodeCLL* newnode) {
	InsertBetween(tail->prev, tail, newnode);
}

void Print_nodeCLL(nodeCLL* head) {
	for (nodeCLL* curr = head->next; curr != head; curr = curr->next)
		printf("%d %d\n", curr->data.id, curr->data.score);
	return;
}

void Destroy_CLL(nodeCLL** head) {
	nodeCLL* curr = (*head)->next;
	while (curr != *head) {
		nodeCLL* next = curr->next;
		free(curr);
		curr = next;
	}
	free(*head);
	*head = NULL;
}
//score가 동일한 노드 탐색
nodeCLL* Find_nodeCLL(nodeCLL* head, int score) {
	for (nodeCLL* curr = head->next; curr != head; curr = curr->next) {
		if (curr->data.score == score)
			return curr;
	}
	return NULL;
}
void Delete_nodeCLL(nodeCLL* curr) {
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(curr);
	curr = NULL;
}

int main(void) {
    nodeCLL* head = NULL;
    init_CLL(&head);

    data_t data = { 0 };
    int n;
    (void)freopen("data.txt", "r", stdin);
    (void)scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        nodeCLL* newnode = NULL;
        (void)scanf("%d %d", &data.id, &data.score);
        newnode = Create_nodeCLL(&data);
		Append_nodeCLL1(head, newnode);
    }
    Print_nodeCLL(head);
	nodeCLL* s = Find_nodeCLL(head, 88);
	if (s != NULL){
		printf("\n%d %d\n", s->data.id, s->data.score);
		Delete_nodeCLL(s);
		printf("\n");
		Print_nodeCLL(head);
	}
	else{
		printf("not found\n");}
	//s가 NULL이 아니면 s의 id를 출력, NULL이면 없다는 표시
	//Destroy_CLL(&head);

    return 0;
}
#endif