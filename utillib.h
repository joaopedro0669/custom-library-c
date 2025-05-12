#ifndef UTILLIB_H_INCLUDED
#define UTILLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef enum {
    ISOS,
    RETDIR,
    RETESQ
} Fortrian;

typedef enum {
    PRE,
    ESP
} Tipodes;

typedef union {
    char *s;
    char c;
    int i;
} Dado;

typedef enum {
    TP_STRING,
    TP_CHAR,
    TP_INT
} Tp_dado;

//10/05/2025
void desentgl(int altura, char caractere, int largura, Fortrian tipo, Tipodes tipo2);

//10/05/2025
void desenlsg(int altura, char caractere, int largura, Tipodes tipo);

//10/05/2025
void desenqdd(int lado, char caractere, Tipodes tipo);

//10/05/2025
void desenrtg(int altura, char caractere, int largura, Tipodes tipo);

//10/05/2025
void remesp(char *str);

//10/05/2025
void strtolower(char *str);

//10/05/2025
void strtoupper(char *str);

//10/05/2025
char* tobase(Dado dado, Tp_dado tp_dado, int base, int tamanho);

#endif // UTILLIB_H_INCLUDED
