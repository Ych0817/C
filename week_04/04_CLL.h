#ifndef __04_CLL_H__
#define __04_CLL_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#endif
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

typedef struct data {
	int id;
	int score;

}data_t; //8바이트 짜리 구조체

typedef struct _nodeCLL {
    data_t data;
    struct _nodeCLL* next;
    struct _nodeCLL* prev;

}nodeCLL;
/*
void init_CLL(nodeCLL** head, nodeCLL** tail);
nodeCLL* Create_nodeCLL(data_t* data);
void Append_nodeCLL1(nodeCLL* tail, nodeCLL* newnode);
void Append_nodeCLL2(nodeCLL* tail, nodeCLL* newnode);
void InsertAfter_nodeCLL1(nodeCLL* head, nodeCLL* newnode);
void InsertAfter_nodeCLL2(nodeCLL* head, nodeCLL* newnode);
void InsertBetween(nodeCLL* A, nodeCLL* B, nodeCLL* newnode);
void Append_nodeCLL(nodeCLL* tail, nodeCLL* newnode);
void Print_nodeCLL(nodeCLL* head);
void Destroy_CLL(nodeCLL** head, nodeCLL** tail);
*/

