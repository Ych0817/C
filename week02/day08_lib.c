#include "day08_lib.h"
/*
주의할 점: 이 매크로는 배열 이름에만 통합니다. 
함수 안에서 int (*score)[4] 같은 포인터에 쓰면 sizeof(포인터)/sizeof(int[4]) = 8/16 = 0이 나옵니다. 
그래서 함수에 r, c를 따로 넘기는 것입니다.*/
#define SIZE(a) (sizeof(a) / sizeof((a)[0]))

void input2Darray(int(*score)[4],int r,int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			(void)scanf("%d", &score[i][j]);
		}
	}
}

void print2Darray(int(*score)[4], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%3d", score[i][j]);
		}
		printf("\n");
	}
}

void input1Darray(int *score, int r) {
	for (int j = 0; j < r; j++) {
			(void)scanf("%d", &score[j]);
	}
}
void input_string(char (*animal)[10], int n) // = animal[][10]
{
	for (int i = 0; i < n; i++)
		(void)scanf("%s", animal[i]);
}

void print_string(char (*animal)[10], int n) 
{
	for (int i = 0; i < n; i++)
		printf("%s\n", animal[i]);
}
void print_string02(char *animal[], int n) // = **animal
{
	for (int i = 0; i < n; i++)
		printf("%s\n", *(animal+i)); //= + animal[i] , *( +x) == [x]
	//[]를 전부 *( + ) 형태로 바꾼다
}