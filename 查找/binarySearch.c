#include <stdio.h>
#include <stdlib.h>

#define N 10

//查找x对应的下标，若不存在该值则返回-1
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1, mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    return -1;
}

//找到第一个大于等于x的下标
int lower_bound(int arr[], int n, int x) {
    int left = 0, right = n, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] >= x) {
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

//找到第一个大于x的下标
int upper_bound(int arr[], int n, int x) {
    int left = 0, right = n, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] > x) {
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int arr[N] = {0,3,4,5,6,57,67,69,677,6969};
    int x;
    while (scanf("%d", &x) != EOF) {
        //int res = binarySearch(arr, N, x);
        //int res = lower_bound(arr, N, x);
        int res = upper_bound(arr, N, x);
        printf("%d\n", res);
    }    
    
    return 0;
}