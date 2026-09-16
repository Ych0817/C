#ifndef __04_DLL_H__
#define __04_DLL_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "02_SLL.h"

#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

typedef struct _nodeDLL {
	data_t data;
	struct _nodeDLL* next;
	struct _nodeDLL* prev;
}nodeDLL;

void init_DLLHT(nodeDLL** head, nodeDLL** tail);
nodeDLL* Create_nodeDLL(data_t* data);
void Append_nodeDLL1(nodeDLL* tail, nodeDLL* newnode);
void Append_nodeDLL2(nodeDLL* tail, nodeDLL* newnode);
void InsertAfter_nodeDLL1(nodeDLL* head, nodeDLL* newnode);
void InsertAfter_nodeDLL2(nodeDLL* head, nodeDLL* newnode);
void InsertBetweenDLL(nodeDLL* A, nodeDLL* B, nodeDLL* newnode);
void Append_nodeDLL(nodeDLL* tail, nodeDLL* newnode);
void Print_nodeDLL(nodeDLL* head, nodeDLL* tail);
void Destroy_DLL(nodeDLL** head, nodeDLL** tail);
#endif