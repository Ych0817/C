#include "day07_lib.h"

// strcpy, memcpy, memmove
#if 0
int main(void) {
	char fruit[30] = { 0 };
	char* dessert = "watermelon";
	//strcpy(fruit, dessert);
	printf("%d %d\n", sizeof(fruit), strlen(dessert) + 1);
	//memcpy(fruit, dessert, strlen(dessert) + 1);
	memmove(fruit, dessert, strlen(dessert) + 1);
	printf("%s\n", fruit);
	return 0;
}
#endif

// const 학습 
#if 0
int main(void) {
	char fruit[10] = "apple";
	const char* dessert = "banana";
	dessert = fruit;
	//dessert[0] = 'X';
	char* p = dessert;
	p[0] = 'Y';
	printf("%s %s %s\n", fruit, dessert, p);
	return 0;
}
#endif

#if 0

int main(void) {
	int x = 10;
	int y = 20;
	const int* a = &x;  // a라는 이름을 사용해 int 값을 변경하지 못함
	int const* b = &y;  // b라는 이름을 사용해 int 값을 변경하지 못함
	int* const c = &x;  // c라는 이름을 사용해 포인터 값을 변경하지 못함
	int const* const d = &y;  // d라는 이름을 사용해, int, 포인터 값을 모두 변경하지 못함

	//a[0] = 30;  // 불가능
	//*a = 40;    // 불가능
	a = &y;       // 가능
	//c = &y;     // 불가능
	*c = 30;      // 가능
	//d = &x;     // 불가능
	//*d = 40;    // 불가능
	return 0;
}
#endif


// 매크로 상수와 const의 차이점
// 매크로 상수 : 자료형 정보를 별도 사용하지 않음
// const : 일반 변수 선언과 동일함

#if 0
#define Pi 3.14
void constTest(void) {
	const int a = 3.14;  // double값(3.14)을 int 변수에 넣으려고 함
	int c;
	c = Pi + a + 5;      // int 변수 c에 double값을 넣으려고 함
	printf("%d\n", c);
}
int main(void) {
	constTest();
	return 0;
}
#endif

#if 0
int main(void) {
	char to[20];
	char* from = "banana";

	//printf("%s\n", mystrcpy(to, from));
	//printf("%d\n", mystrlen(from));
	printf("%d\n", mystrcmp("fox", "cat"));
	printf("%d\n", mystrcmp("cat", "cat"));
	printf("%d\n", mystrcmp("ant", "cat"));
	int a = 10, b = 20, c = 10;
	printf("%d\n", intcmp(&a, &b));
	printf("%d\n", intcmp(&a, &c));
	printf("%d\n", intcmp(&b, &c));
	return 0;
}
#endif

#if 0

int a = 10;
static int b = 20;  // 전역 static : 1개 파일 내부에서만 사용

int func(void) {
	static int a = 0;  // 지역 static : 1개 함수 내부에서만 사용

	return ++a;
}
int main(void) {
	printf("%d\n", a); // 10
	printInt();  // 10
	printf("%d\n", func()); // 1
	printf("%d\n", func()); // 2
	printf("%d\n", b);   // 20
	return 0;
}
#endif


// 2차원 배열
#if 0
#define S(a) sizeof(a)
int main(void) {
	int a[3][4] = { 0 };  //  32 -> 0x20, 96 -> 0x60
	int(*ap)[4] = a;
	printf("%p %p %p %p %p\n", &a, a, &a[0], a[0], &a[0][0]);
	printf("%p %p %p %p %p\n", &a + 1, a + 1, &a[0] + 1, a[0] + 1, &a[0][0] + 1);
	printf("%d %d %d %d %d\n", sizeof(&a), sizeof(a), sizeof(&a[0]),
		sizeof(a[0]), sizeof(&a[0][0]));
	printf("%p %p\n", ap, ap + 1);
	printf("%d %d %d\n", sizeof(ap), sizeof(*ap), sizeof(**ap));

	printf("%p %p %p %p %d\n", a, a + 1, *(a + 1), *(a + 1) + 2, *(*(a + 1) + 2));
	int(*p0)[3][8] = &a;
	int(*p1)[4] = a;  //  a는 a[0]를 가리키는 포인터, a[0]의 타입은?  int [4]
	int(*p2)[4] = a + 1;      // 포인터와 정수의 덧셈/뺄셈 연산은 타입을 변경하지 않음
	int* p3 = a[1]; //a[1] == *(a + 1);  a[0]는 a[0][0]를 가리키는 포인터, a[0][0]의 타입은? int
	int* p4 = *(a + 1) + 2;
	int p5 = a[1][2]; //a[1][2] == *(*(a + 1) + 2);

	int* b[5];  // 포인터 배열
	int** pb = b; //  b[0]를 가리키는 포인터, b[0]의 타입은? int *

	int(*arr[3])[2];  // 배열 포인터 배열
	int(**parr)[2] = arr; // arr[0]를 가리키는 포인터, arr[0]의 타입은? int (*) [2]

	int ary[2][3][4];
	int(*pary)[3][4] = ary;  // ary[0]를 가리키는 포인터, ary[0]의 타입은? int [3][4]
	int(*pary2)[4] = ary[0];  // ary[0][0]를 가리키는 포인터, ary[0][0]의 타입은? int [4]
	int* pary3 = ary[0][0];  // ary[0][0][0]를 가리키는 포인터, ary[0][0][0]의 타입은? int
	return 0;
}

#endif