#include "day11_lib.h"

#if 0
int main(void) {
	int (*fp[5])(int, int) = { add,sub,mul,divi,mod };
	int (**fpp)(int, int) = (int(**)(int, int))malloc(5 * sizeof(*fpp));
	int (**fpp)(int, int) = fp;
}
#endif

#if 0
#define N_5 5

int main(void) {
	char** parr;
	char* s;  
	char* save = 0;
	int offset[N_5] = { 0 };

	s = malloc(N_5 * 80);
	if (s == NULL) return EXIT_FAILURE;
	save = s;

	parr = malloc(N_5*4);
	if (parr == NULL) return EXIT_FAILURE;

	for (int i = 0; i < N_5; ++i) {
		*(parr+i) = s;
		offset[i] = s -
		gets(s);
		//printf("%d ",strlen(parr[i])); //입력한거 길이
		s += strlen(s) + 1; //+1 == NULL
	}

	for (int i = 0; i < N_5; ++i)
		puts(parr[i],offset[i]);

	char* p = (char*)realloc(save, s - save);
	if (p == NULL) {
		exit(0);
	}
	//realloc을 하다가 주소가 변경된 경우
	if (save != p) {
		for (int i = 0; i < N_5; ++i)
			parr[i] = p + offset[i];
	}

	free(save); free(parr);
	s = NULL;
	parr = NULL;
	return 0;
}
#endif

#if 0
#define N_5 5

int main(void) {
	char *arr[N_5] = { 0 };
	char *s;          //각 문자열의 시작 오프셋

	s = malloc(N_5 * 80);
	char* save = s;
	if (s== NULL) return EXIT_FAILURE;

	for (int i = 0; i < N_5; ++i) {
		arr[i] = s;
		gets(s);
		s += strlen(arr[i]) + 1;
	}

	for (int i = 0; i < N_5; ++i)
		puts(arr[i]);

	free(save);
	save = NULL;
	return 0;
}
#endif

#if 0
//반장꺼
int main(void) {
	char* arr = (char*)malloc(5 * 80);
	if (arr == NULL) { exit(0); }
	char* pos = arr;
	for (int i = 0; i < 5; ++i) {
		gets(pos);
		pos += strlen(pos) + 1;
	}
	pos = arr;
	for (int i = 0; i < 5; ++i) {
		printf("%s\n", pos);
		pos += strlen(pos) + 1;
	}
	free(arr);
	arr = NULL;
	return 0;
}	
#endif

//최적화 오프셋
#if 0
#define N_5 5

int main(void) {
	char* arr[N_5] = { 0 };
	int offset[N_5];          //각 문자열의 시작 오프셋
	
	arr[0] = malloc(N_5 * 80);
	if (arr[0] == NULL) return EXIT_FAILURE;

	offset[0] = 0;
	gets(arr[0]);

	for (int i = 0; i < N_5 - 1; ++i) {
		offset[i + 1] = offset[i] + strlen(arr[i]) + 1;
		arr[i + 1] = arr[0] + offset[i + 1];
		gets(arr[i + 1]);
	}

	int used = offset[N_5 - 1] + strlen(arr[N_5 - 1]) + 1;

	char* p = realloc(arr[0], used);

	if (p != NULL) {                    //realloc이 성공했을 때만
		for (int i = 0; i < N_5; ++i)   // 주소가 바뀌었을 수 있으니 재계산 
			arr[i] = p + offset[i];
	}
	// realloc 실패해도 원본 블록은 유효하므로 arr 그대로 사용

	for (int i = 0; i < N_5; ++i)
		puts(arr[i]);

	free(arr[0]);
	arr[0] = NULL;
	return 0;
}
#endif

#if 0
int main(void) {
	char* arr[5] = { 0 };

	arr[0] = (char*)malloc(5 * 80);
	if (arr[0] == NULL)  exit(0);

	gets(arr[0]);

	for (int i = 0; i < 4; ++i) {
		arr[i + 1] = arr[i] + strlen(arr[i]) + 1;
		gets(arr[i + 1]);
	}

	char *p = realloc(arr[0], (arr[4] + strlen(arr[4]) + 1) - arr[0]);
	if (p == NULL) exit(0);
	arr[0] = p;

	for (int i = 0; i < 5; i++) {
		printf("%s\n", arr[i]);
	}

	free(arr[0]);
	arr[0] = 0;
	return 0;
}
#endif

//연속으로 문자열 받기
#if 0
int main(void) {
	char* arr[5] = { 0 };
	char temp[80] = { 0 };
	int pos = 0;
	
	arr[0] = (char*)malloc(5 * 80);
	if (arr[0] == NULL)  exit(0); 

	gets(arr[0]);

	arr[1] = arr[0] + strlen(arr[0]) + 1; //0x1000 + 5 + 1 => 0x1006
	gets(arr[1]);

	arr[2] = arr[1] + strlen(arr[1]) + 1; 
	gets(arr[2]);

	arr[3] = arr[2] + strlen(arr[2]) + 1;
	gets(arr[3]);

	arr[4] = arr[3] + strlen(arr[3]) + 1;
	gets(arr[4]);

	for (int i = 0; i < 5; i++) {
		printf("%s\n", arr[i]);
	}

	free(arr[0]);
	arr[0] = 0;
	return 0;
}
#endif
// 가변 배열
#if 0

int main(void) {
	char* arr[5] = { 0 };
	char temp[80] = { 0 };

	for (int i = 0; i < SIZE(arr); i++) {
		gets(temp);
		arr[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
		if (arr[i] == 0) exit(0);
		strcpy(arr[i], temp);
	}

	for (int i = 0; i < SIZE(arr); i++) {
		printf("%s\n", arr[i]);
	}

	for (int i = 0; i < SIZE(arr); i++) {
		free(arr[i]);
		arr[i] = NULL;
	}
	return 0;
}
#endif

//char 배열 만들기
#if 0
#define MAX (20)

int main(void) {

	char *str = NULL;
	str = (char *)malloc(20 * sizeof(*str));

	if (str == NULL) {
		exit(0);
	}
	(void)scanf("%s", str);
	printf("%s \n", str);
	printf("%d %d\n", strlen(str), sizeof("water")); //strlen은 5 널문자 포함X sizeof는 6

	free(str);
	str = NULL;

	return 0;
}

#endif
//2차원배열 만들기
#if 0
#define R (3)
#define C (4)

int main(void) {

	int(* arr)[4] = NULL;
	printf("%d\n", sizeof(*arr)); // 4 * 4 = 32
	arr = (int(*)[C])malloc(3 * sizeof(*arr));
	if (arr == NULL) {
		return -1;
		//exit(0);

	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
				arr[i][j] = i*4 +j +1 ;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			printf("%d ", arr[i][j]);
	}

	free(arr);
	arr = NULL;

	return 0;
}

#endif
//12개 int를 요소로 하는 int 배열 만들기
#if 0
int main(void) {
	int* arr;
	arr = (int*)malloc(12 * sizeof(*arr));
	if (arr == NULL) {
		return -1;
		//exit(0);
	
	}
	for (int i = 0; i < 12; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 12; i++)
		printf("%d\n", *(arr+i));
	free(arr);
	arr = NULL;
	
	return 0;
}

#endif
//메모리 동적 할당 - malloc(초기화 x), calloc(초기화 0), realloc(한번 할당받은 메모리 크기 확대,축소할때 사용)
#if 0

int main(void) {
	int* a = 0;
	int* b = 0;
	int* c = 0;
	a = (int*)malloc(800000*sizeof(*a));
	if (a == NULL) {
		return -1;
	}
	b = (int*)calloc(80, sizeof(*a));
	if (b == NULL) {
		return -1;
	}
	c = (int*)realloc(NULL, 80);
	if (c == NULL) {
		return -1;
	}
	printf("%p %p %p\n\n", a, b, c);
	printf("%zu %zu %zu\n\n", sizeof(a), sizeof(b), sizeof(c));
	print_1Darray(a,10);
	print_1Darray(b, 10);
	print_1Darray(c, 10);
	free(a); free(b); free(c);
	a = NULL;
	free(a);
	return 0;
}
#endif

//메모리 동적 할당 (전역 변수, 지역 변수 메모리)
#if 0
int arr[10000][20000] = { 0 };
int main(void) {
	//int arr[200][1000] = { 0 }; //됨
	printf("%.3fM\n", sizeof(arr)/1024/(double)1024);
	return 0;
}
#endif