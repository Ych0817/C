#include "05_Queue.h"

// 연결리스트로 구현하는 Queue
#if 0
typedef struct _nodeQ {
    int r;
    int c;
    struct _nodeQ* next;   // 배열의 "다음 인덱스" 대신, 다음 노드를 직접 가리킴
} nodeQ;

typedef struct _queue_t {
    nodeQ* front;   // 꺼낼 노드 (헤드)
    nodeQ* rear;    // 마지막에 넣은 노드 (테일) — 이게 없으면 매번 끝까지 순회해야 함
    
} queue_t;

queue_t* init_Q(int size) {
    //(void)size; // 연결리스트는 원칙적으로 크기 제한이 없어서 size는 쓰지 않음
    // (용량을 제한하고 싶으면 queue_t에 capacity 필드를 추가해서 쓰면 됨)
    queue_t* nq = (queue_t*)malloc(sizeof(queue_t));
    if (nq == NULL) return NULL;
    nq->front = NULL;
    nq->rear = NULL;
    
    return nq;
}

int Enqueue(queue_t* q, nodeQ newdata) {
    nodeQ* node = (nodeQ*)malloc(sizeof(nodeQ));
    if (node == NULL) {
        printf("Overflow!\n");   // 배열판의 "칸이 없다"에 대응하는 건 여기선 "malloc 실패"뿐
        return 0;
    }
    node->r = newdata.r;
    node->c = newdata.c;
    node->next = NULL;

    if (q->rear == NULL) {       // 큐가 비어 있던 경우: 새 노드가 front이자 rear
        q->front = node;
        q->rear = node;
    }
    else {                      // 기존 rear 뒤에 이어 붙이고 rear를 갱신
        q->rear->next = node;
        q->rear = node;
    }
    
    return 1;
}

nodeQ* Dequeue(queue_t* q) {
    if (q->front == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    nodeQ* old = q->front;
    q->front = old->next;
    if (q->front == NULL) q->rear = NULL;   // 마지막 남은 노드를 꺼냈으면 rear도 같이 비움
    
    return old;   // 주의: free하지 않고 그대로 반환 — 호출한 쪽이 다 쓴 뒤 free 책임을 짐
}

void printQ(queue_t* q) {
    int i = 0;
    for (nodeQ* p = q->front; p != NULL; p = p->next) {
        printf("%d %d\n", p->r, p->c);
    }
}

void free_Q(queue_t* q) {
    nodeQ* p = q->front;
    while (p != NULL) {
        nodeQ* next = p->next;
        free(p);
        p = next;
    }
    free(q);
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
            if (!Enqueue(queue, (nodeQ) { r, c, NULL })) break;
        }
        else {
            nodeQ* popped = Dequeue(queue);
            if (!popped) break;
            free(popped);   // 연결리스트 버전에서는 다 쓴 노드를 직접 free 해줘야 함
        }
    }
    printQ(queue);
    free_Q(queue);
    return 0;
}
#endif

//더미 활용하여 enqueue dequeue 최적화
#if 0
typedef struct _nodeQ {
    int r;
    int c;
    struct _nodeQ* next;   // 배열의 "다음 인덱스" 대신, 다음 노드를 직접 가리킴
} nodeQ;

typedef struct _queue_t {
    nodeQ* front;   // 꺼낼 노드 (헤드)
    nodeQ* rear;    // 마지막에 넣은 노드 (테일) — 이게 없으면 매번 끝까지 순회해야 함
    
} queue_t;

queue_t* init_Q(int size) {
    //(void)size; // 연결리스트는 원칙적으로 크기 제한이 없어서 size는 쓰지 않음
    // (용량을 제한하고 싶으면 queue_t에 capacity 필드를 추가해서 쓰면 됨)
    queue_t* nq = (queue_t*)malloc(sizeof(queue_t));
    if (nq == NULL) return NULL;

    nodeQ* dummy = (nodeQ*)malloc(sizeof(nodeQ));
    if (dummy == NULL) {
        free(nq);            // [수정] nq를 해제하지 않으면 누수
        return NULL;
    }
    dummy->r = 0;
    dummy->c = 0;
    dummy->next = NULL;
    nq->front = dummy;
    nq->rear = dummy;

    return nq;
}

int Enqueue(queue_t* q, nodeQ newdata) {
    nodeQ* node = (nodeQ*)malloc(sizeof(nodeQ));
    
    if (node == NULL) {
        printf("Overflow!\n");   // 배열판의 "칸이 없다"에 대응하는 건 여기선 "malloc 실패"뿐
        return 0;
    }
    node->r = newdata.r;
    node->c = newdata.c;
    node->next = NULL;
                         
    q->rear->next = node;
    q->rear = node;
    

    return 1;
}

nodeQ* Dequeue(queue_t* q) {
    if (q->front->next == NULL) {   // front가 아니라 front->next를 봐야 함
        printf("Underflow!\n");
        return NULL;
    }
    nodeQ* old = q->front->next;
    q->front->next = old->next;        

    if (old == q->rear)
        q->rear = q->front;

    return old;
}

void printQ(queue_t* q) {
    int i = 0;
    for (nodeQ* p = q->front->next; p != NULL; p = p->next) {   // 더미 건너뜀
        printf("%d %d\n", p->r, p->c);
    }
}

void free_Q(queue_t* q) {
    nodeQ* p = q->front;
    while (p != NULL) {
        nodeQ* next = p->next;
        free(p);
        p = next;
    }
    free(q);
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
            if (!Enqueue(queue, (nodeQ) { r, c, NULL })) break;
        }
        else {
            nodeQ* popped = Dequeue(queue);
            if (!popped) break;
            free(popped);   // 연결리스트 버전에서는 다 쓴 노드를 직접 free 해줘야 함
        }
    }
    printQ(queue);
    free_Q(queue);
    return 0;
}
#endif

//더미 활용하여 동적할당 한번만 받고 enqueue dequeue 최적화
#if 0
typedef struct _nodeQ {
    int r;
    int c;
    struct _nodeQ* next;   
} nodeQ;

typedef struct _queue_t {
    nodeQ* front;   
    nodeQ* rear;    
    nodeQ dummy;
} queue_t;

queue_t* init_Q(int size) {
    
    queue_t* nq = (queue_t*)malloc(sizeof(queue_t));
    if (nq == NULL) return NULL;
    nq->dummy.r = 0;
    nq->dummy.c = 0;
    nq->dummy.next = NULL;
    nq->front = &nq->dummy;
    nq->rear = &nq->dummy;
    return nq;
}

int Enqueue(queue_t* q, nodeQ newdata) {
    nodeQ* node = (nodeQ*)malloc(sizeof(nodeQ));

    if (node == NULL) {
        printf("Overflow!\n");   
        return 0;
    }
    node->r = newdata.r;
    node->c = newdata.c;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;

    return 1;
}
nodeQ* Dequeue(queue_t* q) {
    if (q->front->next == NULL) {   
        printf("Underflow!\n");
        return NULL;
    }
    nodeQ* old = q->front->next;
    q->front->next = old->next;
    if (old == q->rear)
        q->rear = q->front;
    return old;
}

void printQ(queue_t* q) {
    int i = 0;
    for (nodeQ* p = q->front->next; p != NULL; p = p->next) {   
        printf("%d %d\n", p->r, p->c);
    }
}

void free_Q(queue_t* q) {
    nodeQ* p = q->front->next;
    while (p != NULL) {
        nodeQ* next = p->next;
        free(p);
        p = next;
    }
    free(q);
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
            if (!Enqueue(queue, (nodeQ) { r, c, NULL })) break;
        }
        else {
            nodeQ* popped = Dequeue(queue);
            if (!popped) break;
            free(popped);   
        }
    }
    printQ(queue);
    free_Q(queue);
    return 0;
}
#endif