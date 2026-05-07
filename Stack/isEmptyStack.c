#include <Stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
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

int main()
{
    Stack s;
    initStack(&s);
    printf("Stack initialized. Top index: %d\n", s.top);
    isEmptyStack(&s);
    return 0;
}