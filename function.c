//
// Created by 23229 on 2026/2/3.
//

/* includes */
#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

//Hash Table (Separate Chaining)
HashTable* HashTable_create() {
    HashTable* map = (HashTable*)malloc(sizeof(HashTable));
    memset(map->buckets, 0, sizeof(map->buckets)); // 将所有桶头指针初始化为 NULL，memset 比循环更快
    return map;
}

int Hash_getidx(int key) {
    int idx = key % HASH_SIZE;
    return idx < 0 ? idx + HASH_SIZE : idx;
}

void Hash_put(HashTable* map, int key, int value) {
    int idx = Hash_getidx(key);
    HashNode* node = map->buckets[idx];

    // 1. 遍历链表，看 key 是否已存在
    while (node) {
        if (node->key == key) {
            node->value = value; // 存在则更新
            return;
        }
        node = node->next;
    }

    // 2. 不存在，使用"头插法"插入新节点 (效率 O(1))
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[idx]; // 新节点指向旧头
    map->buckets[idx] = newNode;       // 桶头指向新节点
}

int Hash_getvaule(HashTable * map, int key) {
    int idx = Hash_getidx(key);
    HashNode* node = map->buckets[idx];

    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // 表示未找到
}

bool contains(HashTable * map, int key) {
    int idx = Hash_getidx(key);
    HashNode* node = map->buckets[idx];
    while (node) {
        if (node->key == key) return true;
        node = node->next;
    }
    return false;
}

void Hash_deleteKey(HashTable * map, int key) {
    int idx = Hash_getidx(key);
    HashNode* node = map->buckets[idx];
    HashNode* prev = NULL;

    while (node) {
        if (node->key == key) {
            if (prev) prev->next = node->next;
            else map->buckets[idx] = node->next; // 删除的是头节点
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void freeHashMap(HashTable * map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = map->buckets[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map);
}



