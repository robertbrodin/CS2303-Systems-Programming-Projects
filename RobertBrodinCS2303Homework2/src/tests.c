/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "matrix.h"
#include "RobLinkedListClass.h"

bool tests()
{
	bool answer = false;
	bool testAdd2DFunction = addTo2DArrayFunctionTest();
	bool testTheChain = testChain();
	bool testCoordinate = testCoordinateCalculator();

    answer = testAdd2DFunction & testTheChain & testCoordinate;
	return answer;
}
bool testCoordinateCalculator(){

    // 2d array of marker pointers!
    struct Marker* MarkersAllocationPointer = malloc(5 * 5 * sizeof(struct Marker));

    struct Marker testMarker;
    struct Marker testMarker2;
    testMarker.value = 1;
    testMarker2.value = 2;
    // Assigning a value to assign to the pointer.
    *MarkersAllocationPointer = testMarker;
    *(MarkersAllocationPointer + 16) = testMarker2;
    *(MarkersAllocationPointer + 3) = testMarker;

    if((((MarkersAllocationPointer + coordinateToInteger(5, 0, 3))->value) == testMarker.value)
    && ((MarkersAllocationPointer + coordinateToInteger(5, 3, 1))->value == testMarker2.value)){
        printf("The coordinate calculator works correctly!");
        return true;
    }
    printf("\nThe coordinates do not work correctly!");
    return false;
}

bool testChain(){
    //struct RobLinkedList* createLinkedListChainForTesting(int numberOfLL, struct Marker* MarkersAllocationPointer){
    struct Marker* my2DArray = malloc(20*20* sizeof(struct Marker));

    int numberOfLL = 7;
    struct RobLinkedList* linkedListChain = createLinkedListChainForTesting(numberOfLL, my2DArray);
    struct RobLinkedList* currentChain = linkedListChain;

    for(int i = 0; i < numberOfLL; i++){
        currentChain = currentChain->nextLinkedList;
    }

    // If the code doesn't fail, then return true! If the for loop breaks, then the function
    printf("The test chain function succeeded!\n");
    return true;
}


bool addTo2DArrayFunctionTest(){

    // TODO: void addTo2DArray(struct Marker* MarkersAllocationPointer, struct RobLinkedList* firstLL, int randomRow, int randomCol){
    // First, I need to create the 2d array and set a pointer equal to it (malloc)
    // Second, I need to create a RobLinkedList value and give it a marker.
    // Third, I need to give a row and column.
    // Fourth, I need to put a value in the spot of memory for the 2d array.
    // Fifth, set last value equal to the value the pointer marker has.
    // Sixth, run the addTo2DArray function on it.
    // Seventh, set the new value equal to the value the pointer has now.
    // Eigth, see if they are equal.

    int lastValue;
    int newValue;

    struct Marker* my2DArray = malloc(sizeof(struct Marker));
    struct Marker myRobLinkedListMarker;
    myRobLinkedListMarker.value =1;
    myRobLinkedListMarker.col = 0;
    myRobLinkedListMarker.row = 0;
    struct RobLinkedList myRobLinkedList;
    myRobLinkedList.marker = &myRobLinkedListMarker;
    struct RobLinkedList* myRobLinkedListPointer = &myRobLinkedList;

    struct Marker my2DArrayMarker;
    my2DArrayMarker.value = 0;
    my2DArrayMarker.col = 1;
    my2DArrayMarker.row = 1;
    *my2DArray = my2DArrayMarker;

    lastValue = my2DArray->value;
    addTo2DArray(my2DArray, myRobLinkedListPointer, 0, 0);
    newValue = my2DArray->value;

    if(lastValue != newValue){
        printf("\nAdding to the allocated array works!\n");
        return true;
    }
    printf("\nThe two values are not equal!");
    return false;
}