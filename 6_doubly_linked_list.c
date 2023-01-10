#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;

int createDoublyLinkedList(Node **head, int *data, int dataSize)
{
    Node *node = (Node *)malloc(sizeof(Node));
    *head = node;
    Node *nextNode, *prevNode;

    for (int i = 0; i < dataSize; i++)
    {
        node->data = data[i];
        node->prev = (i == 0) ? NULL : prevNode;
        prevNode = node;
        nextNode = (Node *)malloc(sizeof(Node));
        node->next = (i == dataSize - 1)? NULL : nextNode;
        node = node->next;
    }
    return 0;
}

int traverse(Node *head)
{
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main(void)
{
    Node *head;
    // char data[][10] = {"Pawan","Rahul","Preetam","Prathmesh","Aditya","Shikhar"};
    int data[] = {12,45,23,45,67};
    int dataSize = 5;
    // printf("%d",strlen(data));
    createDoublyLinkedList(&head,data,dataSize);

    if(head != NULL){
        printf("Traversing\n");
        traverse(head);
    }
    else
        printf("There is an error");
    return 0;
}