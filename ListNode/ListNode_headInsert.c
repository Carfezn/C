#include <stdio.h>
#include <stdlib.h>

//头插法
typedef struct ListNode
{
    int val;
    struct ListNode *nextNode; 
}ListNode;

void createListNode(ListNode *headNode , int array[] , int arrayLength) {
    for(int i = 0; i < arrayLength ; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = array[i];
        newNode->nextNode = headNode->nextNode;
        headNode->nextNode = newNode;
    }
}

void selectListNode(ListNode *headNode) {
    ListNode *SListNode;
    SListNode = headNode->nextNode;
    while(SListNode != NULL) {
        printf("%d\n" , SListNode->val);
        SListNode = SListNode->nextNode;
    }
}

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,0};
    ListNode *headNode = (ListNode*)malloc(sizeof(ListNode));
    headNode->nextNode = NULL;
    createListNode(headNode,array,sizeof(array)/sizeof(array[0]));
    selectListNode(headNode);
    return 0;
}