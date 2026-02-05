//
// Created by 23229 on 2026/2/3.
//

#ifndef DATA_STRUCTURE_LEARNING_FUNCTION_H
#define DATA_STRUCTURE_LEARNING_FUNCTION_H

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* defines */
//Hash Table
#define HASH_SIZE 10007
typedef struct HashNode {
    int key; //关键字
    int value; //值
    struct HashNode *next; //链
} HashNode; //哈希节点结构体定义

typedef struct {
    HashNode *buckets[HASH_SIZE]; // 指针数组，存储每个桶的头节点
} HashTable; //哈希表

//Disjoint Set Union
typedef struct {
    int *front; //记录首结点
    int *rank; //记录树高
    int count; //记录连通分量的数量
} DSU;

//Adjacency Matrix
#define MAX_V 100
typedef struct {
    int numV;
    int matrix[MAX_V][MAX_V];
} GraphMatrix;

//Adjacency List
typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int numV;
    Node** adjLists; // 指针数组，每个元素是一个链表头
} GraphList;




/* function */
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





/**
 * @brief 哈希函数：将 key 映射到 0 ~ HASH_SIZE-1
 * @param key 关键字
 */
int Hash_getidx(int key);

/**
 * @brief 哈希表插入或更新
 * @param map 哈希表
 * @param key 关键字
 * @param value 值
 */
void Hash_put(HashTable* map, int key, int value);

/**
 * @brief 哈希表中查找值
 * @param map 哈希表
 * @param key 关键字
 */
int Hash_getvaule(HashTable * map, int key);

/**
 * @brief 哈希表中检查key是否存在
 * @param map 哈希表
 * @param key 关键字
 */
bool contains(HashTable * map, int key);

/**
 * @brief 哈希表中删除key
 * @param map 哈希表
 * @param key 关键字
 */
void Hash_deleteKey(HashTable * map, int key);

/**
 * @brief 哈希表释放内存
 * @param map 哈希表
 */
void freeHashMap(HashTable * map);




/**
 * @brief 创建并查集
 * @param n 初始子集个数
 */
DSU* creatDSU(int n);

/**
 * @brief 查找并查集中元素的根节点
 * @param dsu 并查集
 * @param i 待查找元素
 */
int findDSU(DSU* dsu, int i);

/**
 * @brief 并
 * @param dsu 并查集
 * @param i 待合并元素i
 * @param i 待合并元素j
 */
void UniteDSU(DSU* dsu, int i, int j);

/**
 * @brief 判断两元素是否已合并
 * @param dsu 并查集
 * @param i 待查找元素i
 * @param i 待查找元素j
 */
bool DSUisConnected(DSU* dsu, int i, int j);

/**
 * @brief 释放并查集内存
 * @param dsu 并查集
 */
void freeDSU(DSU* dsu);





/**
 * @brief 初始化邻接矩阵
 * @param g 邻接矩阵
 * @param v 顶点个数
 */
void initMatrix(GraphMatrix* g, int v);

/**
 * @brief 邻接矩阵添加边
 * @param g 邻接矩阵
 * @param u 顶点u
 * @param v 顶点v
 */
void addEdgeMatrix(GraphMatrix* g, int u, int v);

/**
 * @brief 邻接矩阵深度优先遍历
 * @param g 邻接矩阵
 * @param curr 起始顶点
 * @param visited 记录顶点是否已访问
 */
int DFS_Matrix(GraphMatrix* g, int curr, bool* visited);

/**
 * @brief 邻接矩阵广度优先遍历
 * @param g 邻接矩阵
 * @param start 起始顶点
 */
void BFS_Matrix(GraphMatrix* g, int start);





/**
 * @brief 创建邻接表顶点
 * @param d 顶点
 */
Node* createNode(int d);

/**
 * @brief 初始化邻接表
 * @param v 顶点个数
 */
GraphList* initGraphList(int v);

/**
 * @brief 邻接表添加边
 * @param g 邻接表
 * @param u 顶点u
 * @param v 顶点v
 */
void addEdgeList(GraphList* g, int u, int v);

/**
 * @brief 邻接表深度优先遍历
 * @param g 邻接表
 * @param curr 起始顶点
 * @param visited 记录顶点是否已访问
 */
void DFS_List(GraphList* g, int curr, bool* visited);

/**
 * @brief 邻接表广度优先遍历
 * @param g 邻接表
 * @param start 起始顶点
 */
void BFS_List(GraphList* g, int start);

#endif //DATA_STRUCTURE_LEARNING_FUNCTION_H
