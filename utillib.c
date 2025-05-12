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

void remesp(char *str){
    int len = strlen(str);
    int j = 0;
    for(int i = 0; i < len; i++)
        if(str[i] != ' ')
            str[j++] = str[i];
    str[j] = '\0';
}

void strtolower(char *str){
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        str[i] = tolower(str[i]);
}

void strtoupper(char *str){
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        str[i] = toupper(str[i]);
}

char* tobase(Dado dado, Tp_dado tp_dado, int base, int tamanho){
    if(base <= 1 || base > 200)
        return NULL;
    else if(tp_dado == TP_INT || tp_dado == TP_CHAR){
        int num = (tp_dado == TP_INT ? dado.i : dado.c);

        if(tamanho <= 0){
            char montagem[100];
            if(num == 0)
                montagem[0] = '0';
            for(int i = 0; num != 0; i++){
                int resto = num % base;
                num /= base;
                montagem[i] = ((resto - 10) < 0 ? resto + '0' : (resto - 10) + 'A');
                if(num == 0)
                    montagem[i + 1] = '\0';
            }

            int tam = strlen(montagem);
            char *resultado = malloc((tam + 1) * sizeof(char));

            for (int i = tam - 1, j = 0; i >= 0; i--, j++){
                resultado[j] = montagem[i];
            }
            resultado[tam] = '\0';
            return resultado;
        }
        else{
            char montagem[tamanho + 1];
            for(int i = 0; i < tamanho; i++){
                if(num != 0){
                    int resto = num % base;
                    num /= base;
                    montagem[i] = ((resto - 10) < 0 ? resto + '0' : (resto - 10) + 'A');
                }
                else
                    montagem[i] = '0';
            }
            montagem[tamanho] = '\0';

            char *resultado = malloc((tamanho + 1) * sizeof(char));

            for (int i = tamanho - 1, j = 0; i >= 0; i--, j++){
                resultado[j] = montagem[i];
            }
            resultado[tamanho] = '\0';
            return resultado;
        }
    }
    else if(tp_dado == TP_STRING){
        if ((tamanho <= 0 && (base == 2 || base == 16)) || tamanho > 0){

            if (tamanho <= 0 && base == 2)
                tamanho = 8;
            else if (tamanho <= 0 && base == 16)
                tamanho = 2;

            int tamtotal = (tamanho + 1) * (strlen(dado.s));

            char montagem[tamanho + 1];
            char *resultado = malloc(tamtotal * sizeof(char));

            int len = strlen(dado.s);
            int j = 0;
            for(int letra = 0; letra < len; letra++){
                int num = dado.s[letra];

                for(int i = 0; i < tamanho; i++){
                    if(num != 0){
                        int resto = num % base;
                        num /= base;
                        montagem[i] = ((resto - 10) < 0 ? resto + '0' : (resto - 10) + 'A');
                    }
                    else
                        montagem[i] = '0';
                }
                montagem[tamanho] = '\0';


                for (int i = tamanho - 1; i >= 0; i--, j++){
                    resultado[j] = montagem[i];
                }
                if((letra + 1) < len)
                    resultado[j++] = ' ';
                else{
                    resultado[j] = '\0';
                    return resultado;
                }
            }
        }
        else if (tamanho <= 0){
            int tamtotal = 11 * (strlen(dado.s));

            char montagem[tamtotal];
            char *resultado = malloc(tamtotal * sizeof(char));

            int len = strlen(dado.s);
            int j = 0;
            for(int letra = 0; letra < len; letra++){
                int num = dado.s[letra];

                for(int i = 0; num != 0; i++){
                    int resto = num % base;
                    num /= base;
                    montagem[i] = ((resto - 10) < 0 ? resto + '0' : (resto - 10) + 'A');
                    if(num == 0)
                        montagem[i + 1] = '\0';
                }

                int tam = strlen(montagem);
                for (int i = tam - 1; i >= 0; i--, j++){
                    resultado[j] = montagem[i];
                }
                if((letra + 1) < len)
                    resultado[j++] = ' ';
                else{
                    resultado[j] = '\0';
                    return resultado;
                }
            }
        }
    }
    else{
        return NULL;
    }
}
