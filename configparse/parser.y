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
#include "configparse.h"
%}

%union {
  char *s;
}

%token <s> NAME NUMBER STRING
%token EOL

%type <s> stmt

%%

list:                       /* nothing */
  | list stmt EOL
//   | list EOL                { return 0; }
  | list EOL
  ;

stmt: NAME '=' NAME         { dict_set(config_dict, $1, $3); }
  | NAME '=' STRING         { dict_set(config_dict, $1, $3); }
  | NAME '=' NUMBER         { dict_set(config_dict, $1, $3); }
  ; 

%%
