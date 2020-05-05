#include "Room.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Function BFS does a breadth-first search on a given pointer to a list of rooms, and adds the number of clues to each room.
// The total number of clues is kept track of and displayed at the end.
void BFS(struct Room* roomPointer, bool searchSpecific, int numberToSearch){
    struct Room** queue = malloc(13 * sizeof(struct Room*));
    struct Room* testRoomFinder = findRoom(roomPointer->roomNum);
    int clues = 0;
    clues = clues + testRoomFinder->numClues;
    roomPointer->searched = true;

    int* intToAddAllocate = malloc(sizeof(int));
    int placeInArray = 0;
    *intToAddAllocate = placeInArray;

    for(int i = 0; i < roomPointer->lastArrayVal; i++){
        // If the room has not been searched yet, add it to the queue.
        if(roomPointer->connectedTo[i]->searched == false){
            *(queue + placeInArray) = roomPointer->connectedTo[i];
        }
    }

    int sent = 11;
    int locationToPlace = 0;

    while(placeInArray < sent){

        struct Room* roomFromQueue;
        roomFromQueue = *(queue + placeInArray);

        struct Room* roomFoundFromSearch = findRoom(roomFromQueue->roomNum);

        clues = clues + (roomFoundFromSearch->numClues);
        printf("\nThe number of clues discovered from %s is %d - the new number of clues is: %d", roomFoundFromSearch->roomName, roomFoundFromSearch->numClues, clues);
        roomFromQueue->searched = true;

        FILE * fptr;
        char testList[500];
        int newCluesString = roomFoundFromSearch->numClues;
        int cluesString = clues;
        sprintf(testList, "\nThe number of clues discovered from %s is %d - the new number of clues is: %d $", roomFoundFromSearch->roomName, newCluesString, cluesString);

        fptr = fopen("writingfile.txt", "a"); // "w" defines "writing mode"
        for (int i = 0; (testList[i] != '$'); i++) {
            fputc(testList[i], fptr);
        }
        fclose(fptr);

        for(int searchConnections = 0; searchConnections < roomFromQueue->lastArrayVal; searchConnections++){
            if((roomFromQueue->connectedTo[searchConnections]->searched == false) && (roomFromQueue->connectedTo[searchConnections]->discovered == false)){
                locationToPlace++;
                *(queue + locationToPlace) = roomFromQueue->connectedTo[searchConnections];
                roomFromQueue->connectedTo[searchConnections]->discovered = true;
            }
        }
        placeInArray++;


        if(searchSpecific && (numberToSearch <= clues)){
            placeInArray = sent;
            printf("\nThe number of clues found is: %d, the number of extra clues from the room is: %d", numberToSearch, (clues - numberToSearch));
        }

    }
}

// Finds a room in the given file and creates a struct with the number of clues and the room name.
struct Room* findRoom(int roomID){
    int id;
    char roomName[50];
    int clues;
    int sentinel;
    FILE *matrix;
    matrix = fopen("MansionRoomsNoDots-1.txt", "r");
    sentinel = fscanf(matrix, "%d", &sentinel);

    bool foundMatch = false;
    int counter = 0;
    int sent = 12;
    while(!foundMatch && (counter < sent)){
        fscanf(matrix, "%d %s %d", &id, roomName, &clues);
        //printf("\nThis is running! ID: %d, Pointer ID: %d, Name: %s", id, roomID, roomName);

        if (id == roomID) {
            foundMatch = true;
        }
        counter++;
    }

    fclose(matrix);

    struct Room newRoom;
    newRoom.numClues = clues;
    strcpy(newRoom.roomName, roomName);

    struct Room* pointerToNewRoom = malloc(sizeof(struct Room));
    *pointerToNewRoom = newRoom;
    return pointerToNewRoom;
}

// Checker sees if two given strings are equal.
int checker(char input[],char check[])
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++) {
        if(input[i] != check[i]) {
            result=0;
            break;
        }
    }
    return result;
}