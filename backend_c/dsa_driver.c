#include <stdio.h>
#include <string.h>

#include "min_heap.h"
#include "hash_table.h"
#include "queue.h"
#include "linked_list.h"

int main() {
    int choice;

    MinHeap heap;
    HashTable ht;
    Queue q;
    ListNode *history = NULL;

    initHeap(&heap);
    initHashTable(&ht);
    initQueue(&q);

    while (1) {
        printf("\n===== GROCERX MENU =====\n");
        printf("1. Add Grocery Item\n");
        printf("2. Show Nearest Expiry Item\n");
        printf("3. Add Item to Shopping List\n");
        printf("4. Purchase Item\n");
        printf("5. Show Purchase History\n");
        printf("6. Search Item\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[50];
            int qty, days;

            printf("Item name: ");
            scanf("%s", name);
            printf("Quantity: ");
            scanf("%d", &qty);
            printf("Days until expiry: ");
            scanf("%d", &days);

            HeapNode item;
            item.expiry_days = days;
            strcpy(item.name, name);

            insertHeap(&heap, item);
            insertItem(&ht, name, qty);

            printf("Item added successfully\n");
        }

        else if (choice == 2) {
            if (heap.size == 0) {
                printf("No items in inventory\n");
            } else {
                HeapNode min = getMin(&heap);
                printf("Nearest expiry item: %s (%d days)\n",
                       min.name, min.expiry_days);
            }
        }

        else if (choice == 3) {
            char name[50];
            printf("Enter item name to add to shopping list: ");
            scanf("%s", name);
            enqueue(&q, name);
        }

        else if (choice == 4) {
            if (isEmpty(&q)) {
                printf("Shopping list empty\n");
            } else {
                char item[50];
                strcpy(item, q.items[q.front]);
                dequeue(&q);
                insertEnd(&history, item, 100);
                printf("Item purchased and added to history\n");
            }
        }

        else if (choice == 5) {
            displayList(history);
        }

        else if (choice == 6) {
            char name[50];
            printf("Enter item to search: ");
            scanf("%s", name);

            HashNode *res = searchItem(&ht, name);
            if (res != NULL) {
                printf("Found %s | Qty: %d | Freq: %d\n",
                       res->name, res->quantity, res->frequency);
            } else {
                printf("Item not found\n");
            }
        }

        else if (choice == 7) {
            printf("Exiting GrocerX...\n");
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

