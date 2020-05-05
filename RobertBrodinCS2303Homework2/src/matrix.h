//
// Created by Robert Brodin on 1/29/20.
//

#ifndef ROBERTBRODINCS2303HOMEWORK2_MATRIX_H
#define ROBERTBRODINCS2303HOMEWORK2_MATRIX_H

struct Marker{
    // Value is used to hold whether there is a one or zero.
    int value;
    int row;
    int col;
};


struct RobLinkedList* createNewLinkedList();
void addToLinkedList(struct RobLinkedList* robLinkedListPointer, struct RobLinkedList* previousLinkedListPointer,
        struct RobLinkedList* emptyRLLPointer, int valueForMarker, int rowValue, int colValue);
void printEntireLinkedList(struct RobLinkedList* starterPointer);
void printMarkerValues(struct Marker* MarkerAllocationPointer, int size);
void addTo2DArray(struct Marker* MarkersAllocationPointer, struct RobLinkedList* firstLL, int randomRow, int randomCol);
void createLinkedListChain(int numberOfLL, struct Marker* MarkersAllocationPointer);
struct RobLinkedList* createLinkedListChainForTesting(int numberOfLL, struct Marker* MarkersAllocationPointer);
int coordinateToInteger(int size, int row, int column);
int generateRandomNumber(int high);

#endif //ROBERTBRODINCS2303HOMEWORK2_MATRIX_H
