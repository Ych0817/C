#include "day09_lib.h"


int sum1D(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int sum2D(int(*arr)[4], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
    return sum;
}
int sum3D(int(*arr)[3][4], int a, int b, int c) {
    int sum = 0;
    for (int i = 0; i < a; ++i) {
        sum += sum2D(arr[i], b, c);
    }
    return sum;
}

// main에 위치한 a, b 변수의 주소를 전달 받아
// a, b값을 교환하는 함수
void exchange0(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ap, bp 변수의 주소를 전달 받아 a, b값을 교환하는 함수
void exchange1(int** a, int** b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}


// app, bpp 변수의 주소를 전달 받아 a, b값을 교환하는 함수
void exchange2(int*** a, int*** b) {
    int temp = ***a;
    ***a = ***b;
    ***b = temp;
}


// ap, bp 변수의 주소를 전달 받아 ap, bp값을 교환하는 함수
void exchange3(int** a, int** b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}


// app, bpp 변수의 주소를 전달 받아 ap, bp값을 교환하는 함수
void exchange4(int*** a, int*** b) {
    int* temp = **a;
    **a = **b;
    **b = temp;
}


// app, bpp 변수의 주소를 전달 받아 app, bpp값을 교환하는 함수
void exchange5(int*** a, int*** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}


void print_ary01(char** pary, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", pary[i]);
    }
    printf("\n");
}

void print_var_array(int **pary, int n) {
    for (int i = 0; i < n; i++) {
        print_1Darray(pary[i]+1, pary[i][0]); //출력할 1차원 배열의 첫주소 , 출력할 요소수
    }
}

void print_1Darray(int* ary, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n\n");
}

void print_1Darray_double(double* ary, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", ary[i]);
    }
    printf("\n\n");
}
void print2Darray09(int(*score)[3], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d", score[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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


//정렬 - 함수포인터활용
void sort(int* ary, int n)
{
    int tmp;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (ary[i] > ary[j]) {
                memmove(&tmp, &ary[i], sizeof(int)); //&tmp에&ary[i]을 sizeof(int)만큼 복사
                memmove(&ary[i], &ary[j], sizeof(int));
                memmove(&ary[j], &tmp, sizeof(int));
            }
        }
    }
}