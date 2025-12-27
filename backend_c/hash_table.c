#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

void initHashTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

int hashFunction(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void insertItem(HashTable *ht, char *name, int quantity) {
    int index = hashFunction(name);

    HashNode *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->quantity += quantity;
            current->frequency++;
            return;
        }
        current = current->next;
    }

    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->frequency = 1;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

HashNode* searchItem(HashTable *ht, char *name) {
    int index = hashFunction(name);
    HashNode *current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayHashTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = ht->table[i];
        if (current != NULL) {
            printf("Index %d: ", i);
            while (current != NULL) {
                printf("[%s | Qty: %d | Freq: %d] -> ",
                       current->name,
                       current->quantity,
                       current->frequency);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}
