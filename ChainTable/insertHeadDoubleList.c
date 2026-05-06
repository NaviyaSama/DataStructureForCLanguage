#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *prev, *next;
} DLinkNode;

DLinkNode *initList()
{
    DLinkNode *head = (DLinkNode *)malloc(sizeof(DLinkNode));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

void listNode(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 头插法
int insertHead(DLinkNode *L, ElemType e)
{
    DLinkNode *p = (DLinkNode *)malloc(sizeof(DLinkNode));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if (L->next != NULL)
    {
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}

int main()
{
    DLinkNode *list = initList();
    insertHead(list, 1);
    insertHead(list, 2);
    insertHead(list, 3);
    insertHead(list, 4);
    listNode(list);
    return 1;
}