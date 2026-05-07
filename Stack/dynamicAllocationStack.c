#include <Stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int top;
} Stack;

Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

int isEmptyStack(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return 1;
    }
    else
    {
        printf("Stack is not empty. Top index: %d\n", s->top);
        return 0;
    }
}

int pushStack(Stack *s, ElemType e)
{
    if (s->top == MAXSIZE - 1)
    {
        printf("Stack overflow. Cannot push element %d\n", e);
        return 0; // Push failed
    }
    else
    {
        s->top++;
        s->data[s->top] = e;
        return 1; // Push successful
    }
}

ElemType popStack(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

int getTop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main()
{
    Stack *s = initStack();

    pushStack(s, 10);
    pushStack(s, 20);
    pushStack(s, 30);
    pushStack(s, 40);

    ElemType e;
    popStack(s, &e);
    printf("%d\n", e);
    getTop(s, &e);
    printf("%d\n", e);
}