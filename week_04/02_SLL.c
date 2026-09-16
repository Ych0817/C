#include "02_SLL.h"

//head가 heap 메모리를 할당받은 구조체의 포인터인 경우 (dummy 있으며 heap 사용)
#if 0
nodeSLL* Create_nodeSLL(const data_t* data) {
	nodeSLL* newnode = (nodeSLL*)calloc(1, sizeof(nodeSLL));
	newnode->data = *data;
	return newnode;
}

void Append_nodeSLL(nodeSLL* head, nodeSLL* newnode) {
	nodeSLL* curr = head;
	for (; curr->next != NULL; curr = curr->next);
	curr->next = newnode;
}

void Print_nodeSLL(const nodeSLL* head) {
	for (const nodeSLL* curr = head; curr != NULL; curr = curr->next)
		printf("%d %d\n", curr->data.id, curr->data.score);
}

void Destroy_nodeSLL(nodeSLL* head) {
	nodeSLL* curr = head;
	while (curr != NULL) {
		nodeSLL* next = curr->next;
		free(curr);
		curr = next;
	}
}

int main(void) {
	nodeSLL* head = (nodeSLL*)calloc(1, sizeof(nodeSLL));  
	data_t data = { 0 };
	int n;

	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		(void)scanf("%d %d", &data.id, &data.score);
		Append_nodeSLL(head, Create_nodeSLL(&data));
	}
	Print_nodeSLL(head->next);   
	Destroy_nodeSLL(head);     
	head = NULL;
	return 0;
}
#endif

//head가 main에서 생성된 구조체 변수인 경우 (dummy 있으며 스택 사용)
#if 0
nodeSLL* Create_nodeSLL(data_t* data) {
	nodeSLL* newnode = NULL;
	newnode = (nodeSLL*)calloc(1, sizeof(nodeSLL));
	if (newnode != NULL)
		newnode->data = *data;
	return newnode;
}

void Append_nodeSLL(nodeSLL* head, nodeSLL* newnode) {
	nodeSLL* curr = head;
	for (; curr->next != NULL; curr = curr->next);
	curr->next = newnode;
	return;
}

void Print_nodeSLL(nodeSLL* head) {
	nodeSLL* curr = head;
	for (; curr != NULL; curr = curr->next) 
		printf("%d %d\n", curr->data.id, curr->data.score);
	
	return;
}

int main(void) {
	nodeSLL head = { 0 };
	data_t data = { 0 };
	int n;
	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		nodeSLL* newnode = NULL;
		(void)scanf("%d %d", &data.id, &data.score);
		newnode = Create_nodeSLL(&data);

		if (newnode != NULL) {
			Append_nodeSLL(&head, newnode);
		}
	}
		Print_nodeSLL(head.next); //&head 하면 출력할때 head->next 부터 대입
		return 0;
	
}
#endif

//head가 첫 번째 노드를 가리키는 포인터인 경우 (dummy 없음)
#if 0
nodeSLL* Create_nodeSLL(data_t *data) {
	nodeSLL* newnode = NULL;
	newnode = (nodeSLL * )calloc(1, sizeof(nodeSLL));
	if (newnode != NULL)
		newnode -> data = *data;
	return newnode;
}

void Append_nodeSLL(nodeSLL** head, nodeSLL* newnode) {
	if (*head == NULL) {
		*head = newnode;
		return;
	}
#if 0
	nodeSLL* curr;
	for (curr = *head; curr->next != NULL; curr = curr->next);
	curr->next = newnode;
	printf("%d ", curr->data.id);
#else
	nodeSLL* curr = *head;
	while (curr->next != NULL) curr = curr->next;
	curr->next =newnode;   
#endif
	return;
}

int main(void) {
	nodeSLL* head = NULL;
	data_t data = { 0 };
	int n;
	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		nodeSLL* newnode = NULL;
		(void)scanf("%d %d", &data.id, &data.score);
		newnode = Create_nodeSLL(&data);
		if (newnode != NULL) {
			Append_nodeSLL(&head, newnode);
		}
	}
	return 0;
}
#endif