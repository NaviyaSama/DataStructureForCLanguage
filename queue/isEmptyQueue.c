#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Queue q; // 使用栈上的队列结构体
    initQueue(&q);
    printf("队列初始化成功！\n");
    printf("front: %d, rear: %d\n", q.front, q.rear);
    isEmpty(&q);
    return 0;
}