#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

ListNode* createNode(char item[], int price) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    strcpy(newNode->item, item);
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(ListNode **head, char item[], int price) {
    ListNode *newNode = createNode(item, price);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ListNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(ListNode *head) {
    if (head == NULL) {
        printf("No purchase history available\n");
        return;
    }

    printf("Purchase History:\n");
    ListNode *temp = head;
    while (temp != NULL) {
        printf("Item: %s | Price: %d\n", temp->item, temp->price);
        temp = temp->next;
    }
}
