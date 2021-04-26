//
// -----------------------------------------------------------------------------
// main.c
// -----------------------------------------------------------------------------
//
// Tyler Wayne © 2021
//

#include <stdio.h>        // FILE, fopen, fprintf, printf
#include <stdlib.h>       // EXIT_FAILURE
#include <dict.h>         // dict_T, dict_new, dict_get
#include "configparse.h"  // configparse
#include "parser.h"

int main(int argc, char **argv) {

  FILE *fd;

  if (argc == 2) {
    if (!(fd = fopen(argv[1], "r"))) {
      fprintf(stderr, "Unable to open file...\n");
      exit(EXIT_FAILURE);
    }
  }

  dict_T configs = dict_new();
  configparse(configs, fd);
  char *val;
  if ((val = dict_get(configs, "a"))) printf("a: %s\n", val);

}
