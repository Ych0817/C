#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

//  단지번호붙이기 DFS , 재귀함수로 DFS
#if 0
#define MAX (25 + 2)
int arr[MAX][MAX] = { 0 };
int N;

typedef struct _node_danji {
	int r;
	int c;
}node_danji;

void printData(int (*arr)[MAX], int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printCnt(int* arr, int n) {
	//printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}
}

void inputData(void) {
	char temp[MAX] = { 0 };
	(void)scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		(void)scanf("%s", temp + 1);
		for (int j = 1; j <= N; ++j) {
			arr[i][j] = temp[j] - '0';
		}
	}
}

int dR[] = { -1, 1, 0, 0 };
int dC[] = { 0, 0, -1, 1 };

int danji_DFS(int sR, int sC, int vno) {
	node_danji stack[MAX * MAX] = { 0 };
	int top = 0;
	int cnt = 1;

	stack[top++] = (node_danji){ sR, sC };
	arr[sR][sC] = vno;
	while (top > 0) {
		node_danji curr = stack[--top];
		for (int i = 0; i < 4; ++i) {
			int nR = curr.r + dR[i];
			int nC = curr.c + dC[i];
			//printf("%d %d\n", nR, nC);
			//if (nR < 1 | nC < 1 | nR > N | nC > N) continue;
			if (arr[nR][nC] == 1) {  // 방문하지 않은 집
				stack[top++] = (node_danji){ nR, nC };
				arr[nR][nC] = vno;
				cnt++;
			}
		}
	}
	return cnt;
}

int vno;
int danji_reculsive(int currR, int currC) {
	int cnt = 1;
	arr[currR][currC] = vno; //방문 표시
	for (int i = 0; i < 4; ++i) {
		int nR = currR + dR[i];
		int nC = currC + dC[i];
		//printf("%d %d\n", nR, nC);
		//if (nR < 1 | nC < 1 | nR > N | nC > N) continue;
		if (arr[nR][nC] == 1) {  // 방문하지 않은 집
				arr[nR][nC] = vno;
				cnt += danji_reculsive(nR, nC);
		}
	}
	return cnt;
}

int danji_cnt[(MAX * MAX) / 2] = { 0 }; //return 안쓸라고 전역 으로
int danji_reculsive2(int currR, int currC) {
	++danji_cnt[vno - 2];
	arr[currR][currC] = vno; //방문 표시
	for (int i = 0; i < 4; ++i) {
		int nR = currR + dR[i];
		int nC = currC + dC[i];
		//printf("%d %d\n", nR, nC);
		//if (nR < 1 | nC < 1 | nR > N | nC > N) continue;
		if (arr[nR][nC] == 1) {  // 방문하지 않은 집
			arr[nR][nC] = vno;
			danji_reculsive2(nR, nC);
		}
	}
}

// 값의 범위가 1 ~ 25*25 범위이므로 안전하다.
int compint(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	//int danji_cnt[(MAX * MAX) / 2] = { 0 };
	(void)freopen("House_number.txt", "r", stdin);

	inputData();
	//printData(arr, N);

	int dno = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (arr[i][j] == 1) {  //  arr 배열은 입력배열 + 방문배열
				//danji_cnt[dno++] = danji_DFS(i, j, dno + 2);
				//printData(arr, N);


				vno = dno + 2;
				arr[i][j] = vno; //방문표시 2로 방문표시
				//danji_cnt[dno++] = danji_reculsive(i, j);

				danji_reculsive2(i, j);
				dno++;
			}
		}
	}
	qsort(danji_cnt, dno, sizeof(int), compint);
	printCnt(danji_cnt, dno);
	return 0;
}

#endif

//인접리스트 바이러스 DFS
#if 0
#define MAX (101)
int stack[MAX];
int top;
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

// DFS(Depth-First Search, 깊이 우선 탐색)
// 1. 시작점(start)을 스택에 삽입, 방문 표시
// 2. 스택에 내용이 있는 동안 반복(top > 0)
// 2-1, 스택에서 정점을 꺼냄
// 2-2, 그 정점과 연결된 방문하지 않은 정점을 찾음
// 2-3. "연결점이 끝점(end)인지 확인하고 아니라면" 정점을 스택에 삽입, 방문표시

int virus_dfs(int start) {
	int used[MAX] = { 0 };
	int cnt = 0;
	top = 0;
	stack[top++] = start;
	used[start] = 1;
	while (top > 0) {
		int curr = stack[--top];
		for (int i = 1; i <= arr[curr][0]; i++) {
			int next = arr[curr][i];
			if (used[next] == 0) {
				++cnt;
				stack[top++] = next;
				used[next] = 1;
			}
		}
	}
	return cnt;
}

//재귀함수를 사용한 바이러스_DFS 구현
int used[MAX] = { 0 }; //전역
int virus_cnt = 0;     //전역 여러 함수가 같이써야되서

void virus_reculsive(int curr) {
	for (int i = 1; i <= arr[curr][0]; i++) {
		int next = arr[curr][i];
		if (used[next] == 0) {
			++virus_cnt;
			used[next] = 1;
			virus_reculsive(next);
		}
	}
}

int virus_reculsive2(int curr) {
	int cnt = 1;
	for (int i = 1; i <= arr[curr][0]; i++) {
		int next = arr[curr][i];
		if (used[next] == 0) {
			used[next] = 1;
			cnt += virus_reculsive2(next);
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

	//print_arr(arr, v);
	//printf("\n%d\n", virus_dfs(1));

	used[1] = 1;
	virus_cnt = 0;

	//virus_reculsive(1);
	//printf("%d\n", virus_cnt);

	
	printf("%d\n", virus_reculsive2(1)-1);
	return 0;
}
#endif


//스택 연습! 메모리 할당 함수로 + 구조체 사용!
#if 0
typedef struct _stack_t{
	int* data ;
	int top ; //데이터를 넣을 위치 (데이터가 없음), 실제 데이터가 있는 위치 바로 위, 데이터는 top - 1 까지 있음.
	int size;
}stack_t;

//stack의 top부터 1개씩 pop하여 출력
void printstack(stack_t* stack) {
	int size = stack->size ;
	while (size < 0 ) {
		printf("%d\n",stack->data[--size]);
	}
}

int push(stack_t* stack, int data) {
	if (stack->top >= stack->size) {
		printf("overflow\n");
		return -1;
	}
	stack->data[stack->top++] = data;
	return data;
}

int pop(stack_t* stack) {
	//static int data = 0;
	if (stack->top <= 0) {
		printf("underflow\n");
		return -1;
	}
	return stack->data[--stack->top];
}

// 메모리 할당 및 해지를 여러번 해야함
/*
stack_t* init_stack(int size) {
	stack_t* new_stack = NULL;
	new_stack = (stack_t*)calloc(1, sizeof(stack_t));
	if (new_stack != NULL) {
		new_stack->data = (int*)calloc(size, sizeof(int));
		if (new_stack->data == 0) {
			printf("Out of memory\n");
			free(new_stack);
			return NULL;
		}
	}
	return new_stack;
}
*/

//메모리 할당 및 해지 1회 수행
stack_t* init_stack(int size) {
	stack_t* new_stack = NULL;
	new_stack = (stack_t*)calloc(1, sizeof(stack_t) + size * sizeof(int));
	if (new_stack != NULL) {
		new_stack->data = (int*)(new_stack + 1);
		new_stack->size = size;
		new_stack->top = 0;
	}
	return new_stack;
}

int main(void) {
	stack_t* stack = NULL;
	int size, cmd_cnt,data;
	char cmd[5] = { 0 };
	(void)freopen("09_stack.txt", "r", stdin);
	(void)scanf("%d %d", &size, &cmd_cnt);

	stack = init_stack(size);

	for (int i = 0; i < cmd_cnt; i++) {
		(void)scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			(void)scanf("%d", &data); 
			if (data != push(stack, data)) break;
		}
		else {
			if ((data = pop(stack)) == -1) break;
			printf("%d\n", pop(stack));
		}
	}
	free(stack);
	stack = NULL;
	return 0;
}
#endif


//스택 연습! 동적메모리 할당 메인에서 구현
#if 0
int* stack = 0;
int top = 0; //데이터를 넣을 위치 (데이터가 없음), 실제 데이터가 있는 위치 바로 위, 데이터는 top - 1 까지 있음.

void push(int a, int n) {
	if (top >= n) {
		printf("overflow\n");
		return;
	}
	stack[top++] = a;
}
int pop() {
	//static int data = 0;
	if (top <= 0) {
		printf("underflow\n");
		return -1;
	}
	return stack[--top];
}

int main(void) {
	int size, cmd_cnt, data;
	char cmd[16] = { 0 };
	(void)freopen("09_stack.txt", "r", stdin);
	(void)scanf("%d %d", &size, &cmd_cnt);

	stack = (int*)calloc(size, sizeof(int));   // 여기서 바로 할당
	if (stack == NULL) return 1;

	for (int i = 0; i < cmd_cnt; i++) {
		(void)scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {        
			(void)scanf("%d", &data);
			push(data, size);
		}
		else {
			printf("%d\n", pop());
		}
	}
	free(stack);
	return 0;
}
#endif
