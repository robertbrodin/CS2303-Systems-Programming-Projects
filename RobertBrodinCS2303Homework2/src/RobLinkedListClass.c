//
// Created by Robert Brodin on 2/4/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "RobLinkedListClass.h"

struct RobLinkedList* createNewLinkedList(){
    struct RobLinkedList* pointerToAnotherLinkedList = (struct RobLinkedList*) malloc(sizeof(struct RobLinkedList));
    pointerToAnotherLinkedList->marker = (struct Marker*)0;
    pointerToAnotherLinkedList->nextLinkedList = (struct RobLinkedList*)0;
    pointerToAnotherLinkedList->previousLinkedList = (struct RobLinkedList*)0;
    return pointerToAnotherLinkedList;
}

void addToLinkedList(struct RobLinkedList* robLinkedListPointer, struct RobLinkedList* previousLinkedListPointer,
                     struct RobLinkedList* emptyRLLPointer, int valueForMarker, int rowVal, int colVal){
    struct Marker markerCreated;
    markerCreated.value = valueForMarker;
    markerCreated.row = rowVal;
    markerCreated.col = colVal;

    struct Marker* markerFromM = (struct Marker*) malloc(sizeof(struct Marker));
    *markerFromM = markerCreated;
    (*robLinkedListPointer).marker = markerFromM;

    robLinkedListPointer->previousLinkedList = previousLinkedListPointer;
    previousLinkedListPointer->nextLinkedList = robLinkedListPointer;
}

void printEntireLinkedList(struct RobLinkedList* starterPointer){
    // Need to figure out when to stop this, I'm not entirely sure when but maybe I could use a while loop here?
    // Could use recursion for this, while starterPointer->next isn't equal to empty?
    struct RobLinkedList* initialTemp = starterPointer;
    printf("\nCurrent value from entire linked list: %d", initialTemp->marker->value);
    if(starterPointer->nextLinkedList->marker->value == -1){
        printf("\nNo more code to print!\n");
    }
    else{
        // Need some way of calculating the position, I could feasibly put this in marker and not have too much of an issue.
        struct RobLinkedList* tempP = starterPointer->nextLinkedList;
        printEntireLinkedList(tempP);

    }
}

void addTo2DArray(struct Marker* MarkersAllocationPointer, struct RobLinkedList* firstLL, int randomRow, int randomCol){
    *(MarkersAllocationPointer + coordinateToInteger(20, randomRow, randomCol)) = *(firstLL->marker);

}


void createLinkedListChain(int numberOfLL, struct Marker* MarkersAllocationPointer){

    struct RobLinkedList* emptyLL = createNewLinkedList();
    struct RobLinkedList* lastPointer = emptyLL;
    // Need a lastPointer to keep track of the last one, so it can be referenced as the last.
    int path[30] = {};
    int randomNumbersRow[30] = {};
    int randomNumbersCol[30] = {};
    int lastNumbers[30] = {};
    for(int numberOfLLCounter = 0; numberOfLLCounter < numberOfLL; numberOfLLCounter++) {
        //printf("Counter: %d", numberOfLLCounter);
        // Used to generate the random number.
        int randomRow = generateRandomNumber(20);
        int randomCol = generateRandomNumber(20);
        randomNumbersRow[numberOfLLCounter] = (int) randomRow;
        randomNumbersCol[numberOfLLCounter] = (int) randomCol;

        struct RobLinkedList *firstLL = createNewLinkedList();
        addToLinkedList(firstLL, lastPointer, emptyLL, 1, randomRow, randomCol);
        //printf("\nThe value of the currentLL's marker in the main function is: %d", firstLL->marker->value);
        //printf("\nThe row and column values are: %d, %d", firstLL->marker->row, firstLL->marker->col);
        if (numberOfLLCounter > 0) {
            //printf("\nThe value of the pastLL's marker in the main function from the currentLL is: %d", firstLL->previousLinkedList->marker->value);
        }
        printf("\nThe value of currentLL's marker in the main function from pastLL is: %d\n", lastPointer->nextLinkedList->marker->value);
        lastPointer = firstLL;
        path[numberOfLLCounter] = firstLL->marker->value;


        //printf("\nNow setting the value of the allocated 2d array using the calculation from coordinateToInteger");
        //printf("\n The random num is : %d", coordinateToInteger(20, randomRow, randomCol));
        addTo2DArray(MarkersAllocationPointer, firstLL, randomRow, randomCol);
        lastNumbers[numberOfLLCounter] = coordinateToInteger(20, randomRow, randomCol);
        // TODO: Instead of going back one correctly, it goes back two correctly. I am unsure of why this is the case.
        // TODO: Sometimes, the path just doesn't line up with the previous one. Need to make sure that I am doing everything correctly, maybe I should do this with malloc? But I kinda already do
        // TODO: EDIT: THIS IS WORKING!!!

        printMarkerValues(MarkersAllocationPointer, 20);
    }

    for(int i = 0; i < 20; i++){
        //printf("\nPrinting the path: %d, Random: %d, Last: %d\n", path[i], randomNumbersRow[i], lastNumbers[i]);
        printf("Index: %d, Path - Row: %d, Value: %d\n", i, randomNumbersRow[i], randomNumbersCol[i]);
    }
}

struct RobLinkedList* createLinkedListChainForTesting(int numberOfLL, struct Marker* MarkersAllocationPointer){

    struct RobLinkedList* emptyLL = createNewLinkedList();
    struct Marker emptyMarker;
    emptyMarker.value = -1;
    emptyLL->marker = &emptyMarker;
    struct RobLinkedList* lastPointer = emptyLL;
    struct RobLinkedList* empty;
    // Need a lastPointer to keep track of the last one, so it can be referenced as the last.
    int path[30] = {};
    int randomNumbersRow[30] = {};
    int randomNumbersCol[30] = {};
    int lastNumbers[30] = {};
    for(int numberOfLLCounter = 0; numberOfLLCounter <= numberOfLL + 1; numberOfLLCounter++) {
        // Used to generate the random number.
        int randomRow = generateRandomNumber(20);
        int randomCol = generateRandomNumber(20);
        randomNumbersRow[numberOfLLCounter] = (int) randomRow;
        randomNumbersCol[numberOfLLCounter] = (int) randomCol;

        struct RobLinkedList *firstLL = createNewLinkedList();
        if(numberOfLLCounter == 0){
            empty = firstLL;
        }
        addToLinkedList(firstLL, lastPointer, emptyLL, 1, randomRow, randomCol);
        lastPointer = firstLL;
        path[numberOfLLCounter] = firstLL->marker->value;

        addTo2DArray(MarkersAllocationPointer, firstLL, randomRow, randomCol);
        lastNumbers[numberOfLLCounter] = coordinateToInteger(20, randomRow, randomCol);
        // TODO: Instead of going back one correctly, it goes back two correctly. I am unsure of why this is the case.
        // TODO: Sometimes, the path just doesn't line up with the previous one. Need to make sure that I am doing everything correctly, maybe I should do this with malloc? But I kinda already do
        // TODO: EDIT: THIS IS WORKING!!!

    }
    return empty;
}