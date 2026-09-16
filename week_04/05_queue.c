#include "05_queue.h"

//배열로 구현하는 simple queue
#if 1
#define MAX (5)
typedef struct _nodeQ{
	int r;
	int c;
}nodeQ;

typedef struct _queue_t {

}queue_t;

int Enqueue(nodeQ*q,int *rear,int r, int c) {
	if (MAX <= *rear) {
		printf("overflow\n");
		return 0;
	}
	q[*rear].r = r;
	q[*rear].c = c;
	(*rear)++;
	return 1;
}
nodeQ* Dequeue(nodeQ* q, int* front) {

}

void print_q(nodeQ* q, int front, int rear) {
	for (int i = front; i < rear; i++)
		printf("%d %d\n", q[i].r, q[i].c);
}

int main(void) {
	nodeQ queue[MAX] = { 0 };
	int front, rear,n,r,c;
	char cmd;
	front = rear = 0;
	(void)freopen("queueadata.txt", "r", stdin);
	(void)scanf("%d", &n);
	for (int i = 0; i < 2; i++) {
		(void)scanf(" %c", cmd);
		if(cmd == 'P'){
			(void)scanf("%d %d", &r, &c);
			if (!Enqueue(queue, &rear, r, c)) break; //overflow인 경우 반복문 종료
		//printf("%d %d", &r, &c);
		}
	}
	print_q(queue,front,rear);
	return 0;
}
#endif