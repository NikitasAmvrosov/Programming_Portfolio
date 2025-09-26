#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spacegoesbrr.h"

// Function prototypes
Node* readfile(const char* fileName);
Node* createNode(Shuttle data);
Node* addtolist(Node* head, Node* newNode);

void missionSorter(Node** head);
void printList(Node* head);
void reverseList(Node** head);
void freelist(Node* head);


Node* readfile(const char* fileName){

    FILE* file = fopen(fileName, "r");

    if (!file){
        perror("Error opening file");
        return NULL;
    }

    char line[256];
    Node* head = NULL;

    // Skip the first two lines
    fgets(line, sizeof(line), file);  // Skip the header line
    fgets(line, sizeof(line), file);  // Skip the dashed line

    while(fgets(line, sizeof(line), file)){
        if(line[0] == '-' || line[0] == '\n') continue;

        Shuttle shuttle;
        sscanf(line, "%d | %10s | %19s | %19s | %9s",
            &shuttle.missionNumber,
            shuttle.startDate,
            shuttle.missionName,
            shuttle.orbiter,
            shuttle.launchPad);

        // Create a new node and add it to the list
        Node* newNode = createNode(shuttle);
        head = addtolist(head, newNode);
    }

    fclose(file);
    return head;
}

Node* createNode(Shuttle data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

Node* addtolist(Node* head, Node* newNode){
    if(!head) return newNode;

    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void missionSorter(Node** head){

    Node* i, *j;
    Shuttle tempData;

    for(i = *head; i->next != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(strcmp(i->data.missionName, j->data.missionName) < 0){
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
}

void printList(Node* head){

    printf("Missions-Nr. | Start-Datum | Missionsbezeichnung |  Orbiter   | Startrampe\n");
    printf("-------------------------------------------------------------------------\n");
    
    Node* temp = head;
    while(temp){
        printf("%-13d| %s  | %-19s | %-10s | %s\n",
            temp -> data.missionNumber,
            temp -> data.startDate,
            temp -> data.missionName,
            temp -> data.orbiter,
            temp -> data.launchPad);
        
        temp = temp -> next;
    }
}

// Reversing list
void reverseList(Node** head){
    Node* temp = NULL;
    Node* current = *head;
    
    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // If the list was not empty, set the new head
    if (temp != NULL) {
        *head = temp->prev;
    }
}


void freelist(Node* head){

    Node* temp;
    while(head){
        temp = head;
        head = head -> next;
        free(temp);
    }
}

int main(){

    Node* head = readfile("shuttle_data.txt");
    missionSorter(&head);
    reverseList(&head);
    printList(head);
    freelist(head);  

    return 0;
}
