#include<cstdio>
#include<cstdlib>
struct List
{
    int data;
    struct List* next;
    struct List* pre;
};

struct List* listCreate()
{
    int data;
    struct List* head;
    struct List* current;
    struct List* pre;
    head = (struct List*)malloc(sizeof(struct List));
    current = head;
    pre = head;
    while (scanf("%d", &data) && data != -1)
    {
        current->next = (struct List*)malloc(sizeof(struct List));
        current = current->next;
        current->data =  data;
        current->next = NULL;
        current->pre = pre;
        pre = current;
    }
    current->next = head;
    head->pre = current;
    return head;
}

void printNext(struct List* head)
{
    struct List* current = head;
    while(current->next!=head){
        current = current->next;
        printf("%d", current->data);
    }
}

void printPre(struct List* head)
{
    struct List* current = head;
    while(current->pre!=head){
        current = current->pre;
        printf("%d", current->data);
    }
}

void deleteNode(struct List* head, int data)
{
    struct List* current = head;
    while (current->next != head)
    {
        if (current->next->data != data)
        {
            current = current->next;
        }else{
            current->next = current->next->next;
            current->next->pre = current;
        }
    }
}

int main()
{
    int data;
    struct List* head = listCreate();
    printNext(head);
    printf("\n");
    scanf("%d", &data);
    deleteNode(head, data);
    printPre(head);
}