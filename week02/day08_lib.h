#ifndef __DAY08_LIB_H__
#define __DAY08_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
/*
식	타입	sizeof	결과
SIZE(score)	int[3][4] ÷ int[4]	48 / 16	3 (행 개수)
SIZE(score[0])	int[4] ÷ int	16 / 4	4 (열 개수)
*/
#endif

void input2Darray(int(*score)[4], int r, int c);
void print2Darray(int(*score)[4], int r, int c);
void input1Darray(int *score, int r);
void print_string(int animal[10], int n);
void input_string(int animal[10], int n);
void print_string02(int animal[10], int n);