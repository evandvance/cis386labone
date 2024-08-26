#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct {
    char *key;
    int val;
    struct Node *next;
} Node;


typedef struct{
    Node **table;
    int size;
    int capacity;
    char **keys;
} Hashtable;

int hash(const char *key, int table_size){
    //Yoinked this from an old DS book.

    unsigned int hash_val = 0;

    while(*key != '\0'){
        //Leftshifting the hashval and adding the ascii 
        //value of the key to it then moving to the next char in the key
        hash_val = ( hash_val << 5 ) + *key++;
    }

    return hash_val % table_size;
}

bool is_full(Hashtable *hashtable){
    return hashtable->size == hashtable->capacity;
}

bool is_empty(Hashtable *hashtable){
    return hashtable->size == 0;
}

Node *create_node(char *key, int val){
    Node *node = malloc(sizeof(Node));

    if(node == NULL) return NULL;

    node->key = malloc(sizeof(key));

    if(node->key == NULL) return NULL;

    strcpy(node->key, key);
    node->val = val;
    node->next = NULL;

    return node;
}

/*A function to create a hashtable
  Due to the limits of my own skill, the table must only have
  64 keys at most.
*/
Hashtable *create_hashtable(int capacity){
    if (capacity <= 0 || capacity > 64) return NULL;

    Hashtable *hashtable = malloc(sizeof(Hashtable));

    if(hashtable == NULL) return NULL;

    hashtable->keys = malloc(sizeof(char *) * capacity);

    if(hashtable->keys == NULL) return NULL;

    hashtable->table = malloc(sizeof(Node *) * capacity);

    if(hashtable->table == NULL) return NULL;

    hashtable->capacity = capacity;
    hashtable->size = 0;

    return hashtable;
}

//This is asking for a memory leak
//Add a way to remove the key from the keys of the hashtable and also
//check if the key is even in the keys of the hashtable
void destroy_node(Node *node, Hashtable *hashtable){

    Node *parent_node = hashtable->table[hash(node->key, hashtable->capacity)];

    while(parent_node->next != node) parent_node = parent_node->next;

    parent_node->next = node->next;

    free(node->key);
    node->next = NULL;
    free(node);
}


void destroy_hashtable(Hashtable *hashtable){

    for(int i = 0; i < hashtable->size; i++){
        //write something to iterate over table and remove every node
       
    }

    free(hashtable->table);
    free(hashtable);
}


bool add(Hashtable *hashtable, char *key, int val){
    if(is_full(hashtable)) return false;

    hashtable->keys[hashtable->size] = key;
    hashtable->size++;

    int index = hash(key, hashtable->capacity);

    Node *node = create_node(key, val);

    if(hashtable->table[index] == NULL){
        hashtable->table[index] = &node;
        return true;
    }

    Node *curr = hashtable->table[index];
    while(curr->next != NULL) curr = &curr->next;

    curr->next = &node;
    return true;
}

Node *lookup_node(Hashtable *hashtable, char *key){
    Node *found_node = hashtable->table[hash(key, hashtable->capacity)];

    while(found_node->key != key){
        found_node = found_node->next;
    }

    return found_node;
}


int lookup(Hashtable *hashtable, char *key){
    Node *found_node = lookup_node(hashtable, key);

    return found_node->val;
}

int update_val(Hashtable *hashtable, char *key, int new_val){
    Node *node = lookup_node(hashtable, key);

    node->val = new_val;
    return node->val;
}

bool contains_key(Hashtable *hashtable, char *key){
    for(int i = 0; i < hashtable->size; i++){
        if(hashtable->keys[i] == key) return true;
    }

    return false;
}
