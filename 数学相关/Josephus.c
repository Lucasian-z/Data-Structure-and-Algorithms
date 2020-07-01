#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}List, *pList;

void Josephus(int N, int M) {
    pList t = (pList)malloc(sizeof(List)), x = t;
    t->val = 1;
    t->next = t;
    for (int i = 2; i <= N; ++i) {//依次插入链表
        x->next = (pList)malloc(sizeof(List));
        x = x->next;
        x->val = i;
        x->next = t;
    }
    while (x != x->next) {//多于1个节点
        for (int i = 1; i < M; ++i) {//相隔M-1个
            x = x->next;
        }
        pList tmp = x->next;
        x->next = x->next->next;
        free(tmp);
        --N;
    }
    printf("res1 = %d\n", x->val);//最后生存的节点
}

//数学解法
void Josephus1(int N, int M) {
    int res = 0;
    for (int i = 2; i <= N; ++i) {
        res = (res + M) % i;
    }
    printf("res2 = %d\n", res + 1);
}

int main()
{
    int N, M;//总数N与每相隔M个人死亡
    scanf("%d%d", &N, &M);
    //Josephus(N, M);
    Josephus1(N, M);
    return 0;
}