#include "Llista_PDI.h"

Llista_PDI PDI_crea(){
    Llista_PDI llista;
    llista.ant = llista.pri = NULL;
    llista.pri = (Node*)malloc(sizeof(Node));
    llista.ant = llista.pri;
    if(llista.pri == NULL){
        printf("\n\aError en la inisialitzacio del programa\n");
    }
    else{
        llista.ant->seg = llista.ant->ant = NULL;
        llista.ant->Numero = 0;
    }
    return llista;
}

void PDI_avanca(Llista_PDI *llista){
    llista->ant = llista->ant->seg;
}

void PDI_vesInici(Llista_PDI *llista){
    (*llista).ant = (*llista).pri;
}

void PDI_escriu(Llista_PDI *llista, int numero){
    Node *aux;
    int trobat;
    trobat = 0;
    PDI_vesInici(llista);
    while(llista->ant->seg != NULL && !trobat){
        if(llista->ant->seg->Numero <= numero){
            trobat = 1;
        }
        else{
            PDI_avanca(llista);
        }
    }

    if(!trobat){
        aux = (Node *)malloc(sizeof(Node));
        aux->Numero = numero;
        aux->seg = NULL;
        aux->ant = NULL;
        aux->ant = llista->ant;
        llista->ant->seg = aux;
    }
    else{
      aux = (Node *)malloc(sizeof(Node));
      aux->Numero = numero;
      aux->seg = llista->ant->seg;
      aux->ant = llista->ant;
      llista->ant->seg->ant = aux;
      
    }
}
