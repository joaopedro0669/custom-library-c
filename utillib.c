#include <stdio.h>
#include "utillib.h"

void desentgl(int altura, char caractere, int largura, Fortrian tipo, Tipodes tipo2){
    int altFazendo = 1;
    while(altFazendo <= altura){
        for(int i = 0; i < altura - altFazendo && tipo == ISOS; i++)
            for(int j = 0; j < largura; j++)
                printf(" ");
        for(int i = 0; i < altura - altFazendo && tipo == RETDIR; i++)
            for(int j = 0; j < largura; j++)
                printf("  ");
        for(int i = 0; i < altFazendo * (2 * largura) - (1 + 2 * (largura - 1)); i++){
            if(tipo2 == PRE)
                printf("%c", caractere);
            else if(tipo2 == ESP){
                i % 2 == 0 ? printf("%c", caractere) : printf(" ");
            }
        }
        printf("\n");
        altFazendo++;
    }
}

void desenlsg(int altura, char caractere, int largura, Tipodes tipo){
    int altFazendo = 1;
    int metadeAltura;
    if(altura % 2 == 0)
        metadeAltura = altura / 2;
    else
        metadeAltura = altura / 2 + 1;
    int alturaRestante = altura - metadeAltura;
    while(altFazendo <= metadeAltura){
        for(int i = 0; i < metadeAltura - altFazendo; i++)
            for(int j = 0; j < largura; j++)
                printf(" ");
        for(int i = 0; i < altFazendo * (2 * largura) - (1 + 2 * (largura - 1)); i++){
            if(tipo == PRE)
                printf("%c", caractere);
            else if(tipo == ESP){
                i % 2 == 0 ? printf("%c", caractere) : printf(" ");
            }
        }
        printf("\n");
        altFazendo++;
    }

    while(alturaRestante > 0){

        for(int i = 0; i < metadeAltura - alturaRestante; i++)
            for(int j = 0; j < largura; j++)
                printf(" ");
        for(int i = 0; i < alturaRestante * (2 * largura) - (1 + 2 * (largura - 1)); i++){
            if(tipo == PRE)
                printf("%c", caractere);
            else if(tipo == ESP){
                i % 2 == 0 ? printf("%c", caractere) : printf(" ");
            }
        }
        printf("\n");
        alturaRestante--;
    }
}

void desenqdd(int lado, char caractere, Tipodes tipo){
    int altFazendo = 1;
    while(altFazendo <= lado){
        for(int i = 0; i < lado && tipo == PRE; i++)
            printf("%c%c", caractere, caractere);
            for(int i = 0; i < lado && tipo == ESP; i++)
            printf("%c ", caractere);
        printf("\n");
        altFazendo++;
    }
}

void desenrtg(int altura, char caractere, int largura, Tipodes tipo){
    int altFazendo = 1;
    while(altFazendo <= altura){
        for(int i = 0; i < largura && tipo == PRE; i++)
            printf("%c%c", caractere, caractere);
            for(int i = 0; i < largura && tipo == ESP; i++)
            printf("%c ", caractere);
        printf("\n");
        altFazendo++;
    }
}
