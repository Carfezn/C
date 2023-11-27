#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct  listNode *next;
}listNode;


//动态数组的空间开辟与赋值
int main() {
    listNode *l1;
    l1 = (listNode*)malloc(sizeof(listNode)*10);
    for(int i = 0 ; i < 10 ; i++) {
        (l1+i)->val = i;    
    }
    for(int i = 0 ; i < 10 ; i++) {
        printf("%d" , (l1+i)->val);    
    }
}