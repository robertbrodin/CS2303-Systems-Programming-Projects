/*
 * Homework 3
 * Programmed by Robert Brodin, Nick Vachon, and Orest Ropi
 * CS 2303, Systems Programming Concepts, February 11, 2020
 * C Term 2019, Worcester Polytechnic Institute
 */

#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "tests.h"

int main(void) {
    char write_file_name[100];
    char numberLimit[100];
    bool search = false;

    while(!checker(write_file_name, "yes") && !checker(write_file_name, "no")){
        printf("Would you like to search all rooms (yes)? Or a certain amount (no)\n");
        scanf("%s", write_file_name);

        printf("Answer is :%s", write_file_name);
        if(checker(write_file_name, "no")){
            printf("\nHow many clues would you like to find? (and stop at)");
            scanf("%s", numberLimit);
            printf("You said: %s", numberLimit);
            search = true;
        }
    }

    int lim = atoi(numberLimit);

    FILE *fp;
    FILE *matrix;

    int sentinel;
    char roomName[50];
    char roomT[30];

    fp = fopen("MansionRoomsNoDots-1.txt", "r");
    matrix = fopen("adjacencymatrix.txt", "r");

    fscanf(fp, "%d", &sentinel);

    printf("\nThe sentinel is: %d", sentinel);
    fclose(fp);

    /// Allocates the block where the rooms will be stored.
    struct Room* roomPointer = (struct Room*) malloc(sentinel * sizeof(struct Room));
    for(int j = 0; j < sentinel; j++){
        struct Room newRoom;
        newRoom.roomNum = j;
        newRoom.lastArrayVal = 0;
        roomPointer->discovered = false;
        roomPointer->searched = false;
        *(roomPointer + j) = newRoom;
        printf("\nNew room created! %d", newRoom.roomNum);
    }
    for(int i = 0; i < sentinel; i++) {
        fscanf(matrix, "%s %s", roomT, roomName);

        printf("\nDiscovered %s", roomName);

        for(int roomConnections = 0; roomConnections < sentinel; roomConnections++){

            int a = (int) roomT[roomConnections];
            char newTest[1];

            newTest[0] = roomT[roomConnections];
            //printf("New test is: %c", newTest[1]);
            int t = atoi(newTest);
            if(t == 11){
                (roomPointer + i)->connectedTo[(roomPointer + i)->lastArrayVal] = (roomPointer + roomConnections);
                (roomPointer + i)->lastArrayVal = ((roomPointer + i)->lastArrayVal + 1);
                struct Room* tempP =  (roomPointer + i)->connectedTo[0];

            }
        }
    }
    BFS(roomPointer, search, lim);

    if(tests()){
        printf("\nThe tests passed!");
    }
    else{
        printf("\nThe tests failed!");
    }

    return EXIT_SUCCESS;
}
