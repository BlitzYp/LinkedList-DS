#include <stdio.h>
#include <stdlib.h>

typedef struct listNode 
{
    int value;
    struct listNode* next;
} listNode;

typedef struct linkedList 
{
    listNode* head;
    int size;
} linkedList;


listNode* createNode(int value)
{
    listNode* new_node = malloc(sizeof(listNode));
    if (new_node == NULL) 
    {
        fprintf(stderr, "COuld not allocate space for the list node\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insertAtBegin(int value, linkedList* list)
{
    listNode* new_node = createNode(value);
    if (list->head != NULL)
        new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void insert(int value, linkedList* list)
{
    if (list->head == NULL || list->head->value > value)
    {
        insertAtBegin(value, list);
        return;
    }
    
    listNode* new_node = createNode(value);
    listNode* current = list->head;
    listNode* prev = NULL;
    while (current != NULL && value > current->value)
    {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) prev->next = new_node;
    new_node->next = current;
    current = new_node;
    list->size++;
}

void display(linkedList* list)
{
    listNode* current = list->head;
    while (current != NULL)
    {
       printf("%d\n", current->value); 
       current = current->next;
    }
}

void insertAtPos(int index, linkedList* list, int value) 
{
    listNode* new_node = createNode(value);
    int counter = 0;
    listNode* current = list->head;
    listNode* prev = NULL;
    while (counter++ < index && current != NULL) 
    {
        prev = current;
        current = current->next;
    }
    prev->next = new_node;
    new_node->next = current;
    current = new_node;
}

void delete(int value, linkedList* list)
{
    listNode* current = list->head;
    listNode* prev = NULL;
    while (current->value != value)
    {
        prev = current;
        current = current->next;
    }
    if (prev) prev->next = current->next;
    else list->head = current->next;
    free(current);
}


int main(void)
{
    linkedList* list = malloc(sizeof(linkedList));
    list->size = 0;
    insert(4, list);
    insert(2, list);
    insert(6, list);
    insertAtPos(1, list, 23);
    delete(2, list);
    display(list);
}