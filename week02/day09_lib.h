#ifndef __DAY08_LIB_H__
#define __DAY08_LIB_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif

int sum1D(int* arr, int n);
int sum2D(int(*arr)[4], int rows, int cols);
int sum3D(int(*arr)[4], int rows, int cols);
void exchange0(int* a, int* b);
void exchange1();
void exchange2();
void exchange3();
void exchange4();
void exchange5();
void print_ary01(char** pary, int size);
void print_var_array(int** pary, int n);
void print_1Darray(int* ary, int n);
void print_1Darray_double(double* ary, int n);
void print2Darray09(int(*score)[3], int r, int c);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);
int mod(int a, int b);
void sort(int* ary, int n);

    