#include "Llista_Ordenada.h"

Llista_PDI PDI_crea(){
    Llista_PDI llista;
    llista.ant = llista.pri = NULL;
    return llista;
}

void PDI_avanca(Llista_PDI *llista){
    llista->ant = llista->ant->seg;
}

void PDI_vesInici(Llista_PDI *llista){
   while(  llista->ant->ant != NULL){
   		PDI_retrocedeix(llista);
	}
}

void PDI_escriu(Llista_PDI *llista, int numero){
    Node *aux;
    int trobat;
    trobat = 0;
	if((*llista).pri == NULL){
		aux = (Node *)malloc(sizeof(Node));
		(*aux).Numero = numero;
		(*aux).seg == NULL;
		(*aux).ant = NULL;
		trobat =  -1;
		(*llista).pri = aux;
		(*llista).ant = aux;
	}
	else{
    	PDI_vesInici(llista);
    	while(llista->ant->seg != NULL && !trobat){
        	if(llista->ant->seg->Numero <= numero){
            	trobat = 1;
        	}
        	else{
            	PDI_avanca(llista);
        	}
    	}
	}
    if(trobat == 0){
        aux = (Node *)malloc(sizeof(Node));
        aux->Numero = numero;
        aux->seg = NULL;
        aux->ant = NULL;
        aux->ant = llista->ant;
        llista->ant->seg = aux;
    }
    else{
	  if(trobat == 1){
     	aux = (Node *)malloc(sizeof(Node));
     	aux->Numero = numero;
      	aux->seg = llista->ant->seg;
      	aux->ant = llista->ant;
      	llista->ant->seg->ant = aux;
	  }
    }
}

int PDI_llegeix(Llista_PDI llista){
    Node aux;
    if(llista.ant != NULL){
        aux.Numero = llista.ant->Numero;
    }
    else{
        aux.seg = NULL;
        aux.ant = NULL;
        aux.Numero = 0;
    }
    return aux.Numero;
}

void PDI_retrocedeix(Llista_PDI *llista){
    if (llista->ant->ant != NULL){
		llista->ant = llista->ant->ant;
	}
}

void PDI_destrueix(Llista_PDI *llista){
    Node *aux;
	PDI_vesInici(llista);
    while((*(*llista).ant).seg != NULL){
        aux = (*(*llista).ant).seg;
        free((*llista).ant);
        (*llista).ant = aux;
    }
    free((*llista).ant);
    (*llista).ant = (*llista).pri = NULL;
}
