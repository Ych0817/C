#ifndef __02_SLL_H__
#define __02_SLL_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif

typedef struct data {
	int id;
	int score;
	
}data_t; //8바이트 짜리 구조체

typedef struct _nodeSLL {
	data_t data;
	struct _nodeSLL* next; //자기 참조 구조체
}nodeSLL; //12바이트 
