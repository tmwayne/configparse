//
// -----------------------------------------------------------------------------
// configparse.c
// -----------------------------------------------------------------------------
//
// Main routines for configuration parser
//

#include <stdio.h>  // fprintf
#include <stdlib.h> // calloc
#include <string.h> // strncpy
#include "configparse.h"
#include "configparse.tab.h"

struct dict *configs;

void yyerror(char *s) {

  fprintf(stderr, "%s\n", s);

}

struct dict *dict_new() {

  struct dict *l = calloc(1, sizeof(struct dict));
  return l;

};

void dict_set(struct dict *dict, char *key, char *val) {

  if (!dict) {
    fprintf(stderr, "List is NULL pointer\n");
    exit(EXIT_FAILURE);
  }

  struct elem **elem = &dict->head;

  while (*elem) {
    if (strcmp((*elem)->key, key) == 0) {
      free((*elem)->val);
      (*elem)->val = strdup(val);
      return;
    }
    elem = &(*elem)->next;
  }

  *elem = calloc(1, sizeof(struct elem));
  (*elem)->key = strdup(key);
  (*elem)->val = strdup(val);
  dict->len++;

}

char *dict_get(struct dict *dict, char *key) {
  
  struct elem **elem = &dict->head;

  while (*elem)
    if (strcmp((*elem)->key, key) == 0) return (*elem)->val;
    else elem = &(*elem)->next;

  return NULL;

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
