#include "day08_lib.h"

//포인터 배열
#if 0
int main(void) {
	char* animal[5] = { "rabbit","tiger","elephant","dog","cat"};
	char** p = &animal;
	
	printf("%s\n", *p);
	print_string02(animal, SIZE(animal));
}
#endif

//char 2차원 배열
#if 0
int main(void) {
	char animal[5][10] = { 0 };
	(void)freopen("animal.txt", "r", stdin);
	input_string(animal, SIZE(animal));
	print_string(animal, SIZE(animal));
}
#endif


//배열 등가 포인터 연습
#if 0
int main(void) {
	int a [2][3][4] = { 0 };
	int(*b[3])[4] = { 0 };
	int* (*c[2])(int*) = { 0 };
	int* d[3][4] = { 0 };
	int(*(*e[5])(void))[4] = { 0 };

	int(*pa)[3][4];
	int(**pb)[4];
	int* (**pc)(int*);
	int*(*pd)[4];
	int(*(**pe)(void))[4];

}
#endif
//배열 등가 포인터 연습
#if 0
int main(void) {
	int a1[4]; 
	char ch_a[10];
	//요소의 타입 : int
	// 요소의 개수 : 4, a1 = &a1[0] 
	int* a2[4];
	//요소의 타입(이름하고 개수 빼면나옴) : int*
	//요소의 개수 : 4
	int a3[3][4];
	int a4[2][3][4];
	int (*a5[3])[4];

	int* p1 = a1;
	int** p2 = a2;
	int(* p3)[4] = a3;
	int(* p4)[3][4] = a4;
	int(** p5)[4] = a5;
	 
	printf("%zu\n", sizeof(ch_a));
	printf("%zu\n", sizeof(&ch_a));
	printf("a1(16) %zu\n", sizeof(a1));  // 16 = 4*4
	printf("a2(32) %zu\n", sizeof(a2));  // 32 = 8*4   (포인터 배열)
	printf("a3(48) %zu\n", sizeof(a3));  // 48 = 4*3*4
	printf("a4(96) %zu\n", sizeof(a4));  // 96 = 4*2*3*4
	printf("a5(24) %zu\n", sizeof(a5));  // 24 = 8*3   (포인터 배열)
	
	return 0;
}
#endif
//2차원 배열 입력,출력
#if 0
#define ARR_2D(func,arr) func(arr,SIZE(arr),SIZE(arr[0]))//매크로 함수

int main(void) {
	int score[3][4] = { 0 };
	int i, j;

	(void)freopen("scores.txt", "r", stdin);

	//input2Darray(score,SIZE(score),SIZE(score[0]));
	//print2Darray(score, SIZE(score), SIZE(score[0]));
	input1Darray(score, SIZE(score) * SIZE(score[0]));
	//ARR_2D(input2Darray, score);
	ARR_2D(print2Darray, score);
	
	
	return 0;
}
#endif