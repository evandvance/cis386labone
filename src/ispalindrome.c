#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "lib/Stack.h"


//I dont understand how this works well I found it on the internet and changed it a little
//I know what it does but I dont understand how its moving through the src and dst well
void reformat_string(char *src, char *dst) {
    for (; *src; ++src){
        if (!ispunct((unsigned char) *src) && !isspace((unsigned char) *src)){
            *dst++ = tolower((unsigned char) *src);
        }
    }
    *dst = 0;
}

bool is_palindrome(char str[]){
    char clean_string[strlen(str)];

    reformat_string(str, clean_string);

    int string_len = strlen(clean_string);

    Stack *stack = create_stack(string_len);

    if(stack == NULL){
        printf("Error Creating Stack\n");
        return false;
    }

    for(int i = 0; i < string_len; i++){
        push(stack, clean_string[i]);
    }

    char reversed_string[string_len];
    char popped_char = 'c';
    for(int i = 0; i < string_len; i++){
        pop(stack, &popped_char);
        reversed_string[i] = popped_char;
    }

    destoy_stack(stack);
    stack = NULL;

    if(strcmp(clean_string, reversed_string) == 0) return true;
    return false;
}

int main(int argc, char *argv[]) {

    char str[64]; 

    printf("Enter a string: ");
    fgets(str, 64, stdin);

    if(is_palindrome(str)){ 
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

/*
I am aware that there is a solution using cs string functions. I thought this would be fun to do
it was not. I spent far too long debugging this program. I also think there is a solution that is faster too
but I thought this was a good exercize. 
*/