#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

//인접리스트
#if 1
#define MAX (101)
int queue[MAX];
int front, rear;
int v;
int arr[MAX][MAX] = { 0 }; 

int print_arr(int (*arr)[MAX], int v) {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j <= arr[i][0]; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
}

// BFS(Breadth-First Search, 너비 우선 탐색)
// 1. 시작점(start)을 큐에 삽입, 방문 표시
// 2. 큐에 내용이 있는 동안 반복(front != rear)
// 2-1, 큐에서 정점을 꺼냄
// 2-2, 그 정점과 연결된 방문하지 않은 정점을 찾음
// 2-3. "연결점이 끝점(end)인지 확인하고 아니라면" 정점을 큐에 삽입, 방문표시

int virus_bfs(int start) {
	int used[MAX] = { 0 };
	int cnt = 0;
	front = rear = 0;
	queue[rear++] = start;
	used[start] = 1;
	while (front != rear) {
		int curr = queue[front++];
		for (int i = 1; i <= arr[curr][0]; i++) {
			int n = arr[curr][i];      
			if (used[n] == 0) {
				++cnt;
				queue[rear++] = n;
				used[n] = 1;
			}
		}
	}
	return cnt;
}

int main(void) {

	int e, v1, v2;
	(void)freopen("virus.txt", "r", stdin);
	(void)scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		(void)scanf("%d %d", &v1, &v2);
		arr[v1][++arr[v1][0]] = v2;
		arr[v2][++arr[v2][0]] = v1;
	}

	print_arr(arr, v);
	printf("\n%d\n", virus_bfs(1));
	return 0;
}
#endif

//인접행렬
#if 0
#define MAX (101)
int queue[MAX];
int front, rear;
int v;
int arr[MAX][MAX] = { 0 }; //인접행렬

int print_arr(int (*arr)[MAX], int v) {
	printf("  ");
	for (int j = 1; j <= v; j++) {
		printf("%3d", j);
	}
	printf("\n");

	for (int i = 1; i <= v; i++) {
		printf("%2d", i);
		for (int j = 1; j <= v; j++) {
			if (arr[i][j] == 1)
				printf("%3d", 1);
			else
				printf("%3s", "");
		}
		printf("\n");
	}
}

// BFS(Breadth-First Search, 너비 우선 탐색)
// 1. 시작점(start)을 큐에 삽입, 방문 표시
// 2. 큐에 내용이 있는 동안 반복(front != rear)
// 2-1, 큐에서 정점을 꺼냄
// 2-2, 그 정점과 연결된 방문하지 않은 정점을 찾음
// 2-3. "연결점이 끝점(end)인지 확인하고 아니라면" 정점을 큐에 삽입, 방문표시

int virus_bfs(int start) {
	int used[MAX] = { 0 };
	int cnt = 0;
	front = rear = 0;
	queue[rear++] = start;
	used[start] = 1;
	while (front != rear) {
		int curr = queue[front++];
		for (int i = 1; i <= v; i++) {
			if (arr[curr][i] && used[i] == 0 ){
				++cnt;
				queue[rear++] = i;
				used[i] = 1;

			}
		}
	}
	return cnt;
}

int main(void) {
	
	int e, v1, v2;
	(void)freopen("virus.txt", "r", stdin);
	(void)scanf("%d %d",&v, &e);

	for (int i = 0; i < e; i++) {
		(void)scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}

	print_arr(arr, v);
	printf("\n%d\n", virus_bfs(1));
	return 0;
}
#endif

#if 0
#define MAX (101)
int queue[MAX];
int front, rear;

void bfs(int (*arr)[MAX], int v, int* used) {
	front = rear = 0;
	queue[rear++] = 1;
	used[1] = 1;
	int count = 0;

	while (front < rear) {
		int cur = queue[front++];
		for (int i = 1; i <= v; i++) {
			if (arr[cur][i] == 1 && used[i] == 0) {
				used[i] = 1;
				queue[rear++] = i;
				count++;
			}
		}
	}
	printf("%d\n", count);
}

int main(void) {
	int arr[MAX][MAX] = { 0 }; //인접행렬
	int used[MAX] = { 0 };
	int v, e, v1, v2;
	(void)freopen("virus.txt", "r", stdin);
	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}

	bfs(arr, v, used);

	return 0;
}
#endif