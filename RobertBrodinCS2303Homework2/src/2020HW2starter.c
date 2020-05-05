/*
 Programmed by Robert Brodin - February 2020, CS 2303, Professor Engling, C 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"
#include <time.h>


int main(int argc, char* argv[]) {
	// 2d array of marker pointers!
	struct Marker* MarkersAllocationPointer = malloc(20*20*sizeof(struct Marker));

	struct Marker testMarker;
	testMarker.value = 1;
	// Assigning a value to assign to the pointer.
	*MarkersAllocationPointer = testMarker;
	*(MarkersAllocationPointer + 61) = testMarker;
	printf("\nThe value of this pointer using my arithmetic is: %d\n", *(MarkersAllocationPointer + (20 * 3) + 1));
    printf("\nThe value of this pointer using my arithmetic is: %d\n", *(MarkersAllocationPointer + coordinateToInteger(20, 3, 1)));

    printf("The pointer's value is: %d \n", *MarkersAllocationPointer);
    printf("The next value is: %d \n", *(MarkersAllocationPointer + 399));
    printf("The marker pointer is here: %d \n", sizeof(MarkersAllocationPointer));

    srand(time(0));

    struct Marker firstLLMarker;
    firstLLMarker.col = 0;
    firstLLMarker.row = 1;
    firstLLMarker.value = 11;
    struct Marker* firstLLMarkerPointer = &firstLLMarker;


    // TODO: Create linkedListChain creates a chain of linked lists. This is really to test the function.
    // TODO: Using the random numbers it creates, with the number of random numbers generated, iterate through the path and update
    // TODO: the Marker specific piece of memory corresponding with equal coordinate.
    createLinkedListChain(30, MarkersAllocationPointer);

	if(tests())
	{
	    printf("\nAll tests suceeded!");
		puts("About to run production.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
