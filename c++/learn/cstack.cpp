#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *next;
    struct list *pre;
};

void stackPush(struct list *stack,int x)
{
    struct list *current = stack;
    struct list *pre;
    while (current->next != stack){
        if (current->next == NULL)
            break;
        current = current->next;
    }
    current->next = (struct list*)malloc(sizeof(struct list));
    current->next->pre = current;
    current = current->next;
    current->data = x;
    current->next = stack;
    stack->pre = current;
}

void queuePush(struct list *queue, int x)
{
    struct list *current = queue;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = (struct list*)malloc(sizeof(struct list));
    current = current->next;
    current->data = x;
    current->next = NULL;
}

void stackShow(struct list *stack)
{
    struct list *current = stack;
    while (current->next != stack)
        current = current->next;
    while (current != stack){
        printf("%5d", current->data);
        current = current->pre;
    }
}

void queueShow(struct list *queue)
{
    struct list *current = queue->next;
    while(current->next != NULL)
    {
        printf("%5d", current->data);
        current = current->next;
    }
}

int main()
{
    int x;
    struct list *stack;
    struct list *queue;
    stack = (struct list*)malloc(sizeof(struct list));
    stack->next = NULL;
    queue = (struct list*)malloc(sizeof(struct list));
    queue->next = NULL;
    while (scanf("%d", &x) != EOF)
    {
        if (x > 0)
            stackPush(stack, x);
        else if (x < 0)
            queuePush(queue, x);
    }
    stackShow(stack);
    queueShow(queue);
}