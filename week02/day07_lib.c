#include "day07_lib.h"

#if 1
char* mystrcpy(char* to, const char* from) {
    char* save = to;
    for (; *to = *from; ++to, ++from);
    return save;
}
#else
char* mystrcpy(char* to, const char* from) {
    char* save = to;
    while (*to++ = *from++);
    return save;
}
#endif

int mystrlen(const char* str) {
    char* s;
    if (str == 0) return 0;
    for (s = (char*)str; *s; ++s);
    return s - str;
}
// 같으면 0, a가 크면 양수, b가 크면 음수를 반환
// (unsigned char *)를 하는 이유는? 
// : 표준 strcmp는 각 문자를 unsigned char 값(0~255)으로 해석하여 비교하기 때문이다.
int mystrcmp(const char* a, const char* b) {
    while (*a == *b) {
        if (*a == '\0') return 0;
        ++a;
        ++b;
    }
    return *(unsigned char*)a - *(unsigned char*)b;
}
// 같으면 0, a가 크면 양수, b가 크면 음수를 반환
// 반복문, if ~ else, ? : 등 사용하지 않고 '식'으로 풀 것 - 비교 연산 사용해 보세요
int intcmp(const int* a, const int* b) {
    return 0;
}

#if 0
extern int a;
//extern int b;
void printInt(void) {
    printf("a = %d\n", a);
    //printf("b = %d\n", b);
}
#endif