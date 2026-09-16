#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//checkPass 최적화
#if 0
void checkPass(int score) {
	/*
	char* res[3] = { 
		"합격입니다.\n감사합니다.\n", 
		"재시험보세요.\n감사합니다.\n", 
		"불합격입니다.\n감사합니다.\n" };

	printf("%s", score >= 70 ? res[0] : score >= 60 ? res[1] : res[2]);
	*/
	const char* res[] = {"불합격입니다.", "재시험보세요.", "합격입니다."};
	int idx = (score >= 70) + (score >= 60);
	printf("%s\n감사합니다.\n", res[idx]);
	printf("%s감사합니다.\n", res[score >= 70 ? 0 : score >= 60 ? 1 : 2]);
	//더 최적화 70넘는거 많을 때 뒤에 까지안하고 바로 나감
}

int main(void) 
{
	int num;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);
	checkPass(num);
}
#endif

//while,do-while 연습
#if 0
int main(void) {
	int num;
	printf("while_정수를 입력하시오: ");
	scanf_s("%d", &num);
	while (num > 10) {
		printf("10보다 큽니다. 다시 입력해주세요. \n");
		scanf_s("%d", &num);
	}
	printf("입력값: %d\n\n", num);

	
	do {
		printf("do-while_정수를 입력하시오: ");
		scanf_s("%d", &num);
		if (num > 10)
			printf("10보다 큽니다. 다시 입력해주세요.\n");
	} while (num > 10); 
	printf("입력값: %d\n\n", num);
		
		
	return 0;
}
#endif

//성적 프로그램 작성하기
#if 0
int main(void) {
	int score = 0;
	char msg1;
	char msg2;
	char msg3;
	char* grade = "FFFFFFDCBAA";

	printf("점수를 입력하시오(0~100): ");
	scanf_s("%d", &score);

	//if-else
	if (score >= 90) msg1 = 'A';
	else if (score >= 80) msg1 = 'B';
	else if (score >= 70) msg1 = 'C';
	else if (score >= 60) msg1 = 'D';
	else msg1 = 'F';
	

	//switch
	switch (score / 10)
	{
	case 10:
	case 9:
		msg2 = 'A';
		break;
	case 8:
		msg2 = 'B';
		break;
	case 7:
		msg2 = 'C';
		break;
	case 6:
		msg2 = 'D';
		break;
	default :
		msg2 = 'F';
	
	
	}
	
	//문자열
	msg3 = grade[score / 10];

	printf("1.if-else %c \n2.switch %c \n3.문자열 %c  \n", msg1, msg2, msg3);

}
#endif

//합격/불합격 판정
#if 0
int main(void) {
	int score = 0;
	char* msg;   

	printf("점수를 입력하시오(0~100): ");
	scanf_s("%d", &score);
	
	if (score >= 70)      msg = "합격입니다.";
	else if (score >= 60) msg = "재시험보세요.";
	else                  msg = "불합격입니다.";

	printf("%s \n감사합니다.\n", msg);

	return 0;
}
#endif

//배수 판단
#if 0
int main(void) {
	int a = 0;
	printf("정수를 입력하시오:");
	scanf_s("%d", &a);
	if (a % 2 == 0) {
		printf("2");
	}
	else if (a % 3 == 0) {
		printf("3");
	}
	else if (a % 5 == 0) {
		printf("5");
	}
	else if (a % 2 == 0 && a % 3 == 0) {
		printf("2");
	}
	else if (a % 3 == 0 && a % 5 == 0) {
		printf("3");
	}
	else {
		printf("0");
	}
}
#endif

//짝수 홀수 판단
#if 0
int main(void) {
	int a;
	char* msg[2] = { "짝수", "홀수" };

	printf("정수를 입력하시오:");
	scanf_s("%d", &a);

	printf("%s \n", msg[a%2]);

	if (a % 2 == 0) {
		printf("짝수입니다.");
	}
	else {
		printf("홀수입니다.");

	}
	(a % 2 == 0) ? printf("짝수입니다.") : printf("홀수입니다.");
	return 0;
}
#endif

//삼중연산자
#if 0
int main(void) {
	int a = 10;
	int b = 5;
	printf("%d", a > b ? a : b);
	return 0;
}
#endif