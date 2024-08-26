#include <stdio.h>
#include <stdbool.h>
#include "lib/Hashtable.h"

#define MAX_FACTORS 16

void get_prime_factors(int n, int *dst){
    //This is modified code I found on the internet
    //I had no idea how to pragmatically factor a number
    //I think I can explain it though.S

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

    *dst++ = 0;
}

bool is_powerful(int num){

    int factors[MAX_FACTORS];
    get_prime_factors(num, factors);

    Hashtable *hashtable = create_hashtable(MAX_FACTORS);

    for (int i = 0; factors[i] != 0; i++){
        printf("%d", factors[i]);
        //Convert number to a string
        char key[sizeof(factors[i])];
        sprintf(key, "%d", factors[i]);


        if(contains_key(hashtable, key)){
            update_val(hashtable, key, lookup(hashtable, key) + 1);
        } else {
            add(hashtable, key, 1);
        }
    }

    for(int i = 0; i < hashtable->size; i++){
        if(lookup(hashtable, hashtable->keys[i]) % 2 != 0) return false;
    }

    destroy_hashtable(hashtable);

    return true;
}


int main(int argc, char *argv[]) {
    
    int num;

    printf("Enter a number: ");
    // scanf("%d", &num);

    if(is_powerful(36)){
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}