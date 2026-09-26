#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX (100 + 2)

#if 0
typedef struct _node_zerg {
	int r;
	int c;
} node_zerg;

int M, N;                        // M: 열(가로), N: 행(세로)
int arr[MAX][MAX];               // 1 = 저글링, 0 = 빈 칸
int dist[MAX][MAX];              // 0 = 오염 안 됨, 그 외 = 오염된 시각 + 1
node_zerg Queue[MAX * MAX];
int front, rear;

int dR[] = { -1, 1, 0, 0 };
int dC[] = { 0, 0, -1, 1 };

int sR, sC;                      // 방사능 공격 위치 (행, 열)

void inputData(void) {
	char temp[MAX] = { 0 };
	(void)scanf("%d %d", &M, &N);          // 열, 행 순서

	for (int i = 1; i <= N; i++) {
		(void)scanf("%s", temp + 1);       // 1번 칸부터 저장
		for (int j = 1; j <= M; j++)
			arr[i][j] = temp[j] - '0';
	}
	(void)scanf("%d %d", &sC, &sR);        // 열 번호, 행 번호 순서
}

void Zerg_BFS(void) {
	if (arr[sR][sC] != 1) return;        // ← 추가: 저글링이 없으면 아무도 오염되지 않음
	Queue[rear++] = (node_zerg){ sR, sC };
	dist[sR][sC] = 1;                      // 0초에 오염 (0 + 1)

	while (front != rear) {
		node_zerg curr = Queue[front++];
		for (int i = 0; i < 4; i++) {
			int nR = curr.r + dR[i];
			int nC = curr.c + dC[i];
			if (arr[nR][nC] != 1) continue;        // 저글링이 없는 칸(테두리 포함)
			if (dist[nR][nC] != 0) continue;       // 이미 오염됨
			dist[nR][nC] = dist[curr.r][curr.c] + 1;
			Queue[rear++] = (node_zerg){ nR, nC };
		}
	}
}

int main(void) {
	(void)freopen("zergling.txt", "r", stdin);
	inputData();
	Zerg_BFS();

	int maxTime = 0, alive = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] != 1) continue;
			if (dist[i][j] == 0) alive++;                  // 오염되지 않고 살아남음
			else if (dist[i][j] > maxTime) maxTime = dist[i][j];
		}

	printf("%d\n", maxTime == 0 ? 0 : maxTime - 1 + 3);   // 아무도 안 죽으면 0초
	printf("%d\n", alive);
	return 0;
}
#endif