#ifndef _LLISTA_PDI_
#define _LLISTA_PDI_

#include<stdio.h>

typedef struct N{
    int Numero;
    struct N *seg;
    struct N *ant;
}Node;

typedef struct{
    Node *pri;
    Node *ant;
}Llista_PDI;

Llista_PDI PDI_crea();

void PDI_escriu(Llista_PDI *llista, int Numero);

void PDI_avanca(Llista_PDI *llista);

void PDI_retrocedeix(Llista_PDI *llista);

Node PDI_llegeix(Llista_PDI llista);

void PDI_destrueix(Llista_PDI *llista);

void PDI_vesInici(Llista_PDI *llista);

#endif
