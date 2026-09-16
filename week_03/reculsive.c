#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
//int N =5;
static int cnt = 0;

#if 1
#define N 3
#define M 6

int data[10];

void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test05_1(int L, int start) {
	if (L > N) {
		printData(data, N);
		return;
	}

	for (int i = start; i <= M; i++) {
		data[L] = i;
		test05_1(L + 1, i + 1);
	}
}

int main(void) {
	test05_1(1, 1);
	return 0;
}
#endif
#if 0
/*두번째는 첫번째 보다 크고 세번째는 두번째 보다 큼
N : 3개 선택 1~6의 값 범위
1 2 3
1 2 4
1 2 5
1 2 6
1 3 4
1 3 5
1 3 6
1 4 5
1 4 6
1 5 6
2 3 4
2 3 5
2 3 6
. . .

*/
int main(void) {
	for (int i = 1; i <= 6; i++) {
		for (int j = i + 1; j <= 6; j++) {
			for (int k = j + 1; k <= 6; k++) {
				printf("%d %d %d\n", i, j, k);
			}
		}
	}
	return 0;
}
#endif

#if 0
//1 2 3 4 5중에 3개 뽑아서 나열 123 124 125이런식으로
static int used[10] = { 0 };
int data[10];
void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d	", data[i]);
	}
	printf("\n");
}

void test05_1(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

	for (int i = 1; i <= 5; i++) {
		if (used[i]) continue;
		used[i] = 1;
		data[L] = i;
		test05_1(L + 1);
		used[i] = 0;
	}
}
int main(void) {
	N = 3;
	test05_1(1);
	return 0;
}
#endif

#if 0
//1 2 3 4 5중에 3개 뽑아서 나열 123 124 125이런식으로
static int used[10] = { 0 };
int data[10];
void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d	", data[i]);
	}
	printf("\n");
}

void test05_1(int L) {
	if (L > N){
		printData(data, N);
		return;
	}
	
	for (int i = 1; i <= 5; i++) {
		if (used[i]) continue;
			used[i] = 1;
			data[L] = i;
			test05_1(L + 1);
			used[i] = 0;
	}
}
int main(void) {
	N = 3;
	test05_1(1);
	return 0;
}
#endif

#if 0
/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
static int used[10] = { 0 };
int data[10];
void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
void test05_1(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

for (int i = 1; i <= 3; i++) {
	if (used[i]) continue;
			used[i] = 1;
			data[L] = i;
			test05_1(L + 1);
			used[i] = 0;
		}
	
}
	
	/*
	if (used[1] == 0) {
			used[1] = 1;
			data[L] = 1;
			test05_1(L + 1);
			used[1] = 0;
	}
	if (used[2] == 0) {
			used[2] = 1;
			data[L] = 2;
			test05_1(L + 1);
			used[2] = 0;
	}
	if (used[3] == 0) {
			used[3] = 1;
			data[L] = 3;
			test05_1(L + 1);
			used[3] = 0;
	}*/
int main(void) {
	N = 3;
	test05_1(1);
	return 0;
}
#endif

#if 0
/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
int main(void) {
	int used[10] = { 0 };
	for (int i = 1; i <= 3; i++) {
		used[i] = 1;
		for (int j = 1; j <= 3; j++) {
			if (used[j]) continue;
			used[j] = 1;
			for (int k = 1; k <= 3; k++) {
				if (used[k]) continue;
				printf("%d %d %d\n", i, j, k);
			}
			used[j] = 0;   
		}
		used[i] = 0;      
	}
	return 0;
}
#endif

#if 0
/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/ 
int main(void) {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j<= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				if (i != j && j != k && i != k) {
					printf("%d %d %d \n", i, j, k);
				}

			}
		}
	}
	return 0;
}
#endif
#if 0
int data[10];

void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
void test05(int L) {
	if (L > N) 
	{
		printData(data, N);
		return;
	}
	for (int i = 1; i <= 3; i++) {

		for (int j = 1; i <= 3; j++) {
			for (int k = 1; k <= 3; k++) {

				if (i != j && j != k != k != i) {
					printf("%d %d %d", i, j, k);
					L + 1;
				}

			}
		}
	}
}

int main(void) {
	N = 3;
	test05(1);
	return 0;
}
#endif

#if 0
int data[10];

void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
void test04(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}
	for (int i =1 ;i<=6; i++){
		data[L] = i;
		test04(L + 1);
	
	}
}

int main(void) {
	N = 2;
	test04(1);
	return 0;
}
#endif

//111부터 444까지
#if 0
int data[10];

void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
void test03(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}
	data[L] = 1;
	test03(L + 1);
	data[L] = 2;
	test03(L + 1);
	data[L] = 3;
	test03(L + 1);
	data[L] = 4;
	test03(L + 1);
}

int main(void) {
	N = 3;
	test03(1);
	return 0;
}
#endif


//111 112 113 121 122 123 ... 333 출력
#if 0
int data[10];

void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
void test02(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}
	data[L] = 1;
	test02(L + 1);
	data[L] = 2;
	test02(L + 1);
	data[L] = 3;
	test02(L + 1);
}

int main(void) {
	N = 3;
	test02(1);
	return 0;
}
#endif

//000부터 111까지 출력
#if 0
int data[10];
void printData(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", data[i]);
	}
	printf("\n");
}
void test01(int L) {
	if (L > N) {
		printData(data, N);
			return;
	}
	data[L] = 0;
	test01(L + 1);
	data[L] = 1;
	test01(L + 1);
}
int main(void) {
	N = 3;
	test01(1);
}
#endif

#if 0
void func09(int L) {
	if (L > N) return;
	for (int i = 0; i < L; i++) printf("*");
	printf("\n");
	func09(L + 1);
}

void func09_1(int L, int k) {
	if (L > N) return;
	if (k == 0) {          
		printf("\n");
		func09_1(L + 1, L + 1);
		return;
	}
	printf("*");
	func09_1(L, k - 1);     
}
void func08_1(int L) {
	++cnt;
	printf("%d ", L);
	if (L >= N) return;
	func08_1(L + 1);
	printf("%d ", L);
}

//1 2 3 4 5 4 3 2 1출력 
void func08(int L) {
	++cnt;
	if (N < L) return;
	printf("%d ", L);
	func08(L + 1);
	if (L == 5) return; 
	printf("%d ", L);
}
//1 2 3 4 5 1 2 3 4 5 출력 
void func07(int L) {
	if (N < L) return;
	printf("%d ", L);
	func07(L + 1);
	printf("%d ", N - L + 1);
}

//1 2 3 4 5 5 4 3 2 1 출력 
void func05(int L) {
	if (N < L) return;
	printf("%d ", L);
	func05(L + 1);
	printf("%d ", L); 
}

//N이 5인 경우 5 4 3 2 1출력, func04(1)을 사용해서
void func04(int L) {
	if (N<L) return;
	printf("%d ", N+1-L); //L + 출력 = N +1 = 6
	func04(L+1);
}

//L을 이용하여 재귀호출의 종료 조건을 생성함
//L이 N보다 작거나 같은 경우 동작, L이 N보다 큰 경우 종료

//N이 5안 경우 1 2 3 4 5 출력
void func03(int L) {
	if (L > N) return;
	printf("%d ", L);
	func03(L + 1);
}

//3890번정도 
void func02(int L) {
	int arr[10] = { 0 };
	//static int arr[10] = { 0 }; //4757으로 돌아감 static을 사용하면 스택 사용 안함 데이터 영역 활용
	printf("%d %p\n", L,arr);
	func02(L + 1);
}

//4757번 정도
void func01(int L) {
	printf("%d\n", L);
	func01(L + 1);
}

//런타임 스택 오버플로우 발생
void func(void) {
	func();
}

int main(void) {
	func09_1(1);
	//printf("\n%d", cnt);
	return 0;
}
#endif