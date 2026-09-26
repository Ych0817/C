#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

//Binary Search 함수로
#if 0
int binary_search(int* data, int s, int e, int target) {
    int m;
    while (s <= e) {
        m = (s + e) / 2;
        if (target == data[m]) return m;
        //printf("%d %d %d\n", s, e, m);
        if (data[m] > target) {
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return -1;
}

int main(void) {
    int data[10] = { 1,3,4,7,9,11,13,15,17,19 };
    int s = 0;
    int e = 9;
    int m;
    int target = 15;

    m = binary_search(data, s, e, target);
    printf("data[%d] = %d\n", m, target);
}
#endif

//Binary Search
#if 0
int binary_search(int *data,int s,int e,int target) {
    int m;
    while (s <= e) {
        m = (s + e) / 2;
        printf("%d %d %d\n", s, e, m);
        if (target < data[m]) {
            e = m - 1;
        }
        else if (target > data[m]) {
            s = m + 1;
        }
        else {
            printf("data[%d] = %d\n", m, target);
            break;
        }
    }
    return m;
}
int main(void) {
    int data[10] = { 1,3,4,7,9,11,13,15,17,19 };
    int s = 0; 
    int e = 9;
    int m;
    int target = 15;

    while (s <= e) {
        m = (s + e) / 2;
        printf("%d %d %d\n", s, e, m);
        if (data[m] > target) {
            e = m - 1;
        }
        else if (data[m] < target) {
            s = m + 1;
        }
        else {
            printf("data[%d] = %d\n", m, target);
            break;
        }
    }
}
#endif
//buf를 활용한 출력으로 변경해 보는 것이 필요함
#if 0
typedef struct _nodeTree {
    char data;
    struct _nodeTree* left;
    struct _nodeTree* right;
}nodeTree_t;
typedef struct _tree {
    nodeTree_t* root;
    int size;
    int cnt;
}tree_t;
//preorder순서에 따라 node의 data를 출력
void preorder(nodeTree_t* node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);
}
void inorder(nodeTree_t* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}
void postorder(nodeTree_t* node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}
int main(void) {
    nodeTree_t A, B, C;
    nodeTree_t D = { '1' };
    nodeTree_t E = { '2' };
    nodeTree_t F = { '7' };
    nodeTree_t G = { '8' };
    nodeTree_t* Root = &A;
    A = (nodeTree_t){ '+', &B, &C };
    B = (nodeTree_t){ '*', &D, &E };
    C = (nodeTree_t){ '-', &F, &G };
    //pre-order
    printf("%c %c %c\n", Root->data, Root->left->data, Root->right->data);
    //in-order
    printf("%c %c %c\n", Root->left->data, Root->data,  Root->right->data);
    //post-order
    printf("%c %c %c\n",  Root->left->data, Root->right->data,Root->data);

    preorder(Root);
    printf("\n");

    inorder(Root);
    printf("\n");

    postorder(Root);
    return 0;
}


#endif