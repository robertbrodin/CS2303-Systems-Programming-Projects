/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"


bool tests()
{
	bool answer = false;
	bool checkFileEmpty = checkFileNotEmpty();
	answer = checkFileEmpty;
	return answer;
}

bool checkFileNotEmpty(){
    // Open the file
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file

    fp = fopen("writingfile.txt", "r");

    // Check if file exists
    if (fp == NULL){
        printf("\nCould not open file");
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') { // Increment count if this character is newline
            count = count + 1;
        }

    if(count > 12) {
        return true;
    }
    else{
        return false;
    }
}