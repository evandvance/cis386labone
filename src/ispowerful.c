#include <stdio.h>
#include <stdbool.h>

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
}

bool is_powerful(int num){

    int factors[MAX_FACTORS];
    get_prime_factors(num, factors);

    //TODO Make a hash map

}


int main(int argc, char *argv[]) {
    
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(is_powerful(num)){
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}