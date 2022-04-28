#ifndef PARSER_H
#define PARSER_H

#include "Source.h"

int accept(Source s);
int match(Source s, char c);

int parseStmt(Source s);
int parseExpr(Source s);
int parseTerm(Source s);
int parseTermOperation(Source s); // R
int parseFactor(Source s);
int parseFactorOperation(Source s); // Q


#endif // PARSER_H