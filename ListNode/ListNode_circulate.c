#include <stdio.h>
#include <stdlib.h>
//循环链表

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

void becomeCirculate(ListNode *headNode) {
    ListNode *InsNode = headNode->nextNode;
    while (InsNode->nextNode != NULL)
    {
        InsNode = InsNode->nextNode;
    }
    InsNode->nextNode = headNode;
}

void selectCirculate(ListNode *headNode) {
    ListNode *InsNode = headNode->nextNode;
    while(InsNode != headNode) {
        printf("%d\n" , InsNode->val);
        InsNode = InsNode->nextNode;
    }
}

int main() {
    int array[] = {1231,2131,4535,324,112,5,1213,4};
    ListNode *headNode = (ListNode*)malloc(sizeof(ListNode));
    headNode->nextNode = NULL;
    createListNode(headNode , array , sizeof(array)/sizeof(array[0]));
    selectListNode(headNode);
    printf("------------\n");
    becomeCirculate(headNode);
    selectCirculate(headNode);
}