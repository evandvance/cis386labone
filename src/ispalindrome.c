#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lib/Stack.h"


bool is_palindrome(char str[]){
    int string_len = strlen(str);

    Stack *stack = create_stack(string_len);

    if(stack == NULL){
        printf("Error Creating Stack\n");
        return false;
    }

    for(int i = 0; i < string_len; i++){
        push(stack, str[i]);
    }

    char reversed_string[string_len];
    char popped_char = 'c';
    for(int i = 0; i < string_len; i++){
        pop(stack, &popped_char);
        reversed_string[i] = popped_char;
    }

    strcat(reversed_string, "\0");
    destoy_stack(stack);

    if(strcmp(str, reversed_string) == 0) return true;
    return false;
}

int main(int argc, char *argv[]) {

    char str[64]; 

    printf("Enter a string: ");
    scanf("%s", str);

    if(is_palindrome(str)){ 
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}