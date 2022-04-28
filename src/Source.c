#include "include/Source.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Source NewSource(char* userSource) {
    int len = strlen(userSource);

    Source s = (Source) malloc(sizeof(struct SourceStruct));

    // allocate space for the text with space for the null '$' symbol
    s->text = (char*) calloc(len+1, sizeof(char));
    strcpy(s->text, userSource); // copy the provided text
    s->text[len] = '$'; // add the custom EOF symbol for parsing

    // set the head to the first symbol
    s->head = 0;

    return s;
}

char* head(Source s) {
    return s->text + s->head;
}

void FreeSource(Source s) {
    free(s->text);
    free(s);
}