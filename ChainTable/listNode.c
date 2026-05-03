#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *list = initList();
    insertHead(list, 11);
    insertHead(list, 22);
    insertHead(list, 33);
    listNode(list);
    return 1;
}