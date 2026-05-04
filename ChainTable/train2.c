#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
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

int getLenght(Node *L)
{
    Node *p = L;
    int len = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

Node *getTail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 初始化一个带有元素的链表
Node *initListWithElem(ElemType e)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = e;
    head->next = NULL;
    return head;
}

Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
}

// 尾插法插入一个节点
Node *insertTailWithNode(Node *tail, Node *node)
{
    tail->next = node;
    node->next = NULL;
    return node;
}

// 找到两个链表的交点
Node *findIntersection(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    int lenA = getLenght(headA);
    int lenB = getLenght(headB);
    int step = 0;
    if (lenA > lenB)
    {
        step = lenA - lenB;
        for (int i = 0; i < step; i++) // 让长的链表先走step步
        {
            headA = headA->next;
        }
    }
    else
    {
        step = lenB - lenA;
        for (int i = 0; i < step; i++)
        {
            headB = headB->next;
        }
    }
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main()
{
    Node *listA = initList();
    Node *listB = initList();
    Node *tailA = getTail(listA);
    Node *tailB = getTail(listB);
    tailA = insertTail(tailA, 'l');
    tailA = insertTail(tailA, 'o');
    tailA = insertTail(tailA, 'a');
    tailA = insertTail(tailA, 'd');
    tailB = insertTail(tailB, 'b');
    tailB = insertTail(tailB, 'e');

    Node *nodeI = initListWithElem('i');
    tailA = insertTailWithNode(tailA, nodeI);
    tailB = insertTailWithNode(tailB, nodeI);
    Node *nodeN = initListWithElem('n');
    tailA = insertTailWithNode(tailA, nodeN);
    tailB = insertTailWithNode(tailB, nodeN);
    Node *nodeG = initListWithElem('g');
    tailA = insertTailWithNode(tailA, nodeG);
    tailB = insertTailWithNode(tailB, nodeG);

    listNode(listA);
    listNode(listB);

    printf("%c\n", findIntersection(listA, listB)->data);
    return 0;
}