#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10

/* mem系列函数
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/10/ 11:54:27
*/

void printArr(int arr[]) {
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand((unsigned int)time(NULL));
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 100;
    }
    printArr(arr);
    //memcpy(arr, arr + 5, 5 * sizeof(int));//将后5个元素复制到前5个位置
    memmove(arr, arr + 1, 5 * sizeof(int));
    printArr(arr);
    return 0;
}