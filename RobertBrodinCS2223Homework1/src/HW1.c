/*
 ============================================================================
 Name        : HW3.c
 Author      : Robert Brodin
 Version     : 9001
 Copyright   : Your copyright notice
 Description : CS2303 Homework Assignment 1, C Term 2020, Professor Engling
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "RobBrodin.h"
#include "search.c"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW1!!!"); /* prints !!!Hello World!!! */

    if(tests())
	{
		puts("About to run production.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
