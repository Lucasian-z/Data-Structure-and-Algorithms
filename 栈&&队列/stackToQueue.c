#include "stack_queue.h"

/*利用双栈实现队列，利用双队实现栈
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/03/ 11:09:19
*/

//双栈实现队列
pStack sta1, sta2;

int isEmpty1() {
    return getSize(sta1) == 0 && getSize(sta2) == 0;
}

int getSize1() {
    return getSize(sta1) + getSize(sta2);
}

void push1(int x) {
    push(sta1, x);
}

void pop1() {
    if (getSize(sta2) > 0) {
        pop(sta2);
    }else {
        while (getSize(sta1) > 0) {
            push(sta2, getTop(sta1));
            pop(sta1);
        }
        if (getSize(sta2) > 0) {
            pop(sta2);
        }
    }
}

int getTop1() {
    if (getSize(sta2) > 0) {
        return getTop(sta2);
    }else {
        while (getSize(sta1) > 0) {
            push(sta2, getTop(sta1));
            pop(sta1);
        }
        if (getSize(sta2) > 0) {
            return getTop(sta2);
        }
    }
    return -1;
}

void init1() {
    sta1 = (pStack)malloc(sizeof(Stack));
    sta2 = (pStack)malloc(sizeof(Stack));
    sta1->head = NULL;
    sta2->head = NULL;
    sta1->size = 0;
    sta2->size = 0;
}

void test1() {
    init1();
    printf("%d\n", getTop1());
    push1(6666);
    printf("%d\n", getTop1());
    push1(888);
    printf("%d\n", getTop1());
    pop1();
    printf("%d\n", getTop1());
    pop1();
    printf("%d\n", getTop1());
}

//双队实现栈
pQue que1, que2;


void init2() {
    que1 = (pQue)malloc(sizeof(Que));
    initQue(que1);
    que2 = (pQue)malloc(sizeof(Que));
    initQue(que2);
}

int getSize2() {
    return que1->size + que2->size;
}

int isEmpty2() {
    return getSizeQue(que1) == 0 && getSizeQue(que2) == 0;
}

int getTop2() {
    int res = 0;
    if (isEmpty2()) {
        return -1;
    }
    if (getSizeQue(que1) >= 1) {
        while (getSizeQue(que1) > 1) {
            pushQue(que2, getTopQue(que1));
            popQue(que1);
        }
        if (!isEmptyQue(que1)) {
            res = getTopQue(que1);
            popQue(que1);
            pushQue(que2, res);
        }
    }else if(getSizeQue(que2) >= 1) {
        while (getSizeQue(que2) > 1) {
            pushQue(que1, getTopQue(que2));
            popQue(que2);
        }
        if (!isEmptyQue(que2)) {
            res = getTopQue(que2);
            popQue(que2);
            pushQue(que1, res);
        }
    }
    return res;
}

void push2(int x) {
    if (isEmptyQue(que1)) {
        pushQue(que2, x);
    }else {
        pushQue(que1, x);
    }
}

void pop2() {
    if (getSizeQue(que1) >= 1) {
        while (getSizeQue(que1) > 1) {
            pushQue(que2, getTopQue(que1));
            popQue(que1);
        }
        if (!isEmptyQue(que1)) {
            popQue(que1);
        }
    }else if (getSizeQue(que2) >= 1) {
        while (getSizeQue(que2) > 1) {
            pushQue(que1, getTopQue(que2));
            popQue(que2);
        }
        if (!isEmptyQue(que2)) {
            popQue(que2);
        }
    }
}

void test2() {    
    init2();
    push2(43);
    push2(56);
    push2(455);
    printf("%d\n", getTop2());
    pop2();
    pop2();
    pop2();
    pop2();
    printf("%d\n", getTop2());
}

int main() 
{
    //test1();
    test2();
    return 0;
}