#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdlib.h>
#include <stdio.h>
#include "item.h"

typedef struct node NODE;
typedef struct lista LISTA;
char *readline(FILE *arq_entrada);

LISTA *criar_lista();
int apagar_lista(LISTA **listaa);
int inserir_final_lista(LISTA *listaa, ITEM *iteem);
int inserir_posicao_lista(LISTA *listaa, ITEM *iteem);
int vazio_lista(LISTA *listaa);
int tamanho_lista(LISTA *listaa);
void imprimir_lista(LISTA *listaa);
NODE *fim_lista(LISTA *listaa);
int retirar_item(LISTA *listaa, int codigo);
int inserir_palavra_chave(LISTA *listaa, int codigo, char *palavrachave);
int inserir_relevancia(LISTA *listaa, int codigo, int relevancia);
void inserir_site(LISTA *listaa);


#endif
