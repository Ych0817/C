#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

// 소들의 야구 (BinarySearch 사용) 강사님 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
// min ~ max
// min 이상의 값을 요구하는 것이기 때문에 min값이 없으면, min 보다 큰 것 
int binary_search_min(int* arr, int s, int e, int min) {
    int m = -1;
    int res = -1;   // min이나 min보다 큰 것이 없음
    while (s <= e) {
        m = (s + e) / 2;
        if (arr[m] == min) return m;
        if (arr[m] < min) {
            s = m + 1;
        }
        else {
            e = m - 1;
            res = m;
        }
    }
    return res;
}

// max 이하의 값을 요구하는 것이기 때문에 max값이 없으면, max 보다 작은 것 
int binary_search_max(int* arr, int s, int e, int max) {
    int m = -1;
    int res = -1;   // max나 max보다 작은 것이 없음
    while (s <= e) {
        m = (s + e) / 2;
        if (arr[m] == max) return m;
        if (arr[m] < max) {
            s = m + 1;
            res = m;
        }
        else {
            e = m - 1;
        }
    }
    return res;
}

int main(void) {
    int N;
    int cow[1000] = { 0 };
    int i;

    (void)scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        (void)scanf("%d", &cow[i]);
    }

    qsort(cow, N, sizeof(int), compare);

    int cnt = 0;
    int xy = 0;
    int idxmin, idxmax;
    for (int x = 0; x < N - 2; ++x) {
        for (int y = x + 1; y < N - 1; ++y) {
            xy = cow[y] - cow[x];
            idxmin = binary_search_min(cow, y + 1, N - 1, cow[y] + xy);
            if (idxmin < 0) break;
            idxmax = binary_search_max(cow, idxmin, N - 1, cow[y] + xy + xy);
            if (idxmax < 0) {
                //printf("%d %d\n", x, y);
                break;
            }
            cnt += (idxmax - idxmin + 1);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
#endif

//소들의 야구 메안에서
#if 0
int com(const void* a, const void* b)
{
    int ia = *(int*)a;
    int ib = *(int*)b;
    return (ia > ib) - (ia < ib);
}
int main(void)
{
    int n;
    int cnt = 0;
    (void)freopen("cow_baseball.txt", "r", stdin);
    (void)scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++){
        (void)scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), com);

    for (int i = 0; i < n - 2; ++i){
        for (int j = i + 1; j < n - 1; ++j){
            int d1 = arr[j] - arr[i];
            for (int k = j + 1; k < n; ++k){
                int d2 = arr[k] - arr[j];
                if (d2 < d1){
                    continue;
                }
                if (d2 > d1 * 2){
                    break;
                }
                cnt++;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}
#endif

//소들의 야구 함수로
#if 0
int N;
int pos[1000];

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}


int lower_bound(int arr[], int n, int target) {
    int left = 0, right = n;   
    while (left < right) {
        int mid = (left + right)/2;
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(int arr[], int n, int target) {
    int left = 0, right = n;   
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}


int main() {
    (void)freopen("cow_baseball.txt", "r", stdin);
    (void)scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        (void)scanf("%d", &pos[i]);
    }

    qsort(pos, N, sizeof(int), cmp);

    int answer = 0;

    for (int x = 0; x < N; x++) {
        for (int y = x + 1; y < N; y++) {
            int d = pos[y] - pos[x];
            int lo = pos[y] + d;
            int hi = pos[y] + 2 * d;
            answer += upper_bound(pos, N, hi) - lower_bound(pos, N, lo);
        }
    }

    printf("%d\n", answer);
    return 0;
}
#endif