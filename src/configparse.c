//
// -----------------------------------------------------------------------------
// configparse.c
// -----------------------------------------------------------------------------
//
// Tyler Wayne © 2021
//

#include <stdio.h>  // fprintf
#include <stdlib.h> // calloc
#include <string.h> // strncpy
#include "configparse.h"
#include "parser.h"
#include "dict.h"

Dict_T configs;

void yyerror(char *s) {

  fprintf(stderr, "%s\n", s);

}

int main(int argc, char **argv) {

  if (argc == 2) {
    if (!(yyin = fopen(argv[1], "r"))) {
      fprintf(stderr, "Unable to open file...\n");
      exit(EXIT_FAILURE);
    }
  }

  configs = dict_new();
  char *val;

  yyparse();

  if ((val = dict_get(configs, "a"))) printf("a: %s\n", val);

}
