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

void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取尾结点
Node *get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

Node *reverseList(Node *head)
{
    Node *first = NULL;
    Node *second = head->next;
    Node *third;

    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *hd = initList();
    hd->next = first;
    return hd;
}

void reOrderList(Node *head)
{

    // 快慢指针找到链表中点
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 反转后半部分链表
    Node *first = NULL;        // 反转后半部分链表的头结点
    Node *second = slow->next; // 反转后半部分链表的第一个结点
    slow->next = NULL;         // 将链表分成两部分，前半部分以head为头结点，后半部分以second为头结点
    Node *third = NULL;        // 反转后半部分链表的第三个结点
    while (second != NULL)
    {
        third = second->next; // 记录second的下一个结点
        second->next = first; // 将second的next指向first，实现反转
        first = second;       // first向后移动一位
        second = third;       // second向后移动一位
    }

    // 交叉合并链表
    Node *p1 = head->next;
    Node *q1 = first;
    Node *p2, *q2;
    while (p1 != NULL && q1 != NULL)
    {
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
}

int main()
{
    Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    listNode(list);
    reOrderList(list);
    listNode(list);
    return 0;
}