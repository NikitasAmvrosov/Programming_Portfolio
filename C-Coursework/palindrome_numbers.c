#include <stdio.h>
#include <stdbool.h>


// Function prototypes
int getUserInput(int *minRange, int *maxRange);
bool numPalindrome(int num);

int main() {
    // Get user input for range
    int minRange, maxRange;
    int result = getUserInput(&minRange, &maxRange);
    if (result == -1) {
        printf("Wrong input!\n");
        return 1; // Exit with error code
    }
    
    // Variables to store palindrome and factors
    int highestPalindrome = 0;
    int num1, num2;
    bool palindromeFound = false;
    // Loop through the range and find the highest palindrome
    for (int i = minRange; i <= maxRange; i++) {
        for (int j = i; j <= maxRange; j++) {
            int product = i * j;
            if (numPalindrome(product) && product > highestPalindrome) {
                highestPalindrome = product;
                num1 = i;
                num2 = j;
                palindromeFound = true;
            }
        }
    }

    // Output result
    if (palindromeFound) {
        printf("The highest palindrome as a product of %d and %d is %d\n", num1, num2, highestPalindrome);
    } else {
        printf("No palindrome found!\n");
    }

    return 0;
}

// Function to get user input for range
int getUserInput(int *minRange, int *maxRange) {
    printf("Please enter the range of numbers - multiplied with each other - to get the highest palindrome: \n");
    scanf("%d %d", minRange, maxRange);
    if (*minRange > *maxRange || *minRange < 100 || *maxRange > 999) {
        return -1; // Indicates wrong input
    }
    return 0;
}

// Function to check if a number is palindrome
bool numPalindrome(int num) {
    int reverse = 0;
    int temp = num;
    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return num == reverse;
}
