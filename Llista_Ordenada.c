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
