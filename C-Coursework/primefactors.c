#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Prototype
int primeFactors(long int n);

// Main function
int main() {
    // Variable to store user input
    long int number = 0;
    long int result;

    // Main loop to repeat until a valid input is provided
    do {
        // Prompt user to enter the number to be factorized
        printf("Please enter the number which should be factorized: \n");
        scanf("%ld", &number);

        // Check if the entered number is greater than 3 (as 2 is the only prime factor for 2 and 3)
        if (number > 3) {

            // Call the primeFactors function and store the result
            result = primeFactors(number);

            // Print the highest prime factor of the entered number
            printf("Highest prime factor of %ld is %ld \n", number, result);
            
            // Break out of the loop after processing a valid input
            break;
        } else {
            // Print an error message for invalid input and restart the loop
            printf("The entered number is invalid!\n");
            continue;
        }

    } while (true);

    // Return 0 to indicate successful program execution
    return 0;
}

// Function to find and print prime factors of a number
int primeFactors(long int n) {
    // Divide the number by 2 until it becomes odd
    while (n % 2 == 0) {
        //printf("%ld \n", 2);
        n = n / 2;
    }

    // Check for odd factors starting from 3
    for (int i = 3; i * i <= n; i = i + 2) {
        // Divide by the current factor until it is no longer divisible
        while (n % i == 0) {
            //printf("%ld \n", i);
            n = n / i;
        }
    }

    // If the remaining number is greater than 2, it is a prime factor
    if (n > 2) {
        printf("%ld \n", n);
    }

    // Return the last remaining factor (which is the highest prime factor)
    return n;
}