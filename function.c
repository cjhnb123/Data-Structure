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

//Disjoint Set Union
DSU* creatDSU(int n){
    DSU* dsu = (DSU*) malloc(sizeof(DSU));
    dsu -> front = (int*) malloc(sizeof(int) * n);
    dsu -> rank = (int*) malloc(sizeof(int) * n);
    dsu -> count = n;
    for (int i = 0; i < n; i++){
        dsu -> front[i] = i;
        dsu -> rank[i] = 1;
    }
    return dsu;
}

int findDSU(DSU* dsu, int i){
    if (dsu -> front[i] == i) return i;
    // 递归查找并将结果直接赋值给front[i]，实现“路径压缩”
    return dsu->front[i] = findDSU(dsu, dsu->front[i]);
}

void UniteDSU(DSU* dsu, int i, int j){
    int rootI = findDSU(dsu, i);
    int rootJ = findDSU(dsu, j);

    if (rootI != rootJ) {
        if (dsu->rank[rootI] == dsu->rank[rootJ]) {
            dsu->front[rootJ] = rootI;
            dsu->rank[rootI]++;
        }
        else if (dsu->rank[rootI] < dsu->rank[rootJ]) dsu->front[rootI] = rootJ;
        else dsu->front[rootJ] = rootI;
        dsu->count--;
    }
}

bool DSUisConnected(DSU* dsu, int i, int j) {
    return findDSU(dsu, i) == findDSU(dsu, j);
}

void freeDSU(DSU* dsu){
    free(dsu -> front);
    free(dsu -> rank);
    free(dsu);
}

//Adjacency Matrix
void initMatrix(GraphMatrix* g, int v){
    g -> numV = v;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            g -> matrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(GraphMatrix* g, int u, int v){
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

int DFS_Matrix(GraphMatrix* g, int curr, bool* visited){
    visited[curr] = true;
    printf("%d", curr);

    for (int i = 0; i < g -> numV; i++) {
        if (g->matrix[curr][i] == 1 && visited[i] == false){
            DFS_Matrix(g, i, visited);
        }
    }
}

void BFS_Matrix(GraphMatrix* g, int start){
    bool visited[MAX_V] = {false};
    int queue[MAX_V];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < g->numV; i++) {
            if (g->matrix[curr][i] == 1 && visited[i] == false) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

//Adjacency List
Node* createNode(int d){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = d;
    newNode->next = NULL;
    return newNode;
}

GraphList* initGraphList(int v){
    GraphList* g = malloc(sizeof(GraphList));
    g->numV = v;
    g->adjLists = malloc(v * sizeof(Node*));
    for (int i = 0; i < v; i++) g->adjLists[i] = NULL;
    return g;
}

void addEdgeList(GraphList* g, int u, int v){
    // 头插法：u -> v
    Node* newNode = createNode(v);
    newNode->next = g->adjLists[u];
    g->adjLists[u] = newNode;
}

void DFS_List(GraphList* g, int curr, bool* visited){
    visited[curr] = true;
    printf("%d ", curr);

    Node* temp = g->adjLists[curr];
    while (temp) {
        if (!visited[temp->val]) {
            DFS_List(g, temp->val, visited);
        }
        temp = temp->next;
    }
}

void BFS_List(GraphList* g, int start){
    bool* visited = calloc(g->numV, sizeof(bool));
    int* queue = malloc(sizeof(int) * g->numV);
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        Node* temp = g->adjLists[curr];
        while (temp) {
            if (!visited[temp->val]) {
                visited[temp->val] = true;
                queue[rear++] = temp->val;
            }
            temp = temp->next;
        }
    }
    free(visited);
    free(queue);
}





