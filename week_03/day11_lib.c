#include "day11_lib.h"

void print_1Darray(int* ary, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n\n");
}
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divi(int a, int b) {
    return a / b;
}
int mod(int a, int b) {
    return a % b;
}