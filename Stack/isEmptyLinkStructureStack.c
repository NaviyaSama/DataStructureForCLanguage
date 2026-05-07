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

int main()
{
    Stack *s = initStack();
}