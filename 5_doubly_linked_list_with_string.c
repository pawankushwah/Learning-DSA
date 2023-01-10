#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *prev;
    char data[10];
    struct node *next;
} Node;

int createDoublyLinkedList(Node **head, char *data, int dataSize)
{
    *head = (Node *)malloc(sizeof(Node));
    Node *node = *head;
    Node *nextNode, *prevNode;

    for (int i = 0; i <= dataSize; i++)
    {
        strcpy(node->data,data[i]);
        node->prev = (i == 0) ? NULL : prevNode;
        prevNode = node;
        nextNode = (Node *)malloc(sizeof(Node));
        node = node->next = (i == dataSize)? NULL : nextNode;
    }
    return 0;
}

int traverse(Node *head)
{
    while(head != NULL){
        printf("%s ",head->data);
        head = head->next;
    }
}

int main(void)
{
    Node *head;
    char data[][10] = {"Pawan","Rahul","Preetam","Prathmesh","Aditya","Shikhar"};
    // printf("%d",strlen(data));
    if(createDoublyLinkedList(&head,data,strlen(data)) == 0)
        traverse(head);
    else
        printf("There is an error");
    return 0;
}