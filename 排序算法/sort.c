#include "sort.h"

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i; j < n; ++j) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[k];
        arr[k] = tmp;
    }
}

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i];
        int j = i - 1;
        for (; j >= 0 && tmp < arr[j]; --j) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) {
            --right;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) {
            ++left;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int parti = partition(arr, left, right);
        quickSort(arr, left, parti - 1);
        quickSort(arr, parti + 1, right);
    }
}

void downAdjust(int arr[], int left, int right) {
    int i = left, j = 2 * i + 1;
    while (j <= right) {
        if (j + 1 <= right && arr[j] < arr[j + 1]) ++j;
        if (arr[i] <= arr[j]) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i = j;
            j = 2 * i + 1;
        }else {
            break;
        }
    }
    
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        downAdjust(arr, i, n - 1);
    }
    for (int i = n - 1; i > 0; --i) {        
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        downAdjust(arr, 0, i - 1);
    }
}

void shellSort(int arr[], int n) {
    for (int D = n / 2; D > 0; D /= 2) {
        for (int i = D; i < n; ++i) {
            int tmp = arr[i];
            int j = i;
            for (; j >= D && arr[j-D] > tmp; j -= D) {
                arr[j] = arr[j-D];
            }
            arr[j] = tmp;
        }
    }
}

void merge(int arr[], int tmpA[], int L1, int L2, int R2) {
    int tmp = L1, R1 = L2 - 1;
    int cnt = R2 - L1 + 1;
    while (L1 <= R1 && L2 <= R2) {
        if (arr[L1] <= arr[L2]) tmpA[tmp++] = arr[L1++];
        else tmpA[tmp++] = arr[L2++];
    }
    while (L1 <= R1) {
        tmpA[tmp++] = arr[L1++];
    }
    while (L2 <= R2) {
        tmpA[tmp++] = arr[L2++];
    }
    for (int i = 0; i < cnt; ++i, R2--) {
        arr[R2] = tmpA[R2];
    }
}

void merge_sort(int arr[], int tmpA[], int L, int R) {
    if (L < R) {
        int mid = (L + R) / 2;
        merge_sort(arr, tmpA, L, mid);
        merge_sort(arr, tmpA, mid + 1, R);
        merge(arr, tmpA, L, mid + 1, R);
    }
}

void mergeSort(int arr[], int n) {
    int *tmpA = (int *)malloc(sizeof(int) * n);
    merge_sort(arr, tmpA, 0, n - 1);
}

void countSort(int arr[], int n) {
    int counts[100];
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < n; ++i) {
        ++counts[arr[i]];
    }
    int cnt = 0;
    for (int i = 0; i < 100; ++i) {
        while (counts[i] > 0) {
            arr[cnt++] = i;
            --counts[i];
        }
    }
}