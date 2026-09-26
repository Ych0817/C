#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#define MAX (104)

#if 0
typedef struct _node_Janggi {
	int r;
	int c;
}node_Janggi;

node_Janggi Queue[MAX * MAX] = { 0 };
int R, C, K, S, N, M;
int dist[MAX][MAX] = { 0 };
int dR[] = { 2, 2,-2,-2,1,1,-1,-1};
int dC[] = { 1,-1,-1,1,2,-2,2,-2};

int printData(int (*arr)[MAX], int a, int b) {
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Jangji_BFS(int sR, int sC, int s, int k) {
	int front = 0, rear = 0;
	Queue[rear++] = (node_Janggi){ sR, sC };   
	dist[sR][sC] = 0;
	
	while (front != rear) {
		node_Janggi curr = Queue[front++];
		//if (curr.r == s && curr.c == k) break;

		for (int i = 0; i < 8; i++) {
			int nR = curr.r + dR[i];
			int nC = curr.c + dC[i];

			if (nR < 1 || nR > N || nC < 1 || nC > M) continue;
			if (curr.r == s && curr.c == k) return dist[nR][nC] -1;
			if (dist[nR][nC] == 0) {  //방문하지 않은 곳
				Queue[rear++] = (node_Janggi){ nR,nC };
				dist[nR][nC] = dist[curr.r][curr.c] + 1;
			}
		}
		//printData(dist, N, M);
	}
	return dist[s][k];
}

int main(void) {

	(void)freopen("Janggi.txt", "r", stdin);
	(void)scanf("%d %d", &N, &M);
	(void)scanf("%d %d %d %d", &R, &C, &S, &K);

	printf("%d", Jangji_BFS(R, C, S, K));

	return 0;
}
#endif