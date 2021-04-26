/*
 * -----------------------------------------------------------------------------
 * configparse.l
 * -----------------------------------------------------------------------------
 *
 * Lexer for configparse
 *
 * Tyler Wayne © 2021
 */

%option noyywrap nodefault yylineno

%{

#include <string.h>
#include "configparse.h"
#include "parser.h"

char *duplicate_segment(const char *, int);

%}

%%

"="                     { return yytext[0]; }
[0-9]+                  { yylval.s = strdup(yytext); return NUMBER; }
[a-zA-Z][_0-9a-zA-Z]*   { yylval.s = strdup(yytext); return NAME; }
\"(\\.|[^\\\"])*\"      { yylval.s = duplicate_segment(yytext+1, yyleng-2);
                          return STRING; }

\n                      { return EOL; }
"#".*                   /* ignore comments */
[ \t]                   /* ignore whitespace */
.                       { yyerror("Mystery character"); }

%%

char *duplicate_segment(const char *token, int len) {
  char *dup = malloc(len + 1);
  // TODO: handle memory allocation error
  // if (!dup) {} 
  memcpy(dup, token, len);
  dup[len] = 0;
  return dup;
}
