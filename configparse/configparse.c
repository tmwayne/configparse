//
// -----------------------------------------------------------------------------
// configparse.c
// -----------------------------------------------------------------------------
//
// Tyler Wayne © 2021
//

#include <stdio.h>  // fprintf
#include "configparse.h"
#include "parser.h"
#include "dict.h"

dict_T config_dict;

void yyerror(char *s) {

  fprintf(stderr, "%s\n", s);

}

void configparse(dict_T configs, FILE *fd) {

  yyin = fd;
  config_dict = configs;
  yyparse();

}
