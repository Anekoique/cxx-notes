#include<cstdio>
#include<cstdlib>

int i = 0;

struct List
{
    int data;
    struct List* next;
};

struct List* listCreate()
{
	int data;
    struct List* head = NULL;
    struct List* pre = NULL;
    struct List* current = NULL;
    
    while(scanf("%d",&data) && data != -1)
    {
        current = (struct List*)malloc(sizeof(struct List));
        if(head == NULL)
            head = current;
        else
            pre->next = current;
        current->next = NULL;
        current->data = data;
        i++;
        pre = current;
    }
    return head;
}

int Descending(float a, float b) {
	return a > b;
}

int Ascending(float a, float b) {
	return a < b;
}

struct List* listSort(struct List** head, int n, int(*compare)(float a, float b)) {
	int i, j;
	struct List *temp;
    struct List *current;
    struct List *init = *head;
	for (i = 0; i < n; i++) {
		current = *head;
		temp = *head;
		for (j = 0; j < n - i - 1; j++) {
			if ((*compare)(current->data, current->next->data)) {
				if (current == *head) {
					*head = current->next;
					temp = current->next;
					current->next = temp->next;
					temp->next = current;
                    init = *head;
				}
				else {
					temp->next = current->next;
					current->next = current->next->next;
					temp->next->next = current;
					temp = temp->next;
				}
			}
			else {
				temp = current;
				current = current->next;
			}
		}
	}
	return init;
}

void listSort2(struct List* head, int n, int(*compare)(float a, float b)) {
	int i, j;
	struct List *temp;
    struct List *current;
	for (i = 0; i < n; i++) {
		current = head;
		temp = head;
		for (j = 0; j < n - i - 1; j++) {
			if ((*compare)(current->data, current->next->data)) {
				if (current == head) {
					head = current->next;
					temp = current->next;
					current->next = temp->next;
					temp->next = current;
				}
				else {
					temp->next = current->next;
					current->next = current->next->next;
					temp->next->next = current;
					temp = temp->next;
				}
			}
			else {
				temp = current;
				current = current->next;
			}
		}
	}
	// return init;
}

struct List* listPlusCreate()
{
	int data;
    struct List* head;
	head = (List*)malloc(sizeof(List));
    struct List* current = head;
    
    while(scanf("%d",&data) && data != -1)
    {
        current->next = (List*)malloc(sizeof(List));
		current = current->next;
		current->data = data;
		current->next = NULL;
		i++;
	}
    return head;
}

void listSort3(struct List* head, int n, int (*compare)(float a, float b))
{
	int i, j;
	struct List *temp;
    struct List *current;
	for (i = 0; i < n; i++) {
		temp = head;
		current = head->next;
		for (j = 0; j < n - i - 1; j++) {
			if ((*compare)(current->data, current->next->data)) {
				temp->next = current->next;
				current->next = current->next->next;
				temp->next->next = current;
				temp = temp->next;
			}
			else {
				temp = current;
				current = current->next;
			}
		}
	}
}

int main()
{
    //struct List* head = listCreate();
	struct List* headplus = listPlusCreate();
    //listSort2(headplus, i, Descending);
	listSort3(headplus, i, Descending);
    while(headplus!=NULL)
    {
        printf("%d", headplus->data);
        headplus = headplus->next;
    }
}
