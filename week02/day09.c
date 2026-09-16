#include "day09_lib.h"



//오름차순, 내림차순 정렬
//정수 배열 정렬 -> 타입에 상관없는 배열 정렬
#if 0
void swap_03(void* a, void* b, int size) {
	char* temp = NULL;
	temp = malloc(size);
	memmove(temp, a, size);
}
int compint_02(void* a, void* b) {
	int ia = *(int*)a;
	int ib = *(int*)b;
	if (ia > ib) return 1;
	if (ia < ib) return -1;
	return 0;
}
int compstr_02(void* a, void* b) {
	char* ap = *(char**)a;
	char* bp = *(char**)b;
	return strcmp(ap, bp);
}

//모든 타입의 배열을 대상으로 정렬함
// base : 배열의 시작주소
// num : 배열의 요소 개수
// size : 1개의 요소의 개수

void mysort(void* base, int num, int size,int (*comp)(void*,void*)) {
	char* cbase = (char*)base;
	
	for (int i = 0; i < num-1; i++) {
		for (int j = i + 1; j < num; j++) {
			char* a = cbase + (i * size); //시작주소 cbase
			char* b = cbase + (j * size);
			if (comp(a,b) > 0) {
				swap_03(a,b, size);
			}
		}
	}
}
int main(void) {
	int ary[5] = { 4, 2, 5, 1, 3 };

	print_1Darray(ary, SIZE(ary));
	mysort(ary, SIZE(ary),sizeof(*ary),compint_02);
	print_1Darray(ary, SIZE(ary));

	char* animal[5] = { "tiger","cat","lion","dog","elephant" };

	print_ary01(ary, SIZE(animal[5]));
	mysort(ary, SIZE(animal), sizeof(animal), compstr_02);
	print_ary01(ary, SIZE(animal));
	return 0;
}
#endif

#if 0
void swap_03(void* a, void* b, int size) {
	char* temp = NULL;
	temp = malloc(size);
	memmove(temp, a, size);
}

void sort_int(int* ary, int num) {
	int s = num - 1;
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < num; j++) {
			if (ary[i] > ary[j]) {
				swap_03(ary+i,ary+j,sizeof(*ary));
			}
		}
	}
}
int main(void) {
	int ary[5] = { 4, 2, 5, 1, 3 };

	print_1Darray(ary, SIZE(ary));
	sort_int(ary, SIZE(ary));
	print_1Darray(ary, SIZE(ary));

	return 0;
}
#endif

//정수 배열 정렬
#if 0
void sort_int(int* ary, int num) {
	int s = num - 1;
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < num; j++) {
			if (ary[i] > ary[j]) {
				int temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}
int main(void) {
	int ary[5] = { 4, 2, 5, 1, 3 };

	print_1Darray(ary, SIZE(ary));
	sort_int(ary, SIZE(ary));
	print_1Darray(ary, SIZE(ary));

	return 0;
}
#endif


//3차 - 사용자에게 어떤 연산을 할지에 대해 선택을 받고 동작 결과를 출력
/*메뉴 출력->사용자가 메뉴 번호 선택->결과 출력->메뉴 출력 ...
1. 더하기
2. 빼기
3. 곱하기
4. 나누기

연산 변호를 입력하시오 : 1
결과는 20 + 5 = 25 입니다.

*/
//오름차순 내림차순
#if 0
void swap_02(void* ap, void* bp, int size) {
	void* temp = NULL;
	temp = malloc(size);
	memmove(temp, ap, size);
	memmove(ap, bp, size);
	memmove(bp, temp, size);
	free(temp);
}

int compint01(const void* a, const void* b) {
	int ia = *(int*)a;
	int ib = *(int*)b;
	if (ia == ib) return 0;
	if (ia > ib) return 1;
	return -1;
}
// 정렬 - 함수포인터활용 (강사 버전) 내 버전은 sort
void sort01(void* base, int num, int size) {
	char* cbase = (char*)base;
	void* a;
	void* b;
	int s = num - 1;
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < num; j++) {
			a = cbase + i * size;
			b = cbase + j * size;
			if (compint01(a, b) > 0) {
				swap_02(a, b, size);
			}
		}
	}
}
int main(void) {
	int ary[5] = { 4,2,5,1,3 };
	print_1Darray(ary, SIZE(ary));
	//sort(ary, SIZE(ary));
	sort01(ary, SIZE(ary),sizeof(*ary));
	print_1Darray(ary, SIZE(ary));
}
#endif

#if 0
#define ARR_MAX 5

typedef struct op {
	int result;
	char* name;
	int (*func)(int, int);
}op_t;

int main(void) {
	int a = 20, b = 5;
	op_t data[] = {
		{0,"sum",add},
		{0,"sub",sub},
		{0,"mul",mul},
		{0,"divi",divi},
		{0,"mod",mod},
	};


	int tot = 0;

	for (int i = 0; i < SIZE(data); i++) {
		data[i].result = data[i].func(a, b);
		tot += data[i].result;
		printf("%s = %d\n", data[i].name, data[i].result); //참고 : C 입출력은 다 문자열 숫자친다고 숫자아님
	}
	printf("tot = %d\n", tot);

	return 0;
}
#endif
//2차 - 구조체로 변경함
#if 0
#define ARR_MAX 5

typedef struct op {
	char* name;
	int (*func)(int, int);
}op_t;

int main(void) {
	int a = 20, b = 5;
	op_t data[] = {
		{"sum",add},
		{"sub",sub},
		{"mul",mul},
		{"divi",divi},
		{"mod",mod},
	};
	op_t* op = NULL;

	
	int result,tot = 0;

	for (int i = 0; i < SIZE(data); i++) {
		op = &data[i];
		result = op->func(a, b);
		tot += result;
		printf("%s = %d\n", op->name,result); //참고 : C 입출력은 다 문자열 숫자친다고 숫자아님
	}
	printf("tot = %d\n", tot);

	return 0;
}
#endif

//1차 배열구조로 변경함
#if 0
#define ARR_MAX 5
int main(void) {
	int a = 20, b = 5;
	int result[ARR_MAX];
	int res_1, res_2, res_3, res_4, res_5;
	int tot = 0;
	char* str[ARR_MAX] = { "sum","sub","mul","divi","mod" };
	int (*func[ARR_MAX])(int, int) = { add,sub,mul,divi,mod };

	for (int i = 0; i < SIZE(result); i++) {
		result[i] = func[i](a, b);
		tot += result[i];
		printf("%s = %d\n", str[i], result[i]); //참고 : C 입출력은 다 문자열 숫자친다고 숫자아님
	}
	printf("tot = %d\n", tot);
	
	return 0;
}
#endif

//수정전 노최적화
#if 0
int main(void) {
	int a = 20, b = 5;
	int res_1, res_2, res_3, res_4, res_5;
	int tot = 0;
	res_1 = add(a, b);
	res_2 = sub(a, b);
	res_3 = mul(a, b);
	res_4 = divi(a, b);
	res_5 = mod(a, b);
	tot = res_1 + res_2 + res_3 + res_4 + res_5;

	printf("sum = %d\n", res_1);
	printf("sub = %d\n", res_2);
	printf("mul = %d\n", res_3);
	printf("divi = %d\n", res_4);
	printf("mod = %d\n", res_5);
	printf("tot = %d\n", tot);

	return 0;
}
#endif

//qsort 연습
#if 0
/*
void qsort(
	void* base, //배열의 시작주소
	size_t num, //배열 요소의 개수
	size_t size, //1개 요소의 크기
	int (*compare)(const void*, const void*) //비교 함수 ( a == b : 0, a > b :양수, a < b :음수)반환
);
*/
int compint(const void* a, const void* b) {
	int ia = *(int*)a;
	int ib = *(int*)b;
	/*if (ia == ib) return 0;
	if (ia > ib) return 1;
	return -1;
	*/
	return (ia > ib) - (ia < ib);
}
int compstr(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

int compdouble(const void* a, const void* b) {
	double ia = *(double*)a;
	double ib = *(double*)b;
	return (ia > ib) - (ia < ib);
}
/*
int comp2D(const void* a, const void* b) {
	int ia = *(int*)a;
	int ib = *(int*)b;
	return (ia > ib) - (ia < ib);
}
*/
/*
int comp2D(const void* a, const void* b) {
	int const(*rowA)[3] = (const int(*)[3])a;
	int const (*rowB)[3] = (const int(*)[3])b;

	/*
	for (int i = 0; i < 3; ++i) {
		if ((*rowA)[i] > (*rowB)[i]) {
			return 1;
		}
		if ((*rowA)[i] < (*rowB)[i]) {
			return -1;
		}
	}
	return 0;
	
	for (int i = 0; i < 3; ++i) { 
		int b = ((*rowA)[i] > (*rowB)[i]) - ((*rowA)[i] > (*rowB)[i]);
	}
	return b;

}
*/

int comp2D(const void *a, const void *b) {
	int const* ra = (const int*) a;
	int const  *rb = (const int*) b;

	for (int i = 0; i < 3; ++i) {
		if (ra[i] != rb[i]) return (ra[i] > rb[i]) - (ra[i] < rb[i]);
	}
	return 0;
}
int main(void) {

	int A[10] = { 5,2,8,1,9,10,4,6,7,3 };
	char* animal[5] = { "tiger","cat","lion","dog","elephant" };
	double B[5] = { 2.3, 2.1, 2.6, 2.7, 2.4 };
	int C[5][3] = 
	{ 
		{3,5,1},
		{1,4,3},
		{7,1,5},
		{3,2,2},
		{5,3,4}
	};

	print_ary01(animal, SIZE(animal));
	qsort(animal, SIZE(animal), sizeof(*animal),compstr);
	print_ary01(animal, SIZE(animal));

	print_1Darray(A, SIZE(A));
	qsort(A, SIZE(A), sizeof(A[0]), compint);
	print_1Darray(A, SIZE(A));

	print_1Darray_double(B, SIZE(B));
	qsort(B, SIZE(B), sizeof(B[0]), compdouble);
	print_1Darray_double(B, SIZE(B));

	print2Darray09(C, SIZE(C), SIZE(C[0]));
	qsort(C, SIZE(C), sizeof(C[0]), comp2D);
	print2Darray09(C, SIZE(C), SIZE(C[0]));


	return 0;
}
#endif

//함수 포인터 사용
#if 0

int main(void)
{
	int a=10 , b=2;
	int (*func)(int, int);
	func = add;
	printf("%d\n", func(a, b));
	return 0;
}
#endif

//함수 포인터 = 상수
#if 0
int add(int a, int b) {
	return a + b;
}
int main(void)
{
	//함수 포인터 변수
	int (*p)(int, int) = add;

	printf("%p %p %p %p\n", add, *add, **add, &add); //함수의 이름은 함수포인터가 끝
	printf("%d %d\n", add(10, 20), p(10, 20));
}
#endif


//배열 등가 포인터의 이해
#if 0
int main(void)
{
	int ary1[] = { 4,1,2,3,4 };
	int ary2[] = { 3,1,2,3 };
	int ary3[] = { 6,1,2,3,4,5,6 };
	int* pary[3] = { ary1, ary2, ary3 };
	print_var_array(pary, SIZE(pary));
}

#endif

#if 0
int main(void)
{

	char* pary[5] = { "dog", "elephant", "horse", "tiger", "lion" };
	print_ary01(pary, SIZE(pary));
	return 0;
}

#endif

#if 0
int main(void) {
	int a = 10, b = 5;
	int* ap = &a, * bp = &b;
	int** app = &ap, ** bpp = &bp;
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	exchange0(&a, &b);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	exchange1(&ap, &bp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	exchange2(&app, &bpp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	exchange3(&ap, &bp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	exchange4(&app, &bpp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	exchange5(&app, &bpp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	return 0;
	
}
#endif

//2중 포인터 연습
#if 0
int main(void) {
	int a = 10;
	int* ap = &a;
	int** b = &ap;
	printf("%d %d %d", a, *ap, **b);
}
#endif


//2차원 배열에서의 &,sizeof
#if 0
int main(void) {
	int A[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int B[2][3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };
	int sum = 0;
	printf("%p %p %p %p %p\n", &A, A, &A[0], A[0], &A[0][0]);//0x1000
	printf("%p %p %p %p %p\n", &A+1, A+1, &A[0]+1, A[0]+1, &A[0][0]); //A+1, &A[0]+1 둘이 똑같음 그 타입에 도달하는 경로만 다름
	                                  //0x1030 0x1010 0x1010 0x1004 0x1004
	printf("%zu %zu %zu %zu %zu %zu\n",
	sizeof(&A), sizeof(A), sizeof(&A[0]), sizeof(A[0]), sizeof(&A[0][0]), sizeof(A[0][0]));//4 48 4 16 4 4

	sum = sum3D(B,2, 3, 4);
	printf("%d\n", sum);

	sum = sum2D(A, 3, 4);
	printf("%d\n", sum);

	sum = 0;
	for (int i = 0; i < 3; i++)
		sum += sum1D(A[i], 4);
	printf("%d\n", sum);

	return 0;
}
#endif

//1차원 배열에서의 &,sizeof
#if 0
int main(void) {
	int iary[5] = { 1,2,3,4,5 };

	printf("%p %p %p\n", &iary, iary, &iary[0]);
	printf("%p %p %p\n", &iary+1, iary+1, &iary[0]+1);
	printf("%zu %zu\n", sizeof(& iary), sizeof(iary));

	char cary[10] = "rabbit";
	printf("%p %p %p\n", &cary, cary, &cary[0]);
	printf("%p %p %p\n", &cary+1, cary+1, &cary[0]+1);
	printf("%zu %zu\n", sizeof(&cary), sizeof(cary));
	printf("%zu %zu\n", sizeof(&"rabbit"), sizeof("rabbit"));//&"rabbit" = 배열 포인터
	char (*p)[7] = &"rabbit";
	printf("%p\n", p);
	printf("%c\n", *(*p + 4)); // = p[0][4] , (*p)[4]
	//p[0][4] = 'j'; //오류
	return 0;
}
#endif