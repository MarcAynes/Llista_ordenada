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
        llista.ant->seg = NULL;
        llista.ant->X = -1;
        llista.ant->Y = -1;
    }
    return llista;
}

void PDI_avanca(Llista_PDI *llista){
    llista->ant = llista->ant->seg;
}

void PDI_vesInici(Llista_PDI *llista){
    (*llista).ant = (*llista).pri;
}
