#include "05_Queue.h"

// 배열로 구현하는 Circular Queue 
//r == f (Empty)
//(r+1) == f (Full) --> (r+1) % g->size == if(++rear == g->size) rear == 0
#if 0
#define MAX (5)
typedef struct _nodeQ {
    int r;
    int c;
} nodeQ;

typedef struct _queue_t {
    nodeQ* data;  // 배열
    int front;
    int rear;
    int size;
} queue_t;

queue_t* init_Q(int size) {
    queue_t* nq = (queue_t*)malloc(sizeof(queue_t));
    ++size; //더미 노드를 위한 공간 확보
    if (nq == NULL) return NULL;
    nq->data = (nodeQ*)malloc(sizeof(nodeQ) * size);
    if (nq->data == NULL) {
        free(nq);
        return NULL;
    }
    nq->front = 0;
    nq->rear = 0;
    nq->size = size;
    return nq;
}
int Enqueue(queue_t* q, nodeQ newdata) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Overflow!\n");
        return 0;
    }
    q->data[q->rear] = newdata;
    q->rear = (q->rear + 1) % q->size;
    return 1;
}
nodeQ* Dequeue(queue_t* q) {
    if (q->front == q->rear) {
        printf("Underflow!\n");
        return NULL;
    }
    nodeQ* result = &(q->data[q->front]);
    q->front = (q->front + 1) % (q->size);
    return result;
}
void printQ(queue_t* q) {
    /*for (int i = 0; i < q->size; ++i) {
        printf("%d : %d %d\n", i, q->data[i].r, q->data[i].c);
    }*/
    for (int i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf("%d : %d %d\n", i, q->data[i].r, q->data[i].c);
    }
}
int main(void) {
    queue_t* queue = NULL;
    char cmd;
    int n, s;
    int r, c;
    int i;              

    (void)freopen("qdata.txt", "r", stdin);
    (void)scanf("%d %d", &s, &n);
    queue = init_Q(s);

    for (i = 0; i < n; ++i) {
        (void)scanf(" %c", &cmd);
        if (cmd == 'P') {
            (void)scanf("%d %d", &r, &c);
            if (!Enqueue(queue, (nodeQ) { r, c })) break; 
        }
        else {
            if (!Dequeue(queue)) break;
        }
    }
    //printf("%d\n", i);
    printQ(queue);
    free(queue->data);
    free(queue);
    return 0;
}
#endif
