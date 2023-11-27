#include <stdio.h>
#include <stdlib.h>


//尾插法
typedef struct ListNode
{
    int val;
    struct ListNode *nextNode;
}ListNode;

void createListNode(ListNode *headNode , int array[] , int arrayLength) {
    ListNode *tailNode = headNode;
    for(int i = 0 ; i < arrayLength ; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = array[i];
        newNode->nextNode = NULL;
        tailNode->nextNode = newNode;
        tailNode = tailNode->nextNode;
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

int main() {
    int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,11,10,9,8,7,6,5,4,3,2,1,0};
    ListNode *headNode = (ListNode*)malloc(sizeof(ListNode));
    createListNode(headNode , array , sizeof(array)/sizeof(array[0]));
    selectListNode(headNode);
}