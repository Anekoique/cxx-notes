#include<cstdio>
#include<cstdlib>

typedef struct node
{
    int num;
    struct node* next;
}Node;

Node* nodeCreate(int M)
{
    int i = 1;
    Node* head;
    head = (Node*)malloc(sizeof(Node));
    head->num = i;
    head->next = NULL;
    Node* current = head;
    for (i = 2; i <= M + 1; i++)
    {
        if (i != M+1)
        {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
            current->num = i;
            current->next = NULL;
        }else
        {
            current->next = head;
            break;
        }
    }
    return head;
}

Node* listOut(Node* head, int M, int N)
{
    Node* current = head;
    Node* pre = head;
    Node* kill;
    Node* newhead;
    Node* newcurrent;
    while (pre->next != head)
        pre = pre->next;
    for (int i = 0; i < M; i++)
    {
        if (i == M - 2)
        {
            for (int j = 1; j < N; j++)
            {
                pre = pre->next;
                current = current->next;
            }
            newcurrent->next = (Node*)malloc(sizeof(Node));
            newcurrent = newcurrent->next;
            newcurrent->num = current->num;
            newcurrent->next = NULL;
            newcurrent->next = (Node*)malloc(sizeof(Node));
            newcurrent = newcurrent->next;
            newcurrent->num = pre->num;
            newcurrent->next = newhead;
            free(current);
            free(pre);
            break;
        }
        for (int j = 1; j < N; j++)
        {
            pre = pre->next;
            current = current->next;
        }
        if (!i)
        {
            newhead = (Node*)malloc(sizeof(Node));
            newhead->num = current->num;
            newcurrent = newhead;
            kill = (Node*)malloc(sizeof(Node));
            kill = current;
            current = current->next;
            pre->next = current;
            free(kill);
        }
        else
        {
            newcurrent->next = (Node*)malloc(sizeof(Node));
            newcurrent = newcurrent->next;
            newcurrent->num = current->num;
            kill = (Node*)malloc(sizeof(Node));
            kill = current;
            current = current->next;
            pre->next = current;
            free(kill);
        }
    }
    return newhead;
}

void listOut2(Node* head, int M, int N)
{
    Node* current = head;
    Node* pre = head;
    Node* kill = NULL;
    while (pre->next != head)
        pre = pre->next;
    for (int i = 0; i < M; i++)
    {
        if (i == M-2){
            for (int j = 1; j < N; j++)
            {
                pre = pre->next;
                current = current->next;
            }
            printf("%4d", current->num);
            printf("%4d", pre->num);
            free(current);
            free(pre);
            break;
        }
        for (int j = 1; j < N; j++)
        {
            pre = pre->next;
            current = current->next;
        }
        kill = (Node*)malloc(sizeof(Node));
        kill = current;
        printf("%4d", current->num);
        current = current->next;
        pre->next = current;
        free(kill);
    }
}

int main()
{
    int M,x,y;
    scanf("%d %d %d", &M, &x, &y);
    Node* head = nodeCreate(M);
    Node* newhead = listOut(head, M, x);
    listOut2(newhead, M, y);
    return 0;
}