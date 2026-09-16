#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//정수의 승격
#if 0
int main(void) {
	unsigned char a = 0xf0;
	char b = 0xf0;
	unsigned char c = 0x0f;
	char d = 0x0f;
	printf("%X %X %X %X\n", a==~c, a==~d, b==~c, b==~d);
	// a = 0x0000 00F0
	// b = 0xFFFF FFF0
	// c = 0x0000 000F ~c = 0xFFFF FFF0
	// d = 0x0000 000F ~d = 0xFFFF FFF0
}
#endif

#if 0
int main(void){
	int a = 5;
	int b = 10;
	b = a++ + b;
	printf("%d", b);
}
#endif

#if 0
static unsigned int isBitSet(unsigned int num, int bitPosition) {
	return (num >> bitPosition) & 1;
}
int main(void) {
	// 특정 비트가 1인지 0인지 확인
	int num, bitPosition;
	printf("Enter a number : ");
	scanf_s("%d", &num);
	
	printf("Enter bit position to check (0-31) : ");
	scanf_s("%d", &bitPosition);
	

	unsigned int res = isBitSet(num, bitPosition);
	printf("Bit %d of number %u is %u.\n", bitPosition, num, res);
}
#endif


#if 0
// 특정 비트를 설정 (set)
unsigned int setBit(unsigned int num, int bitPosition) {
	return num | (0b01 << bitPosition);

}

// 특정 비트를 해제 (clear)
unsigned int clearBit(unsigned int num, int bitPosition) {
	return num & ~(0b01 << bitPosition);
}

// 특정 비트를 반전 (toggle)
unsigned int toggleBit(unsigned int num, int bitPosition) {
	return num ^ (0b01 << bitPosition);
}
void printBinary(unsigned int num, int bits) {
	for (int i = bits - 1; i >= 0; i--) {
		putchar((num >> i) & 1 ? '1' : '0');
	}
}
int main(void) {
	unsigned int num = 0b1010;
	printf("Initial value: %X (binary : ", num);
	printBinary(num, 4);
	printf(")\n");

	num = setBit(num, 2);
	printf("After setting bit 2 : %X (binary: ", num, num);
	printBinary(num, 4);
	printf(")\n");

	num = clearBit(num, 1);
	printf("After setting bit 1 : %X (binary: ", num, num);
	printBinary(num, 4);
	printf(")\n");

	num = toggleBit(num, 3);
	printf("After setting bit 3 : %X (binary: ", num, num);
	printBinary(num, 4);
	printf(")\n");
}
#endif
#if 0
int main(void) {
	//산술 shift : 양수는 0, 음수는 shift Right 1 (Shift Left : 0,shift Right : 부호)
	//논리 shift : 패딩은 무조건 0
	int a = 0x7FFF0000;
	int b = 0777;
	int c = 0x9090F0F0;

	printf("%x %x\n", a >> 4, a << 4);
	printf("%o %o %o\n", b, b >> 3, b << 3);
	printf("%d %x %d %x\n", c , c , c >> 4, c << 4);
	return 0;
}
#endif

#if 0
int main(void) {
	int a = 10, b = 5;
	printf("%d\n", (a > b) ? 1 : 0);
	printf("%d\n", a > b);
	//컴파일러의 의해 1,2 번 동일
	return 0;
}
#endif
//short-circuit의 원리
#if 0
#include <stdio.h>

static int func1(void) {
	printf("func1() is called\n");
	return 0;
}

static int func2(void) {
	printf("func2() is called\n");
	return 1;
}

int main(void) {
	if (func1() && func2()) { // func1의 결과에 따라 func2 실행 안 될 수도 있음
		printf("Both functions returned true\n");
	}
	else {
		printf("At least one function returned false\n");
	}

	if (func2() || func1()) { // func2가 참이면 func1은 호출되지 않음
		printf("At least one function returned true\n");
	}
	else {
		printf("Both functions returned false\n");
	}

	return 0;
}
#endif

//++/--연습
#if 0
int main(void) {
	int a = 5, b = 5;
	int pre, post;
	pre = (++a) * 3;
	post = (++b) * 3;
	printf("a=%d, b=%d \n", a, b);
	printf("pre=%d, post=%d \n", pre, post);
}
#endif


//scanf 연습
#if 0
int main(void) {
	int a = 0;
	scanf_s("%d", &a);
	
	printf("a = %d \n", a);
	return 0;
}
#endif

//postfix ++/-- 이해
#if 0

int main(void) {
	char arr[10] = "Hello";
	char* p = arr; //arr은 상수 ps는 변수
	char ch = 0;
	printf("%p %c \n", p, ch);
	ch = *p++; //ch = *p; p = p+1
	printf("%p %c %s\n", p,ch,arr);
	ch = (*p)++; //ch = *p; *p=*p+1;
	printf("%p %c %s\n", p, ch,arr);
	ch = ++*p; //*p = *p+1; ch = *p
	printf("%p %c %s\n", p, ch, arr);
	return 0;
}
#endif
//문자열 scanf 연습
#if 0

//int scanf(const char* format,...);
//성공적으로 입력받아 저장한 항목의 개수를 반환합니다.
int main(void) {
	char arr[5] = { 0 };
	(void)scanf("%s", arr); //&arr (배열 포인터) 해도됨 알아서 char *로 형 변환됨
	//arr, &arr의 주소 값이 같아서 문제가 없었음

	printf("a = %s \n", arr);
	return 0;
}
#endif

//const char * from을 사용한 이유는 무엇일까?
//mystrcpy를 사용하는 사용자에게 from에는 read only 메모리의 주소를 사용해도 된다고 알려준 것이다
#if 0
char* mystrcpy(char* to, const char* from) {
	char* save = to;
	//from[0] = 'x';
	for(;*to=*from;++to, ++from)
	return save;
}
int main(void) {
	char a[10] = { 0 };
    char* b = "Hello";
	printf("a = %s \n", mystrcpy(a, "memory"));
	return 0;
}
#endif



//const의 이해 - const는 이름을 const로 만들어 준다.
#if 0
int main(void) {
	const int a = 100;
	int* p = (int*)&a;   
	*p = 150;

	printf("%d \n", a);   
	return 0;
}
#endif