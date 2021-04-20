// 
// -----------------------------------------------------------------------------
// dict.h
// -----------------------------------------------------------------------------
//
// Dictionary ADT
//
// Tyler Wayne © 2021
//

#ifndef DICT_T_INCLUDED
#define DICT_T_INCLUDED

#define D Dict_T
typedef struct D *D;

D dict_new();
void dict_set(D, char *key, char *val);
char *dict_get(D, char *key);

#endif // DICT_T_INCLUDED
