#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10

typedef struct HashNode {
    char name[50];
    int quantity;
    int frequency;
    struct HashNode *next;
} HashNode;


typedef struct {
   HashNode *table[TABLE_SIZE];
} HashTable;

void initHashTable(HashTable *ht);
int hashFunction(char *key);
void insertItem(HashTable *ht, char *name, int quantity);
HashNode* searchItem(HashTable *ht, char *name);
void displayHashTable(HashTable *ht);

#endif
