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

int findList(Node *L, int k)
{
    if (k <= 0) return 0;
    Node *fast = L->next;
    Node *slow = L->next;
    // 先让fast走k步
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL) return 0;
        fast = fast->next;
    }
    // 然后一起走
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // slow就是倒数第k个
    printf("%d\n", slow->data);
    return 1;
}

int main()
{
    Node *list = initList();
    insertHead(list, 11);
    insertHead(list, 22);
    insertHead(list, 33);
    int res = findList(list, 2);
    if (res == 1)
    {
        // 已经输出
    }
    else
    {
        printf("没找到\n");
    }
    return 0;
}