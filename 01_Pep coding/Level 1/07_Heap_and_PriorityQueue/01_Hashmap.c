#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20000

typedef struct ht_node {
    char *key;
    char *value; 
    struct ht_node *next;
} ht_node;

typedef struct {
    ht_node **entries;
} ht;

unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // do several rounds of multiplication
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    // make sure value is 0 <= value < TABLE_SIZE
    value = value % TABLE_SIZE;

    return value;
}

ht_node *ht_pair(const char *key, const char *value) {
    // allocate the entry
    ht_node *entry = malloc(sizeof(ht_node));
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // copy the key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

ht *ht_create(void) {
    // allocate table
    ht *hashtable = malloc(sizeof(ht));

    // allocate table entries
    hashtable->entries = malloc(sizeof(ht_node*) * TABLE_SIZE);

    // set each to null (needed for proper operation)
    int i = 0;
    for (; i < TABLE_SIZE; ++i) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

void ht_set(ht *hashtable, const char *key, const char *value) {
    unsigned int slot = hash(key);

    // try to look up an entry set
    ht_node *entry = hashtable->entries[slot];

    // no entry means slot empty, insert immediately
    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    ht_node *prev;

    // walk through each entry until either the end is
    // reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new
    prev->next = ht_pair(key, value);
}

char *ht_get(ht *hashtable, const char *key) {
    unsigned int slot = hash(key);

    // try to find a valid slot
    ht_node *entry = hashtable->entries[slot];

    // no slot means no entry
    if (entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while (entry != NULL) {
        // return value if found
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }

        // proceed to next key if available
        entry = entry->next;
    }

    // reaching here means there were >= 1 entries but no key match
    return NULL;
}

void ht_del(ht *hashtable, const char *key) {
    unsigned int bucket = hash(key);

    // try to find a valid bucket
    ht_node *entry = hashtable->entries[bucket];

    // no bucket means no entry
    if (entry == NULL) {
        return;
    }

    ht_node *prev;
    int idx = 0;

    // walk through each entry until either the end is reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            // first item and no next entry
            if (entry->next == NULL && idx == 0) {
                hashtable->entries[bucket] = NULL;
            }

            // first item with a next entry
            if (entry->next != NULL && idx == 0) {
                hashtable->entries[bucket] = entry->next;
            }

            // last item
            if (entry->next == NULL && idx != 0) {
                prev->next = NULL;
            }

            // middle item
            if (entry->next != NULL && idx != 0) {
                prev->next = entry->next;
            }

            // free the deleted entry
            free(entry->key);
            free(entry->value);
            free(entry);

            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;

        ++idx;
    }
}

void ht_dump(ht *hashtable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        ht_node *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;) {
            printf("%s=%s ", entry->key, entry->value);

            if (entry->next == NULL) {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}

int main(int argc, char **argv) {
    ht *ht = ht_create();

    ht_set(ht, "name1", "em");
    ht_set(ht, "name2", "russian");
    ht_set(ht, "name3", "pizza");
    ht_set(ht, "name4", "doge");
    ht_set(ht, "name5", "pyro");
    ht_set(ht, "name6", "joost");
    ht_set(ht, "name7", "kalix");

    ht_dump(ht);

    return 0;
}