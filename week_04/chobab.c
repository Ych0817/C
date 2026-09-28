#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#if 0
#define MAX_N (3000000 + 3000 + 2)   // 뒤에 k-1개를 더 복사하니까 k만큼 여유
#define MAX_D (3000 + 2)

int k, c, N, d;
int belt[MAX_N];
int sushi[MAX_D];      // sushi[x] = 지금 창 안에 x번 초밥이 몇 접시 있나
int max_kind;

void print_belt(int* arr, int start, int end) {   // 디버깅용
    for (int i = start; i <= end; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    (void)freopen("chobab.txt", "r", stdin);

    (void)scanf("%d %d %d %d", &N, &d, &k, &c);
    for (int i = 0; i < N; ++i) {
        (void)scanf("%d", &belt[i]);
    }

    // 원형 → 일자로 펴기: 앞의 k-1개를 뒤에 이어 붙임
    for (int i = 0; i < k - 1; ++i) {
        belt[N + i] = belt[i];
    }
    // print_belt(belt, 0, N + k - 2);

    // 0번부터 시작해 k개 먹은 초밥의 가짓수
    int cnt = 1;
    sushi[c] = 1;   // 쿠폰은 무조건 먹기 (가짓수 1개 미리 확보)

    for (int i = 0; i < k; i++) {
        if (sushi[belt[i]]++ == 0) cnt++;
    }
    max_kind = cnt; 

    //슬라이딩 윈도우 기법
    for (int i = 0; i < N - 1; i++) {
        // 왼쪽 끝 접시 빼기
        if (sushi[belt[i]]-- == 1) cnt--;
        // 오른쪽 새 접시 넣기
        if (sushi[belt[k + i]]++ == 0) cnt++;

        if (cnt > max_kind) max_kind = cnt;
    }
        
    printf("%d\n", max_kind);
    return 0;
}
#endif