#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#define MAXN 25

#if 0
int n;
char g[MAXN][MAXN + 2];       /* 문자열 + '\0' 여유 */
int qy[MAXN * MAXN], qx[MAXN * MAXN];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int cmp(void* a, void* b)
{
    return (*(int*)a) - (*(int*)b);
}

int bfs(int sy, int sx)
{
    int head = 0, tail = 0, cnt = 0;

    g[sy][sx] = '0';                      /* 방문 처리 */
    qy[tail] = sy; qx[tail] = sx; tail++;

    while (head < tail) {
        int y = qy[head], x = qx[head];
        int d;
        head++;
        cnt++;

        for (d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (g[ny][nx] != '1') continue;

            g[ny][nx] = '0';              /* 큐에 넣을 때 바로 방문 처리 */
            qy[tail] = ny; qx[tail] = nx; tail++;
        }
    }
    return cnt;
}

int main(void)
{
    int i, j, total = 0;
    int sizes[MAXN * MAXN];
    (void)freopen("House_number.txt", "r", stdin);
    (void)scanf("%d", &n);
    for (i = 0; i < n; i++)
        (void)scanf("%s", g[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (g[i][j] == '1')
                sizes[total++] = bfs(i, j);

    qsort(sizes, total, sizeof(int), cmp);

    printf("%d\n", total);
    for (i = 0; i < total; i++)
        printf("%d\n", sizes[i]);

    return 0;
}
#endif