#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

union unode
{
    double data;
    struct node *next;
};

int nodeCount(struct node *headNode)
{
    int index = 0;
    while (headNode != NULL)
    {
        index++;
        headNode = headNode->next;
    }
    return index;
}

int nodeCountWithAddressOfLastNode(struct node **lastNodeAdd)
{
    struct node *prevNode;
    int index = 0;
    while (*lastNodeAdd != NULL)
    {
        index++;
        prevNode = *lastNodeAdd;
        *lastNodeAdd = (*lastNodeAdd)->next;
    }
    *lastNodeAdd = prevNode;
    return index;
}

struct node *nodeAddrAtIndex(struct node *node, int index)
{
    // struct node* prevNode;
    int i = 0;
    while (node != NULL)
    {
        if (i == index)
            return node;
        node = node->next;
        i++;
    }
}

void traverseLinkedList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct node *insertAtStart(struct node *node, int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = node;
    return newNode;
}

void insertAtEnd(struct node *node, int data)
{
    // Traversing for Getting address of last node
    struct node *lastNodeAdd;
    while (node != NULL)
    {
        lastNodeAdd = node;
        node = node->next;
    }
    // Creating new node
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    // Linking new node with lastnode
    lastNodeAdd->next = newNode;
}

int insertAtIndex(struct node *headNode, int data, int index)
{
    // lastNodeAdd -> &headNode -> actual_Node
    // struct node *lastNodeAdd = &headNode;

    // After using nodeCount function lastNodeAdd will have a last Node Address
    // nodeCountWithAddressOfLastNode(lastNodeAdd);

    int maxIndex = nodeCount(headNode);
    if ((index == 0) || (index > maxIndex) || (index < -1 * maxIndex))
        return -1;

    index = (index < 0) ? maxIndex + ++index : index;

    // Creating a Node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    int i = 0;
    while (i < index - 1)
    {
        headNode = headNode->next;
        i++;
    }
    // linking newNode with nextNode and prevNode to newNode
    newNode->next = (index == maxIndex) ? NULL : headNode->next;
    headNode->next = newNode;
    return 0;
}

struct node *insertAfterNode(int data, struct node *node4reference)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    newNode->next = node4reference->next;
    node4reference->next = newNode;
    return newNode;
}

struct node *deleteAtStart(struct node *node)
{
    struct node *ptr = node;
    node = node->next;
    free(ptr);
    return node;
}

int deleteAtEnd(struct node *node)
{
    struct node *prevNode;
    struct node *prevPrevNode;
    while (node != NULL)
    {
        prevPrevNode = prevNode;
        prevNode = node;
        node = node->next;
    }
    free(prevNode);
    prevPrevNode->next = NULL;
    return 0;
}

int deleteAtIndex(struct node *node, int index)
{
    struct node *prevNode;
    if (index < 0)
        index = nodeCount(node) + ++index;
    int i = 0;
    while (node != NULL)
    {
        if (i == index)
        {
            prevNode->next = node->next;
            free(node);
            return 0;
        }
        prevNode = node;
        node = node->next;
        i++;
    }
    return -1;
}

int deleteAfterNode(struct node *node)
{
    struct node *node4delete = node->next;
    node->next = node4delete->next;
    free(node4delete);
}

int main(void)
{
    /* Creating a Pointers for structure */
    struct node *head;
    struct node *second;
    struct node *third;

    /* Creating memory for pointer in Heap */
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    /* Entering Data in Nodes */
    head->data = 20;
    second->data = 40;
    third->data = 60;

    /* Linking Node for Creating a Chain */
    head->next = second;
    second->next = third;
    third->next = NULL;

    /* Minimum Required Functionality */
    printf("Traversal Before Inserting: ");
    traverseLinkedList(head);

    // inserting Node at the beginning of Linked List
    struct node *beforeHead = insertAtStart(head, 100);
    printf("\nTraversal After Inserting: ");
    traverseLinkedList(beforeHead);

    // inserting Node at the Ending of Linked List
    insertAtEnd(beforeHead, 100);
    printf("\nTraversal After Inserting: ");
    traverseLinkedList(beforeHead);

    // inserting Node at an index of Linked List
    insertAtIndex(beforeHead, 55, 6);
    printf("\nTraversal After Inserting: ");
    traverseLinkedList(beforeHead);

    // inserting Node after a node in Linked List
    insertAfterNode(11, beforeHead);
    printf("\nTraversal After Inserting: ");
    traverseLinkedList(beforeHead);

    // Deletation of Nodes
    // Deleting Node at the beginning of Linked List
    beforeHead = deleteAtStart(beforeHead);
    printf("\nTraversal After deleting: ");
    traverseLinkedList(beforeHead);

    // Deleting Node at the Ending of Linked List
    deleteAtEnd(beforeHead);
    printf("\nTraversal After deleting: ");
    traverseLinkedList(beforeHead);

    // Deleting Node at an index of Linked List
    if (deleteAtIndex(beforeHead, 2) != -1)
    {
        printf("\nTraversal After deleting: ");
        traverseLinkedList(beforeHead);
    }

    // Deleting Node after a node in Linked List
    if (deleteAfterNode(head) != -1)
    {
        printf("\nTraversal After deleting: ");
        traverseLinkedList(beforeHead);
    }

    for (int atIndex = 0; atIndex < nodeCount(beforeHead); atIndex++)
        printf("\nAddress at %d: %d", atIndex, nodeAddrAtIndex(beforeHead, atIndex));

    printf("\nsizeof struct node: %d", sizeof(struct node));
    printf("\ndifference b/w pointers: %d", (int)nodeAddrAtIndex(beforeHead, 0) - (int)nodeAddrAtIndex(beforeHead, 1));

    printf("\nSize of pointer : %d", sizeof(int *));
    printf("\nSize of integer : %d", sizeof(int *));

    union unode obj1;
    obj1.data = 2.34l;
    printf("\nSize of union : %d", sizeof(obj1));
    return 0;
}