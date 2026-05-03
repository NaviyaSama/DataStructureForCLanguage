// 顺序表-在尾部添加元素
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

int main()
{
    SeqList list;
    initList(&list);
    printf("初始化成功，目前长度占用%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));
    appendElem(&list, 231);
    return 0;
}