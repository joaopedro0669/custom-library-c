# utillib.h
### `desentgl(int altura, char caractere, int largura, Fortrian tipo, Tipodes tipo2)`
Sem retorno. Desenha um triângulo formado de caracteres.

> Fortrian (enum) tem ISOS, RETDIR e RETESQ como possíveis valores para isósceles, retângulo direito e retângulo esquerdo, respectivamente.
> Tipodes (enum) tem PRE e ESP como possíveis valores para preenchido e espaçado, respectivamente.
---
### `desenlsg(int altura, char caractere, int largura, Tipodes tipo)`
Sem retorno. Desenha um losango formado de caracteres.

> Tipodes (enum) tem PRE e ESP como possíveis valores para preenchido e espaçado, respectivamente.
---
### `desenqdd(int lado, char caractere, Tipodes tipo)`
Sem retorno. Desenha um quadrado formado de caracteres.

> Tipodes (enum) tem PRE e ESP como possíveis valores para preenchido e espaçado, respectivamente.
---
### `desenrtg(int altura, char caractere, int largura, Tipodes tipo)`
Sem retorno. Desenha um retângulo formado de caracteres.

> Tipodes (enum) tem PRE e ESP como possíveis valores para preenchido e espaçado, respectivamente.
---
### `remesp(char *str)`
Sem retorno. Remove todos os espaços de uma string.

---
### `strtolower(char *str)`
Sem retorno. Transforma todos os caracteres de uma string em minúsculos.

---
### `strtoupper(char *str)`
Sem retorno. Transforma todos os caracteres de uma string em maiúsculos.

---
### `tobase(Dado dado, Tp_dado tp_dado, int base, int tamanho)`
Retorno char*. Converte uma int, char ou string para bases numéricas.

> Dado (union) tem i, c e s, que aceita um int, char e string, respectivamente.
> Tp_dado (enum) rem TP_INT, TP_CHAR e TP_STRING como possíveis valores.
> 1 < base <= 200.
---
