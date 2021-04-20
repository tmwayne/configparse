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

// interface to lexer
extern int yylineno;
void yyerror(char *s);
int yylex();
extern FILE *yyin;

// program data
struct elem {
  char *key;
  char *val;
  struct elem *next;
};

struct dict {
  int len;
  struct elem *head;
};

extern struct dict *configs;

struct dict *dict_new();
void dict_set(struct dict *, char *key, char *val);
char *dict_get(struct dict *, char *key);


#endif // CONFIGPARSE_INCLUDED
