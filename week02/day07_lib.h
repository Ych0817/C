#ifndef __DAY07_LIB_H__
#define __DAY07_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

char* mystrcpy(char* to, const char* from);
int mystrlen(const char* str);
int mystrcmp(const char* s1, const char* s2);
void printInt(void);
#endif