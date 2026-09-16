#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#if 0
int main(void) {
	int a = 10;
	int* p = NULL;
	p = &a;
	*p = 20;

	printf("%d %d\n", a, *p);
	return 0;
}
#endif











//char 배열의 선언, 초기화
#if 0
int main(void) {
	char str1[80] = "applejam"; //나머지는 \0로 채움
	char str2[80];
	char ch;

	strcpy(str2, str1);
	printf("%s %s\n", str1, str2);

	(void)scanf("%s", str2); 
	//입력의 끝을 Enter, Tab, space bar를 입력시 Enter, Tab, space bar를 입력하지 않고 입력이 종료됨
	printf("%s\n", str2);

	gets(str2); //Enter를 입력시 Enter까지 입력 받고 종료됨
	puts(str2); //문자열을 출력 후 줄 변경('\n'이 기본 출력됨)
	printf("%d ,%s\n",strlen(str2), str2);

	(void)scanf("%c", &ch); //1개 문자를 입력받음(줄변경
	printf("%c\n", ch);
	(void)scanf("%c", &ch);
	printf("%c\n", ch);
	return 0;



	return 0;
}
#endif 

#if 0
//40 50 70 80 90
#define SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

//배열과 함수는 파라매터로 못넘어감
void inputData(int* score, int n) {
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &score[i]);
	}
}

totalData(int *x,int n) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += x[i];
	}
	return total;
}

void printData(int * score, int n) {
	for ( int i = 0; i < n; i++) {
		printf("%d \n", score[i]);
	}
	printf("\n");
}



int main(void) {
	int score[5] = { 0 };
	int total = 0;
	double avg;

	inputData(score, SIZE(score));
	total = totalData(score, SIZE(score));
	printData(score, SIZE(score));

	
	/*
	for (int i = 0; i < SIZE(score); i++) {
		scanf_s("%d", &score[i]);
		total += score[i];
	}
	avg = total / SIZE(score);
	for (int i = 0; i < SIZE(score); i++) {
		printf("점수는 %d \n", score[i]);
	}
	printf("합계는 %d, 평균은 %lf \n", total, avg);
	*/
}

#endif

#if 0
//type은 이름 빼고 다 설명
//int arr[10] -  int[10]
//자료형은 이름과 *를 제외한 나머지
//int *ary[5] - a의 자료형 int [3] , a의 type int* [5]

int main(void) {
	int ary[5] = { 1,2,3,4,5 };
	printf("%p \n", ary); //1000
	printf("%p\n", ary + 2); //1008 ary + sizeof(int*)*2
	printf("%d\n", ary[2]); //3  //*(ary + 2)
	return 0;
}
#endif








// "1234" char 포인터 상수
// a : char 포인터 변수
// b : 배열
#if 1
int main(void) {
	char* a = "1234";
	char b[] = "1234";
	char ch = 'X';

	// a의 연산
	//%p : 주소값 출력 (주소의 종류는 상관없음)
	//%s : char * 사용, 주소에가서 char를 꺼내 출력하는 동작을 연속으로 진행하며, '\0'을 만났을 때 종료
	printf("%p %p \n","1234", a); //둘이 주소 똑같음
	printf("%s %s \n","1234", a); //1234 1234
	printf("%p %p \n", &a, &a+1); 
	//a가 할당 받은 스택 주소, 2중 포인터(포인터의 주소), +1 -> +8
	printf("%p %p \n", &"1234", &"1234" + 1);
	//"1234"가 할당 받은 rodata의 주소, char (*)[5] - 배열 포인터, +1 -> +5
	printf("%c %c\n", *a,*"1234"); 
	//a에 저장된 주소에 접근해서 char값을 읽어 printf에 전달
	ch = *a; //*a를 읽어 ch변수에 저장 : read 동작
	//*a = 'A'; //*a에 'A'를 저장 : *a에 write 동작 못함
	a = b; //a에 배열의 주소를 저장(b : 스택 메모리를 사용하는 char 배열, b = &b[0])
	*a = 'A'; //A234

	printf("%c %c %c %c %c\n", ch, *a, b[0],*b,b[0]); // a = b라고 했기 때문에 a는 b배열처럼 사용할 수 있음

	printf("%p %p\n", a, a + 1); //a는 char* 변수, a+1:a가 가리키는 것의 크기만큼 1개 더하기
	printf("%p %p\n", &a, &a + 1); //&a는 char** 상수,&a + 1 : &a가 가리키는 것(char*)의 크기만큼 1개 더하기
	printf("%p %p\n", b, b + 1); //b는 char* 상수, b+1:b가 가리키는 것의 크기만큼 1개 더하기
	printf("%p %p\n",&b, &b + 1); //&b는 char** 상수,&b + 1 : &b가 가리키는 것(char*)의 크기만큼 1개 더하기
	char* p = &b[4];
	printf("%d\n", p-a); // 4 : p와 a 사이에 존재하는 요소의 개수
	

	// b[] = {'A','2','3','4',\0};
	// b는 포인터 상수이며 배열이다.
	printf("%p %c\n", b, *b);// *b : A
	printf("%p %td\n", b + 1, p - b); // p - b : 4
	// b = p; 배열의 이름은 포인터 '상수' 이기 때문에 l-value로 사용할 수 없음
	//&,sizeof 연산자와 함께 사용할 때 '배열'로 동작함
	printf("%p %p %p\n", b, &b, &b + 1); //&b는 char(*)[5] 상수, 배열 포인터
	printf("%zu %zu %zu %zu", sizeof(a), sizeof(b), sizeof(&b), sizeof(*&b));
	//8(포인터) 5(배열) 8(포인터) 5(배열)(*&는 상쇄됨)

}
#endif