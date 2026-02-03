//
// Created by 23229 on 2026/2/3.
//

#ifndef DATA_STRUCTURE_LEARNING_FUNCTION_H
#define DATA_STRUCTURE_LEARNING_FUNCTION_H

/* includes */
#include <stdio.h>

/* defines */

/**
 * @brief 将数组划分为两部分（快排核心逻辑）
 * @param nums 目标数组
 * @param L 左边界索引
 * @param R 右边界索引
 * @return 分区点的索引
 */
int divide(int* nums, int L, int R);

/**
 * @brief 快速排序递归函数
 * @param nums 目标数组
 * @param L 左边界索引
 * @param R 右边界索引
 */
void QuickSort(int* nums, int L, int R);

#endif //DATA_STRUCTURE_LEARNING_FUNCTION_H
