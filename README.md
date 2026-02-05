# Data-Structure
Used for record learning of data structure

## Function Catalog
1、QuickSort  
2、Hash Table (Separate Chaining)  
3、Disjoint Set Union









### offical string related function
strlen(s) 返回字符串长度  
strcpy(a, b) 将字符串b复制到a中   
strncpy(a, b, n) 将b中前n个字符复制到a中   
strdup(s) 拷贝并分配内存 （记得free）  
strcat(a, b) 把b接在a后面  
strcmp(s1, s2)/strncmp(s1, s2, n) 比较，相等返回0  
strchr(s, c)/strrchr(s, c) 查找c第一次/最后一次出现的位置  
strstr(s1, s2) 在大字符串里找小字符串  
strtok(s, a) 字符串切分  
sprintf(buf, "%d + %d = %d", 1, 2, 3); -> buf 变成 "1 + 2 = 3"  
sscanf("2026-02-04", "%d-%d-%d", &y, &m, &d)  
isdigit(c)/isalpha(c)/isspace(c)/tolower(c)/toupper(c)