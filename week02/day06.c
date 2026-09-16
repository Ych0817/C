#include "day06_lib.h"
#include "wrong_header.h"
//int a = 100; // 다른 파일과 공유해서 사용할 수 있는 전역변수 선언 방법


// mygets 함수 작성
#if 0

int main(void) {
	char ary[10];

	mygets(ary, SIZE(ary));
	printf("%s\n", ary);
	printf("%s\n", to_upper(ary));
	return 0;
}

#endif

#if 0
int main(void) {
	char ary[10];

	mygets(ary, SIZE(ary));
	printf("%s\n", ary);
	printf("%s\n", to_upper(ary));
	return 0;
}
#endif


//배열 1번 문제 풀이
#if 0
int main(void) {
	char ch[10];
	for (int i = 0; i < 10; i++)
		(void)scanf("%c", &ch[i]);

	for (int i = 9; i >= 0; i--)
		printf("%c", ch[i]);
}
#endif


#if 0
int main(void) {
	//test08_3();
	test08_4();
	return 0;
}
#endif
//배열 등가 포인터 연습
#if 0
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

int main(void) {
	//freopen("array01.txt", "r", stdin);
	int ary[5] = { 0 };
	scanf_ary(ary, SIZE(ary));
	print_ary(ary, SIZE(ary));
	printf("최댓값 : %d\n", findmax_ary(ary, SIZE(ary)));
	printf("최댓값idx : %d\n", findmax_indax(ary, SIZE(ary)));
	printf("최솟값 : %d\n", findmin_ary(ary, SIZE(ary)));
	find_min_max(ary, SIZE(ary));
	printf("합계   : %d\n", sum_ary(ary, SIZE(ary)));
	printf("평균   : %.2f\n", avg_ary(ary, SIZE(ary)));
	printf("표본분산   : %.4f\n", var_ary(ary, SIZE(ary)));

	sort_ary(ary, SIZE(ary));
	printf("정렬 결과  : ");
	print_ary(ary, SIZE(ary));
	return 0;
}
#endif
//swap함수 사용
#if 0
int main(void) {
	int a = 20, b = 10; //a : 지역변수
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d", a, b);
}
#endif
//전역 변수 a를 사용하는 코드
#if 0
int main(void) {
	a = 100;
	printf("%d", a);
	return 0;
}
#endif