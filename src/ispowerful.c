#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include "lib/Hashtable.h"

#define MAX_FACTORS 32


//I started making a hashtable and the solution wasnt going well
//And I didnt feel like doing the work to figure it out so i did this
//instead its loosely based on a hashtable but it is not as... useful...
typedef struct {
    int *keys;
    int *values;
    int capacity;
    int size;
} Table;

Table *create_table(int capacity){
    if(capacity <= 0) return NULL;

    Table *table = malloc(sizeof(Table));

    if(table == NULL) return NULL;

    int *keys = malloc(sizeof(int) * capacity);

    if(keys == NULL) return NULL;

    table->keys = keys;

    int *values = malloc(sizeof(int) * capacity);

    if(values == NULL) return NULL;

    for(int i = 0; i < sizeof(int) * capacity; i++){
        values[i] = 0;
    }

    table->values = values;

    table->capacity = capacity;
    table->size = 0;

    return table;
}

void destroy_table(Table *table){
    free(table->keys);
    free(table->values);
    free(table);
}

//Returns -1 if the item is not a key
int indexofkey(Table *table, int item){

    for (int i = 0; i < table->size; i++){
        int temp = table->keys[i];
        if(temp == item) {
            return i;
        }
    };

    return -1;
}

int lookup(Table *table, int key){
    int index = indexofkey(table, key);

    if(index == -1) return -1;

    return table->values[index];
}

bool is_full(Table *table){
    return table->size == table->capacity;
}

//This is largely where I strayed from hashtable concepts to just doing
//What i needed to happen for this program to do as intended
void add(Table *table, int key){
    if(is_full(table)) return;

    if(lookup(table, key) > 0){
        table->values[indexofkey(table, key)]++;
    } else {
        table->keys[table->size] = key;
        table->values[table->size] = 1;
        table->size++;
    }
}

void get_prime_factors(int n, int *dst){
    //This is modified code I found on the internet
    //I had no idea how to pragmatically factor a number
    //I think I can explain it though.

    //Calculate all 2s in n
    while(n % 2 == 0){
        //pointer moves to next int pos in array, and assigns 2 to the old position
        *dst++ = 2;
        n /= 2;
    }

    //Find all odd factors
    for(int i = 3; i * i <= n; i += 2){
        while(n % i == 0){
            //See above loop for explanation
            *dst++ = i;
            n /= i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2 
    if(n > 2){
        *dst++ = n;
    }

    //This is so I can know where the end of the data is
    *dst++ = 0;
}

int calc_factor_size(int *factors){
    int size = 0;

    int i = 0;
    while(factors[i] != 0) {
        i++;
        size++;
    }

    return size;
}

bool is_powerful(int num){

    int factors[MAX_FACTORS];
    get_prime_factors(num, factors);
    int factor_size = calc_factor_size(factors);

    Table *table = create_table(factor_size);

    if(table == NULL) return false;

    for(int i = 0; factors[i] != 0; i++){
        add(table, factors[i]);
    }

    for(int i = 0; i < table->size ; i++){

        if(lookup(table, table->keys[i]) < 2 ) {
            destroy_table(table);
            return false;
            }
    }

    destroy_table(table);
    table = NULL;

    return true;
}


int main(int argc, char *argv[]) {
    
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(is_powerful(num)){
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}