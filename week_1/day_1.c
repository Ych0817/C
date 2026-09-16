#include <stdio.h>

#if 0
int main(void) {
    float num = 123456789.0F; //F는 4바이트 정수라는 뜻
    printf("점수 = %.1f \n", num);
    //123456792.0 float 유효숫자 7자리라서 7이후는 믿을 수 없음



    return 0;
}

#endif

//L-value, R-value 이해
#if 0
int main(void) {
    unsigned char a = -1;
    signed char b = -1;
    printf("%d %d \n", a, b);

    if (a > b) printf("a>b");
    else if (a < b) printf("a<b");
    else printf("a==b");

    return 0;
}

#endif

//한글 이름 사용
#if 0

int main(void) {

    float 점수 = 5.5;
    printf("a = %f \n", 점수);
    return 0;
}

#endif

//반올림 사용
#if 0

int main(void) {
    char b = '28';
    float a = 5.5;
    printf("a = %.0lf, b = %d \n", a, b);
    return 0;
}

#endif


//2 8 10 16 진수 출력
#if 0
void print_bin(unsigned int v) {
    int start = 31;
    while (start > 0 && !(v >> start & 1)) start--;

    for (int i = start; i >= 0; i--)
        putchar('0' + (v >> i & 1));
    putchar('\n');
}

int main(void) {
    int a = 13;
    print_bin(a);
    printf("%o %d %x %X\n", a, a, a, a);
    return 0;
}
#endif


//이름 출력
#if 0
int main(void) {
    printf("여창훈");
    return 0;
}
#endif
