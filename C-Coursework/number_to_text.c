#include <stdio.h>
#include <stdbool.h>

// Prototype Helper functions
void numToText();

int main() {
    // Call the numToText function to execute the program
    numToText();

    // Program execution completed successfully
    return 0;
}

void numToText() {
    // Declaration of variables and an array of strings representing digit names
    int num;
    char *numText[] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };

    // Infinite loop to repeatedly prompt the user for input
    while (true) {
        // Prompt the user to enter a number between 0 and 999
        printf("Please enter a number between 0 and 999: \n");

        // Check if the entered number is within the valid range
        if (scanf("%d", &num) == 1 && num >= 0 && num <= 999) {
            int digit;
            bool first_digit = true;

            // Handle the case when the number is 0 separately
            if (num == 0) {
                printf("%s", numText[num]);
            } else {
                // Reverse the order of digits in the number
                int reversedNum = 0;

                while (num > 0) {
                    digit = num % 10;
                    num = num / 10;
                    reversedNum = reversedNum * 10 + digit;
                }

                // Print each reversed digit with a space in between
                while (reversedNum > 0) {
                    digit = reversedNum % 10;
                    reversedNum = reversedNum / 10;

                    // Add a space between digits after the first digit
                    if (!first_digit) {
                        printf(" ");
                    }

                    // Print the digit name from the array
                    printf("%s", numText[digit]);

                    first_digit = false;
                }
            }

            // Print a newline after the digits
            printf("\n");

            // Break the loop after successful execution
            break;
        } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');

            // Inform the user of an invalid input and prompt to try again
            printf("Invalid input. Please enter a number between 0 and 999.\n");
        }
    }
}
