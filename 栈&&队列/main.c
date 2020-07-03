#include "stack_queue.h"

int main()
{
    //pStack sta = (pStack)malloc(sizeof(Stack));
    //sta->size = 0;
    // for (int i = 0; i < 5; ++i) {
    //     push(&sta, i);
    // }
    
    pQue que = (pQue)malloc(sizeof(Que));
    initQue(que);
    pushQue(que, 4);
    pushQue(que, 43);
    printf("topele = %d\n", getTopQue(que));
    popQue(que);
    popQue(que);
    printf("topele = %d\n", getTopQue(que));
    printf("size = %d\n", getSizeQue(que));
    return 0;
}