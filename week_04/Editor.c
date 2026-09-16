#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#if 0
typedef struct node {
    char c;
    struct node* prev, * next;
} node;

void init_CLL(node** head) {
    *head = (node*)calloc(1, sizeof(node));
    if (*head == NULL) {
        exit(0);
    }
    (*head)->next = *head;
    (*head)->prev = *head;
    return;
}
void Append_nodeCLL1(node* head, node* newnode) {

    newnode->prev = head->prev;
    newnode->next = head;
    head->prev->next = newnode;
    head->prev = newnode;
    return;
}
node* Create_node(char c) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode != NULL) {
        newnode->c = c;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    return newnode;
}
void InsertBetween(node* A, node* B, node* newnode) {
    newnode->prev = A;
    newnode->next = B;
    A->next = newnode;
    B->prev = newnode;
}

node* funP(node* cursor, char c) {
    node* n = Create_node(c);
    InsertBetween(cursor, cursor->next, n);
    return n;
}

// cursor 노드를 리스트에서 떼어내고 free, 새 cursor 반환
node* funB(node* cursor, node* dummy) {
    if (cursor == dummy) return cursor;   
    node* before = cursor->prev;
    cursor->prev->next = cursor->next;
    cursor->next->prev = cursor->prev;
    free(cursor);
    return before;
}

void Print_node(node *dummy) {
    static char out[600001] = { 0 };
    int k = 0;
    for (node* curr = dummy->next; curr != dummy; curr = curr->next)
        out[k++] = curr->c;
    out[k] = '\0';
    puts(out);
    return;
}

void FREE(node** head) {
    node* curr = (*head)->next;
    while (curr != *head) {
        node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(*head);
    *head = NULL;
}

char in[100001] = { 0 };

int main(void) {
 
    node* dummy = NULL;
    init_CLL(&dummy);
    printf("문자를 입력하세요 : ");
    (void)scanf("%s", in);
    for (int i = 0; in[i] != '\0'; ++i) {
        node* newnode = Create_node(in[i]);
        Append_nodeCLL1(dummy, newnode);
    }

    node* cursor = dummy->prev;   // 커서는 끝 = 마지막 노드의 오른쪽

    int n;
    printf("입력 받을 명령수를 입력하세요 : ");
    (void)scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char op;
        printf("입력 할 명령을 입력하세요 : ");
        (void)scanf(" %c", &op);       
        switch (op) {
        case 'L': 
            if (cursor != dummy) 
                cursor = cursor->prev; 
            break;
        case 'D': 
            if (cursor->next != dummy) 
                cursor = cursor->next;
            break;
        case 'B': cursor = funB(cursor, dummy); break;
        case 'P': {
            char c;
            (void)scanf(" %c", &c);
            cursor = funP(cursor, c);
            break;
        }
        }
    }
    Print_node(dummy);
    FREE(&dummy);
    return 0;
}
#endif