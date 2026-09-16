#include "day13_lib.h"
#include <stdint.h>

#if 0
#define NDEBUG
#include <assert.h>

int main() {
	int x;

	printf("\nEnter an integer value: ");
	(void)scanf("%d", &x);

	assert(x >= 0);

	printf("You entered %d.", x);

	return(0);
}
#endif

#if 0
#define SOUND_DEVICE_TYPE 1

int main(void) {
#if !SOUND_DEVICE_TYPE
	printf("사운드 장치를 사용하지 않음\n");
#else
#error CODE 10 : Unknown Device!
#endif

	printf("사운드 모드 = %d\n", SOUND_DEVICE_TYPE);
}
#endif

#if 0
#define Assert(x) { \
    if((x) >= 4) printf("Range error : %s, %d\n", __FILE__, __LINE__);\
    }

int main(void) {
	int a[4] = { 10,20,30,40 };
	int i;

	for (i = 0; i <= 4; ++i) {
//#line 100
		Assert(i);
		printf("a[%d] = %d\n", i, a[i]);
	}
}
#endif
//매크로
#if 0
#define MUL1(x,y) x*y
#define SWAP(x,y); \
\temp = x; x = y; y=temp; //이스케이프 확인
int main(void) {
	int a = 100, b = 2, x = 200, y = 3;
	printf("%d %d %d\n", MUL1(2, 5), MUL1(a, b), MUL1(x, y));
	printf("%d\n", 300 / MUL1(2, 5)); //750
	printf("%d\n", 300 / 2 * 5); 
	printf("%d\n", 300 / (MUL1(2, 5))); //또는 #define MUL1(x,y) (x*y)
	printf("%d\n", 300 / (MUL1(2*4-2, 5-124+123))); // #define MUL1(x,y) ((x)*(y))
	int temp;
	printf("%d %d\n", a, b);
	SWAP(a, b);
	printf("%d %d\n", a, b);
	return 0;
}

#endif

#if 0
int main(void) {
	int a;
	int arr[5] = { 1,2,3,4,5 };
	a = (int)arr;
	printf("%d\n", ((int*)a)[2]);
	//arr[2] == *((int*)a +2) == ((int*)a)[2]
	return 0;
}
#endif
#if 0
typedef int (*FP)(int, int);
int func(int a, int b) {
	return a + b;
}

int main(void) {
	int a = (int)func;
	printf("%d\n", func(3, 4));
	int b = ((FP)a) (3, 4); //괄호를 해줘야 a가 함수 포인터 됨
	printf("%d\n", b);

	return 0;
}
#endif

#if 0
int func(int a, int b) {
	return a + b;
}
int main(void) {
	int a = (int)func;
	printf("%d\n", func(3, 4));
	int b = ((int(*)(int, int))(a)) (3,4); //괄호를 해줘야 a가 함수 포인터 됨
	printf("%d\n", b);

	return 0;
}
#endif

#if 0
typedef char C10ARR[10];
typedef  C10ARR *C10ARRP;
typedef int (*Fun_P)(C10ARRP, int);

int printAry(C10ARRP ary, int size) {
	for (int i = 0; i < size; i++) {
		printf("%s ", ary[i]);
	}
	printf("\n");
}

int main(void) {
	C10ARR fruit[] = {"apple", "melon", "cherry"};
	Fun_P fn = printAry;
	fn(fruit, sizeof(fruit) / sizeof(fruit[0]));
	return 0;
}

#endif
#if 0

int main(void) {

	int a;
	typedef int MYINT;
	MYINT b; // = int b;

	unsigned int c;
	typedef unsigned int UINT;
	UINT d; // = unsigned int d;

	int* p;
	typedef int* INTP;	
	INTP p2; // = int * p2

	int ary[5]; //int 5개 배열
	typedef int i5arr[5];
	i5arr x, y;

	int (*p)[5]; //int 5개 배열을 가리키는 포인터
	typedef int (*i5arrp)[5]; 
	typedef i5arrp* i5arrp; //위에랑 같음



	return 0;
}
#endif

#if 0

int main(void) {


	unsigned int a = 0x12345678;
	printf("%x\n", a);
	//printf("%p\n", &a.blue); //비트 필드 멤버는 주소를 가죠올 수 없음;
	//printf("%p\n", &b.blue);

	return 0;
}
#endif


#if 0
typedef struct IP {
	uint16_t version : 4; //uint16_t : 2바이트
	uint16_t IHL : 4;
	uint16_t TOS : 8;
	uint16_t TOtal;
	uint16_t Identification;
	uint16_t IP_Flags_x : 1;
	uint16_t IP_Flags_D : 1;
	uint16_t IP_Flags_M : 1;
	uint16_t Fragement_Offset : 13;
	uint16_t TTL;
	uint16_t Proticol;
	uint16_t Header_checksum;
	uint16_t source_address;
	uint16_t Destination_address;
	uint16_t IP_Option;
};
int main(void) {
	struct color1 IP = { };
	

	printf("%d %d\n", sizeof(a), sizeof(b));
	printf("%p %p\n", &a, &b);
	//printf("%p\n", &a.blue); //비트 필드 멤버는 주소를 가죠올 수 없음;
	//printf("%p\n", &b.blue);

	return 0;
}
#endif

#if 0 
//비트 빌드 구조체 특징 - 멤버가 주소를 가질 수 없음
typedef struct color1 {
	unsigned int blue : 8;
	unsigned int green : 8;
	unsigned int red : 8;
}; 

typedef struct color2 {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}; 

int main(void) {
	struct color1 a = { 0 };
	struct color1 b = { 0 };

	printf("%d %d\n", sizeof(a), sizeof(b));
	printf("%p %p\n", &a, &b);
	//printf("%p\n", &a.blue); //비트 필드 멤버는 주소를 가죠올 수 없음;
	//printf("%p\n", &b.blue);

	return 0;
}
#endif