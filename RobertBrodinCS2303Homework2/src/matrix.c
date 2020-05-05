//
// Created by Robert Brodin on 1/29/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <time.h>
#include "RobLinkedListClass.h"

// I'm probably going to have to use pointers to achieve this.
int generateRandomNumber(int high){
    int num = (rand() % high);
    return num;
}
void printMarkerValues(struct Marker* MarkerAllocationPointer, int size){
    printf("\n|-----------------------------------------------|\n");

    for(int i = 0; i < size; i++){
        printf("|Row %d ", i);
        for(int j = 0; j < size; j++){
            printf("%d|", (MarkerAllocationPointer + coordinateToInteger(20, i, j))->value);
        }
        printf("\n|-----------------------------------------------|\n");

    }

}


int coordinateToInteger(int size, int row, int column){
    return ((size * row) + column);
}
