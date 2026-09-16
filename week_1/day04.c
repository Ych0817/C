#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0
int main() {
	int num ;
	int count = 0;
	printf("숫자를 입력하세요(1~10000000).\n");
	scanf("%d", &num);
	while (num > 0) {
		num /= 10;
		count++;
	}
	printf("%d\n", count);
	return 0;
}
#endif
//암호 확인 프로그램 최적화

#if 0
//더 최적화
int main(void) {

	int pass = 0;
	int count = 3;
	char* msg[2] = { "관리자에게 문의하세요", "로그인성공" };
	do {
		printf("암호를 입력하세요.\n");
		scanf("%d", &pass);
		if (pass == 1357) break;
	} while (--count);

	printf("%s", msg[count != 0]);
}
//우리 조의 최적화
int main(void) {
	int num;
	int i = 3;
	char* msg[2] = { "로그인 성공!","관리자에게 문의하세요" };
	while (i--) {
		printf("암호를 입력하시오: ");
		(void)scanf("%d", &num);
		if (num == 1357) {
			i = 0;
			break;
		}
	}
	printf( "%s",msg[i*-1]);
	return 0;
}
#endif

//암호 확인 프로그램
#if 0
int main(void) {
	int num,set=0,total = 0;
	while (set < 3) {
			printf("암호를 입력하시오: ");
			scanf_s("%d", &num);
			if (num == 1357) { printf("로그인 성공!"); break; }
			else { set += 1; continue; }
	}
	if(set == 3) printf("관리자에게 문의하세요");
}
#endif

//양수의 덧셈
#if 0

int main(void) {
int num,total=0;
	while (1) {
		printf("정수를 입력하시오: ");
		scanf_s("%d", &num);
		if (num > 0) total += num;
		else if (num == 0) break;
	}
	printf("%d", total);
}

#endif





//배열이나 문자열 관련 함수를 사용하여 printf를 1회로 줄이는 프로그램 작성
#if 0
int main(void)
{
	char buf[2048];
	int len = 0;

	for (int i = 2; i <= 9; i++)
		for (int j = 1; j <= 9; ++j)
			len += sprintf(buf + len, "%d * %d = %d\n", i, j, i * j);

	printf("%s", buf);
	return 0;
}
#endif
//구구단 프로그램 작성
#if 0
int main(void)
{
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; ++j) {
			printf("%d * %d = %d\n", i, j,i*j);
		}
	}
}
#endif