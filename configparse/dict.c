//
// -----------------------------------------------------------------------------
// dict.c
// -----------------------------------------------------------------------------
//
// Tyler Wayne © 2021
//

#include <stdio.h>  // fprintf
#include <stdlib.h> // calloc, free, EXIT_FAILURE
#include <string.h> // strcmp, strdup
#include "dict.h"

typedef struct elem_t {
  char *key;
  char *val;
  struct elem_t *next;
} *elem_t;

struct Dict_T {
  int len;
  struct elem_t *head;
};

Dict_T dict_new() {

  Dict_T dict;
  dict = calloc(1, sizeof(*dict));
  return dict;

};

void dict_set(Dict_T dict, char *key, char *val) {

  if (!dict) {
    fprintf(stderr, "List is NULL pointer\n");
    exit(EXIT_FAILURE);
  }

  elem_t *elem = &dict->head;

  while (*elem) {
    if (strcmp((*elem)->key, key) == 0) {
      free((*elem)->val);
      (*elem)->val = strdup(val);
      return;
    }
    elem = &(*elem)->next;
  }

  *elem = calloc(1, sizeof(struct elem_t));
  (*elem)->key = strdup(key);
  (*elem)->val = strdup(val);
  dict->len++;

}

char *dict_get(Dict_T dict, char *key) {
  
  elem_t *elem = &dict->head;

  while (*elem)
    if (strcmp((*elem)->key, key) == 0) return (*elem)->val;
    else elem = &(*elem)->next;

  return NULL;

}

