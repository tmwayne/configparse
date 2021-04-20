// 
// -----------------------------------------------------------------------------
// configparse.h
// -----------------------------------------------------------------------------
//
// Parse config files using flex & bison
//
// Tyler Wayne © 2021
//

#ifndef CONFIGPARSE_INCLUDED
#define CONFIGPARSE_INCLUDED

#include "dict.h"

// interface to lexer
extern int yylineno;
void yyerror(char *s);
int yylex();
extern FILE *yyin;

// program data
extern Dict_T configs;

#endif // CONFIGPARSE_INCLUDED
