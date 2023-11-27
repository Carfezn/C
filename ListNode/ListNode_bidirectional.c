#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *previous;
    struct ListNode *next;
}ListNode;


//双向链表
void createListNode(ListNode *headNode , int array[] , int arrayLength) {
    ListNode *tailNode = headNode;
    for(int i = 0 ; i < arrayLength ; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = array[i];
        newNode->next = NULL;
        tailNode->next = newNode;
        tailNode->next->previous = tailNode;
        tailNode = tailNode->next;
    }
}

//添加至第几位
void addListNode(ListNode *headNode , int val , int position) { 
    ListNode *InsNode = headNode;
    for(int i = 0 ; i < position - 1 ; i++) {
        InsNode = InsNode->next;
    }
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    InsNode->next->previous = newNode;
    newNode->next = InsNode->next;
    newNode->previous = InsNode;
    InsNode->next = newNode;
    }

//遍历链表至结尾 再从链表未遍历至头节点
void whileNode(ListNode *headNode) {
    ListNode *InsNode = headNode->next;
    while (InsNode->next != NULL)
    {
        printf("%d\n" , InsNode->val);
        InsNode = InsNode->next;
    }
    printf("------------\n");
    while (InsNode != headNode)
    {
        printf("%d\n" , InsNode->val);
        InsNode = InsNode->previous;
    }
}

//删除第几位
void delListNode(ListNode *headNode , int position) {
    ListNode *InsNode = headNode->next;
    for(int i = 0 ; i < position-1 ; i++) {
        InsNode = InsNode->next;
    }
    InsNode->previous->next = InsNode->next;
    InsNode->next->previous = InsNode->previous;
    free(InsNode);
}

int main() {
    int array[] = {2342423,23,4,1415,65,72,54,2};
    ListNode *headNode = (ListNode*)malloc(sizeof(ListNode));
    headNode->previous = NULL;
    headNode->next = NULL;
    createListNode(headNode , array , sizeof(array)/sizeof(array[0]));
    whileNode(headNode);
    printf("-----------\n-----------\n");
    addListNode(headNode , 666 , 4);
    delListNode(headNode , 6);
    whileNode(headNode);
    return 0;
}