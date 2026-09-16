#ifndef __DAY06_LIB_H__ //__DAY06_LIB_H__이게 디파인되있지않으면 실행하세요

#define __DAY06_LIB_H__ //디파인 되서 실행 따라서 또 실행안됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* ap, int* bp);

void   scanf_ary(int ary[], int size);
void   print_ary(int ary[], int size);
int    findmax_ary(int ary[], int size);
int    findmin_ary(int ary[], int size);
int    sum_ary(int ary[], int size);
double avg_ary(int ary[], int size);
int findmax_indax(int ary[], int size);
void find_min_max(int ary[], int size);
void sort_ary(int ary[], int size);
double var_ary(int ary[], int size);
void test08_3(void);
void test08_4(void);
char* to_upper(char* str);
void mygets(char* ary, int n);
#endif