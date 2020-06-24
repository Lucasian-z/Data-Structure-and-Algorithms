#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <memory.h>

//数组打印
void printArr(int arr[], int n);

//冒泡排序
void bubbleSort(int arr[], int n);
//选择排序
void selectSort(int arr[], int n);
//插入排序
void insertSort(int arr[], int n);
//快速排序
int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);
//堆排序
void downAdjust(int arr[], int left, int right);
void heapSort(int arr[], int n);
//希尔排序
void shellSort(int arr[], int n);
//归并排序
void merge(int arr[], int tmp[], int L1, int L2, int R2);
void merge_sort(int arr[], int tmp[], int L, int R);
void mergeSort(int arr[], int n);
//计数排序
void countSort(int arr[], int n);