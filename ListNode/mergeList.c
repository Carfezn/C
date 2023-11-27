#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

ListNode *createList(int array[] , int arrayLength) {
    ListNode *headNode , *tailNode , *newNode;
    headNode = (ListNode*)malloc(sizeof(ListNode));
    headNode->next = NULL;
    tailNode = headNode;
    newNode = NULL;
    for(int i = 0 ; i < arrayLength ; i++) {
        newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->next = NULL;
        newNode->val = array[i];
        tailNode->next = newNode;
        tailNode = tailNode->next; 
    }
    return headNode;
}

ListNode *mergeList(ListNode *headNode1 , ListNode *headNode2) {
    ListNode *h1 = headNode1->next;
    ListNode *h2 = headNode2->next;
    ListNode *allInNOde = (ListNode*)malloc(sizeof(ListNode));
    allInNOde->next = NULL;
    ListNode *reNode = allInNOde;
    while (h1 && h2)
    {
        if(h1->val <= h2->val) {
            allInNOde->next = h1;
            allInNOde = h1;
            h1 = h1->next;
        }
        else {
            allInNOde->next = h2;
            allInNOde = h2;
            h2 = h2->next;
        }
    }
    
    allInNOde->next = h1?h1:h2;
    return reNode;
}

int main() {
    int array1[] = {1,4,6,56,77,108};
    int array2[] = {2,4,45,67,456};
    ListNode *h1 = createList(array1 , sizeof(array1)/sizeof(array1[0]));
    ListNode *h2 = createList(array2 , sizeof(array2)/sizeof(array2[0]));
    ListNode *h3 = mergeList(h1 , h2);
    h3 = h3->next;
    while (h3)
    {
        printf("%d\n" , h3->val);
        h3 = h3->next;
    }
}