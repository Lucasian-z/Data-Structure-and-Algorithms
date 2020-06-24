#include "sort.h"

#define N 10


int main()
{
    srand((unsigned int)time(NULL));
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 100;
    }
    printArr(arr, N);
    //bubbleSort(arr, N);
    //selectSort(arr, N);
    //insertSort(arr, N);
    //quickSort(arr, 0, N - 1);
    //heapSort(arr, N);
    //shellSort(arr, N);
    //mergeSort(arr, N);
    countSort(arr, N);
    printArr(arr, N);
    return 0;
}