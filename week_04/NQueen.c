#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#if 1
#define MAX (12)
int cols[MAX];
int main_d[MAX*2];
int anti_d[MAX*2];
int cnt;
int N;

// n : 행번호 - n번 행에 Queen을 놓는 함수 
void nqueen_DFS(int r) {
	if (r == N) {
		++cnt;
		return;
	}
	for (int c = 0; c < N; ++c) {
		int md = (r - c) + N;
		int ad = r + c;
		if (cols[c] || main_d[md] || anti_d[ad]) continue; 
		cols[c] = 1; main_d[md] = 1; anti_d[ad] = 1;   //방문표시

		nqueen_DFS(r + 1); 
		cols[c] = 0; main_d[md] = 0; anti_d[ad] = 0;  //방문해제
	}
}

int main(void) {
	(void)scanf("%d", &N);
	nqueen_DFS(0);
	printf("%d\n", cnt);
	return 0;
}
#endif
