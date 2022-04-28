#include "include/Parser.h"
#include <stdio.h>
#include "include/Source.h"


// -- helper methods
int isNum(char c) {
    return c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' || c=='0';
}

// -- implementations

int accept(Source s) {
    (s->head)++;
    return 0;
}

int match(Source s, char c) {
    if (head(s)[0] != c) {
        printf("Error: Expected \"%c\" but recieved \"%c\"\n", c, head(s)[0]);
        //exit(0);
        return 1;
    } else {
        // move the chars along
        accept(s);
        return 0;
    }
}

int parseStmt(Source s) {
    printf("--- parseStmt(\"%s\")\n", head(s));
    accept(s);
    parseExpr(s);

    // eof
    match(s, '$');

    return 0; // successfully parsed
}

int parseExpr(Source s) {
    printf("--- parseExpr(\"%s\")\n", head(s));
    parseTerm(s);
    parseFactorOperation(s);
    
    return 0; // successfully parsed
}

int parseTermOperation(Source s) { // parseR()
    printf("--- parseTermOperation(\"%s\")\n", head(s));
    if (head(s)[0] == '*' || head(s)[0] == '/') {
        accept(s);
        parseFactor(s);
        parseTermOperation(s);
    }

    return 0;
}

int parseTerm(Source s) {
    printf("--- parseTerm(\"%s\")\n", head(s));
    parseFactor(s);
    parseTermOperation(s);
    return 0; // successfully parsed
}

int parseFactor(Source s) {
    printf("--- parseFactor(\"%s\")\n", head(s));
    if (head(s)[0] == '(') {
        accept(s);
        parseExpr(s);
        match(s, ')');
    } else {
        // accept all numeral digits
        while (isNum(head(s)[0])) {
            accept(s);
        }
    }

    return 0; // successfully parsed
}

int parseFactorOperation(Source s) { // parseQ()
    printf("--- parseFactorOperation(\"%s\")\n", head(s));
    if (head(s)[0] == '+' || head(s)[0] == '-') {
        accept(s);
        parseTerm(s);
        parseFactorOperation(s);
    }

    return 0;
}