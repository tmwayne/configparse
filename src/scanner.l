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
%}

%%

"="           { return yytext[0]; }
[0-9a-zA-Z]+  { yylval.s = strdup(yytext); return STRING; }

\n            { return EOL; }
"//".*        /* ignore comments */
[ \t]         /* ignore whitespace */
.             { yyerror("Mystery character"); }

%%
