//
// Created by Robert Brodin on 2/4/20.
//

#ifndef ROBERTBRODINCS2303HOMEWORK2_ROBLINKEDLISTCLASS_H
#define ROBERTBRODINCS2303HOMEWORK2_ROBLINKEDLISTCLASS_H


struct RobLinkedList;

struct RobLinkedList{
    struct RobLinkedList* nextLinkedList;
    struct RobLinkedList* previousLinkedList;
    struct Marker* marker;
};

struct RobLinkedList* createNewLinkedList();
void addToLinkedList(struct RobLinkedList* robLinkedListPointer, struct RobLinkedList* previousLinkedListPointer,
                     struct RobLinkedList* emptyRLLPointer, int valueForMarker, int rowValue, int colValue);
void printEntireLinkedList(struct RobLinkedList* starterPointer);
void addTo2DArray(struct Marker* MarkersAllocationPointer, struct RobLinkedList* firstLL, int randomRow, int randomCol);
void createLinkedListChain(int numberOfLL, struct Marker* MarkersAllocationPointer);
struct RobLinkedList* createLinkedListChainForTesting(int numberOfLL, struct Marker* MarkersAllocationPointer);



#endif //ROBERTBRODINCS2303HOMEWORK2_ROBLINKEDLISTCLASS_H
