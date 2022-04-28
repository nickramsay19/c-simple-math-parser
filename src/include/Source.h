#ifndef SOURCE_H
#define SOURCE_H

struct SourceStruct {
    char* text;
    int head;
};

typedef struct SourceStruct *Source;

Source NewSource(char* userSource);

void FreeSource(Source s);

char* head(Source s);

#endif // SOURCE_H