#include <stdio.h>
#include <stdlib.h>
#include "include/Parser.h"
#include "include/Source.h"

int main(int argc, char** argv) {

    // check for valid command line args
    if (argc < 2) {
        printf("Please provide an expression.\n");
        exit(-1);
        return -1;
    } 
    
    // get user input
    Source s = NewSource(argv[1]);

    parseStmt(s);

    // free memory
    FreeSource(s);
}