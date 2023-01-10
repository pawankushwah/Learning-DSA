/* Circular Linked list */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float data;
    struct node *next;
} Node;

Node *nodeAddrAtIndex(Node *node, int index)
{
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}

int createCyclicLinkedList(Node **head, float *data, int dataSize)
{
    *head = (Node *)malloc(sizeof(Node));
    Node *node = *head;
    Node *nextnode;

    for (int i = 0; i < dataSize; i++)
    {
        node->data = data[i];
        if (i == dataSize - 1)
        {
            node->next = *head;
            return 0;
        }
        nextnode = (Node *)malloc(sizeof(Node));
        node = node->next = nextnode;
    }
}

int traverse(Node *head)
{
    Node *node = head;
    do
    {
        printf("%.2f ", node->data);
        node = node->next;
    } while (node != head);
}

int insertAtStart(Node *head, float data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    // Managing Data
    node->data = head->data;
    head->data = data;

    // Managing Links
    node->next = head->next;
    head->next = node;
    return 0;
}

int insertAtIndex(Node *head, float data, int index)
{
    if (index == 0)
        return insertAtStart(head, data);
    for (int i = 1; i < index; i++)
    {
        head = head->next;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = head->next;
    head->next = node;
    return 0;
}

int insertAtEnd(Node *head, float data)
{
    Node *node = head;
    do
    {
        node = node->next;
    } while (node->next != head);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
    return 0;
}

int insertAfterNode(Node *node, float data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
    return 0;
}

int deleteAtStart(struct node *head)
{
    struct node *nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
    free(nextNode);
    return 0;
}

int deleteAtEnd(struct node *head)
{
    // for now we are using node4delete as a node only
    struct node *node = head;
    for (int i = 1; (node->next)->next != head; i++)
    {
        node = node->next;
    }
    free(node->next);
    node->next = head;
    return 0;
}

int deleteAtIndex(struct node *head, int index)
{
    if (index == 0)
        return deleteAtStart(head);
    for (int i = 1; i < index; i++)
    {
        head = head->next;
    }
    struct node *node4delete = head->next;
    head->next = node4delete->next;
    free(node4delete);
    return 0;
}

int deleteAfterNode(struct node *node)
{
    struct node *node4delete = node->next;
    node->next = node4delete->next;
    free(node4delete);
    return 0;
}

int main(void)
{
    Node *head;
    float data[] = {12.2, 10.0, 45.9, 23.3, 56.4, 78.0};
    int dataSize = 6;
    createCyclicLinkedList(&head, data, dataSize);
    traverse(head);

    insertAtStart(head, 10);
    printf("\n");
    traverse(head);

    insertAtIndex(head, 20, 4);
    printf("\n");
    traverse(head);

    insertAtEnd(head, 20);
    printf("\n");
    traverse(head);

    insertAfterNode(nodeAddrAtIndex(head, 2), 100);
    printf("\n");
    traverse(head);

    deleteAtStart(head);
    printf("\n");
    traverse(head);

    deleteAtIndex(head, 1);
    printf("\n");
    traverse(head);

    deleteAfterNode(nodeAddrAtIndex(head, 2));
    printf("\n");
    traverse(head);

    deleteAtEnd(head);
    printf("\n");
    traverse(head);

    return 0;
}