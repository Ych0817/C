#ifndef __DAY10_LIB_H__
#define __DAY010_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif

int sum_10(int x, int y);
int sub_10(int x, int y);
int mul_10(int x, int y);
int div_10(int x, int y);
int mod_10(int x, int y);

void print_menu(void);
void clear_stdin(void);