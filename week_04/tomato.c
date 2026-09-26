#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX (1000 + 2)

#if 0
typedef struct _node_tomato {
	int r;
	int c;
} node_tomato;

int M, N;                          // M: (열), N: (행)
int arr[MAX][MAX];                 // 입력 + 방문(날짜) 배열
node_tomato Queue[MAX * MAX];      // 전역: 스택 오버플로 방지
int front, rear;

int dR[] = { -1, 1, 0, 0 };
int dC[] = { 0, 0, -1, 1 };

void inputData(void) {
	(void)scanf("%d %d", &M, &N);

	// 패딩: 테두리까지 전부 -1(벽)로 채움 → 경계 검사 불필요
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= M + 1; j++)
			arr[i][j] = -1;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			(void)scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {                   // 익은 토마토 = 시작점
				Queue[rear].r = i;
				Queue[rear].c = j;
				rear = rear + 1;                   // 전부 큐에 넣고 시작
			}
		}
}

void Tomato_BFS(void) {
	while (front < rear) {
		node_tomato curr;
		curr.r = Queue[front].r;
		curr.c = Queue[front].c;
		front++;
		for (int i = 0; i < 4; i++) {
			int nR = curr.r + dR[i];
			int nC = curr.c + dC[i];
			if (arr[nR][nC] == 0) {                            // 안 익은 토마토
				arr[nR][nC] = arr[curr.r][curr.c] + 1;         // 날짜 + 1 로 익힘
				Queue[rear].r = nR;
				Queue[rear].c = nC;
				rear = rear + 1;
			}
		}
	}
}

int getAnswer(void) {
	int maxDay = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) return -1;             // 끝내 안 익은 토마토
			if (arr[i][j] > maxDay) 
				maxDay = arr[i][j];
		}
	return maxDay - 1;                                 // 1에서 시작했으므로 1을 뺌
}

int main(void) {
	(void)freopen("tomato.txt", "r", stdin);
	inputData();
	Tomato_BFS();
	printf("%d\n", getAnswer());
	return 0;
}
#endif