#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h>


int main()
{
    int arr[LEN] = { 0 };
    printf("please insert 50 number to sort:");
    for (int i = 0; i < LEN; i++)
    {
        int a;
        if (scanf("%d", &a) == 1) {
            *(arr + i) = a;
        }
    }
    insertion_sort(arr, LEN);
    printf("%d", *arr);
    for (int loop = 1; loop < LEN; loop++) {
        printf(",%d", *(arr+loop));
    }
    
}





