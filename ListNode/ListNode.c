#include <stdio.h>
#include <stdlib.h>

//单链表：尾插法
//自己写的
typedef struct Book
{
    int bookNum;
    struct Book *nextBook;
}Book;

void addBook(Book *bookHead) {
    Book *bookIns;
    bookIns = bookHead;
    Book *bookNode = (Book*)malloc(sizeof(Book));
    bookNode->nextBook = NULL;
    printf("Input your number\n");
    scanf("%d", &bookNode->bookNum);
    while(bookIns->nextBook != NULL) {
        bookIns = bookIns->nextBook;
    }
    bookIns->nextBook= bookNode;
}

void SelectBook(int bookNum , Book *bookHead) {
    Book *bookIns;
    bookIns = bookHead;
    while(bookIns->nextBook != NULL) {
        bookIns = bookIns->nextBook;
    }
    if(bookIns->bookNum != bookNum) {
        printf("NO Such Book\n");
        return;
    }
    printf("Find this num %d\n" , bookNum);
    return;
}

int main(){
    Book *bookHead = (Book*)malloc(sizeof(Book));
    bookHead->nextBook = NULL;
    int num;
    while(num != -1) {
    printf("Input num 1 or 2 to Select Add or Select\n");
    scanf("%d", &num);
    switch (num)
    {
    case 1 : addBook(bookHead);
        break;
    case 2 : printf("Input number\n");
             int bookNum;
             scanf("%d", &bookNum);
             SelectBook(bookNum, bookHead);
             break;
    }
    }
}
