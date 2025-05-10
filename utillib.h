#ifndef UTILLIB_H_INCLUDED
#define UTILLIB_H_INCLUDED

typedef enum {
    ISOS,
    RETDIR,
    RETESQ
} Fortrian;

typedef enum {
    PRE,
    ESP
} Tipodes;

void desentgl(int altura, char caractere, int largura, Fortrian tipo, Tipodes tipo2);

void desenlsg(int altura, char caractere, int largura, Tipodes tipo);

void desenqdd(int lado, char caractere, Tipodes tipo);

void desenrtg(int altura, char caractere, int largura, Tipodes tipo);

#endif // UTILLIB_H_INCLUDED
