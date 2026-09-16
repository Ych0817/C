#include "day06_lib.h"
#include "wrong_header.h"

//extern int a; //extern : 내가 저장소 저장할 건아니고 다른 저장소에 있는거 가져오기
// extern을 사용할 경우 변수 초기화를 하면 안됨(물리적으로 안된다는 것은 아니고 오류 방지)

void swap(int* ap, int* bp) {
	int temp;
	temp = *ap;
	*ap = *bp;
	* bp = temp;
}

//입력받는 함수 
void scanf_ary(int ary[], int size)
{
    printf("정수 %d개를 공백으로 구분해 입력하세요 : ", size);
    for (int i = 0; i < size; i++)
        (void)scanf("%d", &ary[i]); // = (void)scanf("%d", ary + 1)
}

//출력하는 함수 
void print_ary(int ary[], int size)
{
    for (int i = 0; i < size; i++) 
        printf("%d ", ary[i]);

    printf("\n");
}

//가장 큰 수를 찾아 반환하는 함수 
int findmax_ary(int ary[], int size)
{
    int max = ary[0];

    for (int i = 1; i < size; i++) {
        if (ary[i] > max){
            max = ary[i];
        }
    }
    return max;
}
int findmax_indax(int ary[], int size)
{
    int max = ary[0];
    int idx=0;
    for (int i = 1; i < size; i++){
        if (ary[i] > max){
            max = ary[i];
            idx = i;
        }
    }
    return idx;
}

//가장 작은 수를 찾아 반환하는 함수 
int findmin_ary(int ary[], int size)
{
    int min = ary[0];

    for (int i = 1; i < size; i++)
        if (ary[i] < min)
            min = ary[i];

    return min;
}
void find_min_max(int ary[], int size) {
    int min = ary[0];
    int max = ary[0];

    for (int i = 1; i < size; i++) {
        if (ary[i] < min)
        {
            min = ary[i];
        }
        else if (ary[i] > max)
        {
            max = ary[i];
        }
    }
    printf("최솟값 :%d 최댓값:%d\n", min, max);

}

//모든 값 더한 값을 반환하는 함수 
int sum_ary(int ary[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += ary[i];

    return sum;
}

//평균을 반환하는 함수
double avg_ary(int ary[], int size)
{
    return (double)sum_ary(ary, size) / size;
}

//편차 제곱의 평균
//편차 = (관찰값 - 평균)
double var_ary(int ary[], int size)
{
    double avg = avg_ary(ary, size);
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        double diff = ary[i] - avg;
        sum += diff * diff;
    }
    return sum / (size-1);
}

//표준편차 = 분산의 양의 제곱근
double std_ary(int ary[], int size) {

}

//선택 정렬 오름차순
void sort_ary(int ary[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        int minidx = i;

        // i번째 뒤에서 가장 작은 값의 위치를 찾기
        for (int j = i + 1; j < size; j++){
            if (ary[j] < ary[minidx]){
                minidx = j;}
        }

        // 가장 작은 값을 i번째 자리와 교환
        if (minidx != i) {
            int tmp = ary[i];
            ary[i] = ary[minidx];
            ary[minidx] = tmp;
        }
    }
}
/*
void sort_ary(int *ary, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (ary[i] > ary[j])
                swap(&ary[i], &ary[j]); // = swap(ary +i,ary +j)
        }
    }
}
*/

void test08_3(void) {
    char ch1, ch2;
    scanf("%c %c", &ch1, &ch2);
    printf("[%c %c]\n", ch1, ch2);
}
void test08_4(void) {
    int ch;
    ch = getchar();
    printf("입력한 문자 : ");
    putchar(ch);
    putchar('\n');
}


//getchar 함수를 사용하여 n글자 미만의 글자를 입력받는 함수를 작성한다.
// n 글자 이상의 글자를 입력해도 오류 없이 n-1개 글자를 입력 받는다.
void mygets_s(char* ary, int size) 
{
    int i = 0;
    int c;
    if (size <= 0) return ary;      /* 저장할 공간이 없으면 아무것도 하지 않음 */
    while (i < size - 1) {          /* 마지막 한 칸은 '\0' 자리로 남겨 둔다 */
        c = getchar();
        if (c == '\n' || c == EOF)  /* Enter 또는 입력 종료 */
            break;
        ary[i++] = (char)c;
    }
    ary[i] = '\0';                  /* 초기화되지 않은 배열이어도 문자열이 되도록 */
    /* 배열보다 입력이 길었다면 남은 글자를 버려 다음 입력에 영향을 주지 않게 한다 */
    if (i == size - 1)
        while ((c = getchar()) != '\n' && c != EOF);
    return ary;
}
    

// getchar 함수를 사용하여 n 글자 미만의 글자를 입력받는 함수를 작성한다.
// n 글자 이상의 글자를 입력해도 오류 없이 n - 1개 글자를 입력 받는다.
void mygets(char* ary, int n) {
    int i = 0;
    int ch;
    while (i < n - 1 && (ch = getchar()) != '\n') {
        ary[i] = (char)ch;
        i++;
    }
    ary[i] = '\0';
}

// str 배열의 내용 중 소문자('a' ~ 'z')를 대문자('A' ~ 'Z')로 수정하는 함수를 작성한다.
// str에 전달 받은 값 그대로 반환한다.
char* to_upper(char* str) {
    char* save = str;
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str -= ('a' - 'A');
        }
        str++;
    }
    return save;
}


