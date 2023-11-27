#include <stdio.h>
#include <stdlib.h>
#define MaxNum 100


typedef struct
{
    int *top;
    int *base;
    int StackSize;
}sequenceStack;

sequenceStack *createStack() {
    sequenceStack *s1 = (sequenceStack*)malloc(sizeof(sequenceStack));
    s1->base = (int*)malloc(sizeof(int)*MaxNum);
    s1->top = s1->base;
    s1->StackSize = MaxNum;
    return s1;
}

int push(sequenceStack *s1 , int num) {
    if((s1->top - s1->base) == s1->StackSize) {
        printf("stack full\n");
        exit;
    }
    *s1->top++ = num;
    return *s1->top-1;
}

int getTop(sequenceStack *s1) {
    if(s1->top == s1->base) {
        printf("stack empty\n");
        exit;
    }
    return *--s1->top;
}

int main() {
    sequenceStack *s1 = createStack();
    push(s1 , 10);
    printf("%d\n" , getTop(s1));
}