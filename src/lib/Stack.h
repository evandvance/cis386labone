#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *collection; //Pointer to address on heap instead of array in stack
    int capacity; //Largest size stack can be
    int size; //Ammount of items in the stack
} Stack;

Stack *create_stack(int capacity){
    if(capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack)); //Allocate memory on heap for the stack
    
    //Malloc can fail and returns null when it does we want the function to fail when malloc fails
    if(stack == NULL) return NULL;

    stack->collection = malloc(sizeof(char) * capacity); //Allocate memory on heap for dynamic array

    if(stack->collection == NULL){
        free(stack); //If malloc fails to allocate collection, free the memory for the stack struct too
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
};

void destoy_stack(Stack *stack){

    free(stack->collection);
    free(stack);
};

bool is_full(Stack *stack){
    return stack->capacity == stack->size;
};

bool is_empty(Stack *stack){
    return stack->size == 0;
};

//Pass by pointer
bool pop(Stack *stack, char *item){
    if(is_empty(stack)) return false;

    stack->size--;
    *item = stack->collection[stack->size];

    return true;
};

bool push(Stack *stack, char item){
    if(is_full(stack)) return false;

    stack->collection[stack->size] = item;

    stack->size++;

    return true;
    };

//pass by pointer
bool peek(Stack *stack, char *item){
    if(is_empty(stack)) return false;

    //dereference the top of the stack into the address that item points to
    *item = stack->collection[stack->size - 1];
    return true;
};

