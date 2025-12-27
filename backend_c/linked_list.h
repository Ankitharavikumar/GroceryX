#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode {
    char item[50];
    int price;
    struct ListNode *next;
} ListNode;


ListNode* createNode(char item[], int price);
void insertEnd(ListNode **head, char item[], int price);
void displayList(ListNode *head);

#endif
