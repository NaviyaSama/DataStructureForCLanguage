#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct stack
{
    ElemType data;
    struct stack *next;
} Stack;

Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

int isEmpty(Stack *s)
{
    if (s->next == NULL)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(Stack *s, ElemType e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

int popStack(Stack *s, ElemType *e)
{
    if (s->next == NULL)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    Stack *q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}

int main()
{
    Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    ElemType e;
    popStack(s, &e);
    printf("%d\n", e);
    return 0;
}