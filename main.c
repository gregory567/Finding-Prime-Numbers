#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\n Welcome to the Prime Number Finder using the Sieve of Eratosthenes!\n");

    int upperLimit;
    char continueResponse;
    int outputCounter = 0;

    do{
        printf("\n Please enter the upper limit up to which you want to find prime numbers: ");
        fflush(stdin);
        scanf("%d", &upperLimit);

        int* primeNumbers = (int*)malloc(upperLimit * sizeof(int));
        if(primeNumbers == NULL){
            printf("Memory allocation failed. Exiting program.\n");
            return 1;
        }

        // initialize all numbers as potential primes
        for(int i = 2; i <= upperLimit; i++){
            primeNumbers[i] = 1;
        }

        for(int i = 2; i <= upperLimit; i++){

            if(primeNumbers[i] != 0){
                outputCounter++;
                printf(" %3d ", i);
                if(outputCounter == 10){
                    printf("\n");
                    outputCounter = 0;
                }
                int k = 1;
                while(i + k * i <= upperLimit){
                    // mark multiples of i as non-prime
                    primeNumbers[i + k * i] = 0;
                    k++;
                }
            }
        }

        free(primeNumbers);

        printf("\n\n Do you want to run the program again?\n"
               " Type 'C' or 'c' to continue, or any other key to exit: ");
        fflush(stdin);
        scanf("%c", &continueResponse);

    } while(continueResponse == 'C' || continueResponse == 'c');

    return 0;
}
