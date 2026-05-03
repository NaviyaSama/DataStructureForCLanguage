// 顺序表-初始化
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

int main()
{
    SeqList list;
    initList(&list);
    printf("初始化成功，目前长度占用%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));
    return 0;
}