#include <stdio.h>
#include <math.h>

// Function declarations
unsigned int upperLimit();
unsigned long long int calculateSum(unsigned int limit);

int main() {
    unsigned int limit = upperLimit(); // Get the upper limit from the user
    unsigned long long int result = calculateSum(limit); // Calculate the sum of the series

    // Print the final result of the series in the expected format | modulo 
    printf("The last digits of the series are %llu \n", result % 100000000);

    return 0;
}

// Function to get the upper limit of the series from the user
unsigned int upperLimit() {
    unsigned int number;
    printf("Please enter the highest value, which will be selected: \n");
    scanf("%u", &number);
    return number;
}

// Function to calculate the sum of the series where each term is i^i
unsigned long long int calculateSum(unsigned int limit) {
    unsigned long long int sum = 0;

    // Loop through each integer from 1 to the specified upper limit (limit)
    for (unsigned int i = 1; i <= limit; i++) {
        unsigned long long int result = pow(i, i); // Use the pow function to calculate i^i
        sum += result; // Add the calculated i^i to the cumulative sum
    }

    return sum; // Return the final sum of the series
}
