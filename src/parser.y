// 
// -----------------------------------------------------------------------------
// configparse.y
// -----------------------------------------------------------------------------
//
// Parser for configparse
//
// Tyler Wayne © 2021
//

%{
#include <stdio.h>
#include "main.h"
%}

%union {
  char *s;
}

%token <s> STRING
%token EOL

%type <s> stmt

%%

list:                       /* nothing */
  | list stmt EOL
  | list EOL                { return 0; }
  ;

// stmt: STRING '=' STRING     { printf("key: %s, val: %s\n", $1, $3); }
stmt: STRING '=' STRING     { dict_set(configs, $1, $3); }
  ; 

%%
