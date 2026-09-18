#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#define MAX (25+2)


/*
<BFS> (인접/연결 + 최단경로이동) (너비우선탐색) (한걸음씩 가면서 찾음)
1. 시작점, 끝점을 찾고(없음, 1개, N개)
 - 시작점이 여러개 일 때 :
   - BFS를 N번 실행(Queue에 1개씩 넣고 실행,보물섬)
   - Queue에 시작점을 모두 넣고 진행(토마토)

2. 인접의 정의 : 왼/오른쪽, 상하좌우, (1,2)(왼쪽하나 오른쪽 두개)

3. 방문(used, visit) : 어떤 정점을 여러번 방문할 수 있는지 여부
  - 여러번 방문인 경우 : 그 기록을 어떻게 할 것인지 결정해야 함
  (0으로 초기화, 개수 세기, 최솟/최댓값으로 갱신)

  - 한 번 방문인 경우 : 단순한 방문표시로 해결 가능

  - BFS를 1회 수행하는 경우 입력 배열을 방문 배열로 사용할 수 있음

  - BFS를 여러 번 수행해야 하는 경우
	입력 배열을 방문 배열로 사용할 수 있는 경우(단지 번호 붙이기)와 없는 경우(보물섬)가 있음.

4. 방문 설계에 따라 Queue의 크기, 구현 방식이 달라질 수 있음(선형,Circular,Linked)

 */

 /*
 단지번호붙이기 설계
 1. 시작점 : 여러개, BFS를 수행하는 횟수(여러번)
	끝점 : 특정할 수 없음
 2. 인접 : 상하좌우의 방문하지 않은 집
 3. 방문 : 별도의 방문배열 사용 또는 입력배열을 방문배열로 사용할 수 있음
 4. Queue의 크기 : map의 최대 크기 사용 ( N*M / 25*25)
	Queue의 노드 : {r , c}
 */

 //GIGO : Gabage In, Gabage Out - 컴퓨터/데이터 분석 분야에서 자주 쓰이는 표현
 //입력 데이터의 품질이 나쁘면 아무리 좋은 알고리즘이나 모델을 써도 결과물의 품질 역시 나쁠 수 밖에 없다.

#if 0
typedef struct _node_danji {
	int r;
	int c;
}node_danji;


int arr[MAX][MAX] = { 0 };
int N;
int dR[] = { -1, 1 ,0, 0 };
int dC[] = { 0,0,-1,1 };


void inputData(void) {
	char temp[MAX] = { 0 };
	(void)scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		(void)scanf("%s", temp + 1);
		for (int j = 1; j <= N; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	printf("\n");
}
int printData(int (*arr)[MAX], int v) {
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int danji_BFS(int sR, int sC, int vno) {
	node_danji Queue[MAX * MAX] = { 0 };
	int front=0, rear = 0;
	Queue[rear++] = (node_danji){ sR,sC };
	arr[sR][sC] = vno;
	while (front != rear) {
		node_danji curr = Queue[front++];
		for (int i = 0; i < 4; i++) {
			int nR = curr.r + dR[i];
			int nC = curr.c + dC[i];

			//printf(" % d % d\n", nR, nC);
			//if (nR < 1 || nC <1 || nR > N || nC> N) contine;

			if (arr[nR][nC] == 1) { //방문하지 않은 집
				Queue[rear++] = (node_danji){ nR,nC };
				arr[nR][nC] = vno;

			}
		}
	}
	return rear;
}
int compint(void* a, void* b) {
	int* ap = (int*)a;
	int* bp = (int*)b;
	return *ap - *bp;
}
void printCnt(int* arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}	

int main(void) {
	int danji_cnt[(MAX*MAX) / 2] = {0};
	(void)freopen("House_number.txt", "r", stdin);
	inputData();
	//printData(arr, N);

    /*int currR = 1, currC = 1;
	for (int i = 0; i < 4; i++) {
		int nR = currR + dR[i];
		int nC = currR + dC[i];
		printf("%d %d\n", nR, nC);
	}*/
	int dno = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1 ) { //arr 배열은 입력배열 + 방문배열
				int cnt = danji_BFS(i, j,dno + 2);
				danji_cnt[dno++] = cnt;
				
			}
		}
	}
	qsort(danji_cnt, dno, sizeof(int), compint);
	printCnt(danji_cnt, dno);
	
	return 0;
}
#endif