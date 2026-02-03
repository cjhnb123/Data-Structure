//
// Created by 23229 on 2026/2/3.
//

/* includes */
#include "function.h"

/* function */
//QuickSort
int divide(int* nums, int L, int R){
    int now = nums[L];
    while (L < R){
        while (nums[R] >= now && L < R) R--;
        nums[L] = nums[R];
        while (nums[L] <= now && L < R) L++;
        nums[R] = nums[L];
    }
    nums[L] = now;
    return L;
}

void QuickSort(int* nums, int L, int R){
    if (L >= R) return;
    int mid = divide(nums, L, R);
    QuickSort(nums, L, mid - 1);
    QuickSort(nums, mid + 1, R);
}
