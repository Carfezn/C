#include <stdio.h>
#include <stdlib.h>

//连接链表
//
typedef struct ListNode
{
    int val;
    struct ListNode *nextNode;
}ListNode;

void createListNode_tail(ListNode *headNode , int array[] , int arrayLength) {
    ListNode *tailNode = headNode;
    for(int i = 0 ; i < arrayLength ; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = array[i];
        newNode->nextNode = NULL;
        tailNode->nextNode = newNode;
        tailNode = tailNode->nextNode;
    }
}

void createListNode_head(ListNode *headNode , int array[] , int arrayLength) {
    for(int i = 0; i < arrayLength ; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = array[i];
        newNode->nextNode = headNode->nextNode;
        headNode->nextNode = newNode;
    }
}

void selectListNode(ListNode *headNode) {
    ListNode *selectNode = headNode->nextNode;
    while (selectNode != NULL)
    {
        printf("%d\n", selectNode->val);
        selectNode = selectNode->nextNode;
    }
}

void mergeList(ListNode *h1 , ListNode *h2) {
    ListNode *newList = h1;
    while(newList->nextNode != NULL) {
        newList = newList->nextNode;
    }
    newList->nextNode = h2->nextNode;
}

int main() {
    int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,11,10,9,8,7,6,5,4,3,2,1,0};
    ListNode *headNode = (ListNode*)malloc(sizeof(ListNode));
    headNode->nextNode = NULL;
    ListNode *anotherHead = (ListNode*)malloc(sizeof(ListNode));
    createListNode_head(headNode , array , sizeof(array)/sizeof(array[0]));
    createListNode_tail(anotherHead , array , sizeof(array)/sizeof(array[0]));
    selectListNode(headNode);
    printf("\n");
    selectListNode(anotherHead);
    printf("\nthis is a kongge");
    mergeList(headNode , anotherHead);
    selectListNode(headNode);
}