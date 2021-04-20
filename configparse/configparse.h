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

#include <stdlib.h> // FILE
#include "dict.h"

// interface to lexer
extern int yylineno;
void yyerror(char *s);
int yylex();
extern FILE *yyin;

// program data
extern Dict_T config_dict;
void configparse(Dict_T, FILE *);

#endif // CONFIGPARSE_INCLUDED
