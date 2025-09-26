#include <stdio.h>
#include <string.h>

// Prototype function
void Track_Search();

void Track_Search(){

    FILE *filePointer;
    char fileName[50];
    char searchString[50];

    printf("Please enter a Jukebox file name: \n");
    scanf("%s", fileName);
    printf("Please enter a search string: \n");
    scanf("%s", searchString);

    // Opens file in read mode
    filePointer = fopen(fileName, "r");

    // Stores file contents
    char myString[100];
    int trackNumber = 1;

    // Checks for files existance
    if (filePointer != NULL){

        // Contents read + "Track XX" formatting
        while (fgets(myString, sizeof(myString), filePointer)){

            // Removes the newline character from the line, if any
            size_t len = strlen(myString);

            if (len > 0 && myString[len - 1] == '\n'){
                myString[len - 1] = '\0';
            }

            if (strstr(myString, searchString) != NULL){

                printf("Track %02d: %s\n", trackNumber, myString);
            }

            trackNumber++;
        }

    }else{

        perror("Error opening file");
    }

    // Closes the file
    fclose(filePointer);
}

int main(){
    
    Track_Search();
    return 0;
}
