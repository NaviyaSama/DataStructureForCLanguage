// 顺序表-遍历
#include <stdio.h>

#define MAXSIZE 100
typedef int ElementType;

typedef struct
{
    ElementType data[MAXSIZE];
    int length;
} SeqList;

void initList(SeqList *L)
{
    L->length = 0;
}

int appendElem(SeqList *L, ElementType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

void listElem(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int insertElem(SeqList *L, int pos, ElementType e)
{
    if (pos <= L->length)
    {
        for (int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

int deleteElem(SeqList *L, int pos, ElementType *e)
{
    *e = L->data[pos - 1];
    if (pos < L->length)
    {
        for (int i = pos; i < L->length; i++)
        {
            L->data[i - 1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}

int findElem(SeqList *L, ElementType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    SeqList list;
    initList(&list);
    printf("初始化成功，目前长度占用%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));
    appendElem(&list, 231);
    appendElem(&list, 54);
    appendElem(&list, 12);
    appendElem(&list, 76);
    appendElem(&list, 43);
    listElem(&list);
    insertElem(&list, 3, 99);
    listElem(&list);
    ElementType delData;
    deleteElem(&list, 4, &delData);
    printf("被删除的数据为:%d\n", delData);
    listElem(&list);
    ElementType findData = 99;
    printf("查找的元素%d在第%d位", findData, findElem(&list, findData));
    return 0;
}